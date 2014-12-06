
#include "main.h"
#include "tinyusbboard.h"
#include "hidcore.h"
#include "asciimap.h"
#include "apipage.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/wdt.h>
#include <avr/pgmspace.h>

#include "usbdrv.h"
#include "oddebug.h"
#include <util/delay.h>

#include <stdint.h>
#include <stdbool.h>
#include <string.h>


/*      	   basically wait timing 	        */
#define COUNTDOWNINIT 32


/*         platform specific time handling code         */
typedef uint16_t mytime_t;
static volatile mytime_t jiffies = 0; /* configure 4ms for each tick */

ISR(TIMER0_OVF_vect, ISR_NOBLOCK) {
  jiffies++;
}

int16_t mydifftime(mytime_t time1, mytime_t time0) {
  int16_t result = time1;
  result -= (int16_t)time0;
  return result;
}

mytime_t mytime(mytime_t *timer) {
  mytime_t result;
  do {
    result = jiffies;
  } while (result != jiffies);
  
  if (timer) (*timer)=result;
  return result;
}

void init_timer(void) {
#if (F_CPU == 16000000)
  TCNT0 = 0;
#	if !(defined (__AVR_ATmega8__) || defined (__AVR_ATmega8A__) || defined (__AVR_ATmega16__) || defined (__AVR_ATmega32__))
      TIMSK0	|= _BV(TOIE0);
      TCCR0B	 = 1*_BV(CS02) | 0*_BV(CS01) | 0*_BV(CS00); // prescaler 256 - so timer0 overflows about every 4ms
#	else
      TIMSK	|= _BV(TOIE0);
      TCCR0	 = 1*_BV(CS02) | 0*_BV(CS01) | 0*_BV(CS00); // prescaler 256 - so timer0 overflows about every 4ms
#	endif
#else
#	error unknown frequency - timer calibration not implemented for this clock
#endif
      sei();
}

/* **END** platform specific time handling code **END** */



/*         USB HOST transmission hook - count TX        */
static uint8_t usbRXcnt = 0;
void usbHookRX(void) {
  if (usbRXcnt < 0xff) usbRXcnt++;
}
/* **END** USB HOST transmission hook, count TX **END** */




static  uint8_t ledloop, ledstate=0;
void reset_rotate(void) {
  ledloop=COUNTDOWNINIT+1;
  ledstate=0;
  SET_HIGH(LED_B);
  SET_HIGH(LED_PWM);
  SET_HIGH(LED_LEFT);
  SET_HIGH(LED_RIGHT);
}
void toggle_all(void) {
  TOGGLE(LED_B);
  TOGGLE(LED_PWM);
  TOGGLE(LED_LEFT);
  TOGGLE(LED_RIGHT);
}

static uchar last_LED_state; 
void EVENT_CHANGE_LED_state (void) {
  if (last_LED_state != current_LED_state) {
    /* when the keyboard LEDs change, the countdown should restart */
    reset_rotate();
    last_LED_state=current_LED_state;
  }  
}

uint8_t rotate_led(const uint8_t state) {
  if (state==0) {
    SET_LOW(LED_LEFT);
    SET_HIGH(LED_B);
  } else if (state==1) {
    SET_LOW(LED_B);
    SET_HIGH(LED_PWM);   
  } else if (state==2) {
    SET_LOW(LED_PWM);   
    SET_HIGH(LED_RIGHT);   
  } else if (state==3) {
    SET_LOW(LED_RIGHT);   
    SET_HIGH(LED_LEFT);   
    return 0;
  } else {
    return 0;
  }
  return state+1;
}

uint8_t rotate_led_inverted(const uint8_t state) {
  if (state==0) {
    SET_HIGH(LED_LEFT);
    SET_LOW(LED_B);
  } else if (state==1) {
    SET_HIGH(LED_B);
    SET_LOW(LED_PWM);   
  } else if (state==2) {
    SET_HIGH(LED_PWM);   
    SET_LOW(LED_RIGHT);   
  } else if (state==3) {
    SET_HIGH(LED_RIGHT);   
    SET_LOW(LED_LEFT);   
    return 0;
  } else {
    return 0;
  }
  return state+1;
}


static mytime_t lastHIDevent;
void pollHID_timed(void) {
  mytime_t current;
  int16_t difference = mydifftime(mytime(&current), lastHIDevent);
  if (difference > 0) {
    uint8_t ticks=difference; 
    if (difference > 0xff) ticks=0xff;
    lastHIDevent=current;
    hidPoll(&ticks);
  } else {
    uint8_t nullvalue = 0;
    hidPoll(&nullvalue);
  }
}

#include "message.h"
void dotyping(void) {
  uint_farptr_t msg = selftest_farptr_of(message_to_type[0]);
  size_t messagelen = ((size_t)2)*strlen_PF(msg);
  size_t messagepos;
  mytime_t lastPress, current;
  bool keypressed = false;

  while (IS_PRESSED(BUTTON_PROG)) {
    pollHID_timed();
  }

  lastPress=mytime(&current);
  for (messagepos=0;messagepos<messagelen;) {
    pollHID_timed();
    if (mydifftime(mytime(&current), lastPress) >= TYPEDELAY_FOURMS) {
      if (!keyboard_report_dirty) {
	rotate_led_inverted((messagepos/(COUNTDOWNINIT/4))%4);
	keyboard_report_clear(&current_keyboard_report);
	if (messagepos & 0x1) {
	  keyboard_report_dirty|=0x02;
	  keypressed=false;
	} else {
	  if (asciitokeyreport(MYPGM_READ_BYTE(msg+(messagepos>>1)), &current_keyboard_report)) {
	    keyboard_report_dirty|=0x02;
	    keypressed=true;
	  }
	}
	lastPress=current;
	messagepos++;
      }

      if (IS_PRESSED(BUTTON_PROG)) {
	while (IS_PRESSED(BUTTON_PROG)) {
	  pollHID_timed();
	}
	if (keypressed) {
	  while (keyboard_report_dirty) {
	    pollHID_timed();
	  }
	  keyboard_report_clear(&current_keyboard_report);
	  keyboard_report_dirty|=0x02;
	}
	break;
      }

    }
  }
}

int main(void) {
  uint8_t i, rotcounter=0;
  mytime_t last;

#ifdef MCUCSR
  i=MCUCSR;
  MCUCSR=0;
#else
  i=MCUSR;
  MCUSR=0;
#endif
  wdt_disable();

  hidInit();
  last_LED_state=current_LED_state;

  usbDeviceDisconnect();
  init_timer();

  CFG_PULLUP(BUTTON_PROG);

  CFG_OUTPUT(LED_B);
  CFG_OUTPUT(LED_PWM);
  CFG_OUTPUT(LED_LEFT);
  CFG_OUTPUT(LED_RIGHT);

  last=mytime(NULL);
  lastHIDevent=last;

  if ((i & _BV(WDRF))==0) {
    /*  connect delay */
    for (i=0;i<16;) {
      mytime_t current;
      if (mydifftime(mytime(&current), last) >= 15) {
	rotcounter=rotate_led(rotcounter);
	last=current;
	i++;
      }
    }

    usbDeviceConnect();
    usbInit();

    /* wait for some host connecting */
    while (usbRXcnt < 7) {
      mytime_t current;
      if (mydifftime(mytime(&current), last) >= 15) {
	rotcounter=rotate_led(rotcounter);
	last=current;
      }
      pollHID_timed();
    }

    /*  acknowledge USB and start countdown */
    reset_rotate();
    for (i=0;i<((COUNTDOWNINIT>>2)&0xfe);) {
      mytime_t current;
      if (mydifftime(mytime(&current), last) >= (10+(i*4))) {
	toggle_all();
	last=current;
	i++;
      }
      pollHID_timed();
      if (IS_PRESSED(BUTTON_PROG)) {
	i=COUNTDOWNINIT+1;
	reset_rotate();
	dotyping();
	reset_rotate();
      }
    }

    /* nice countdown, followed by reboot */
    reset_rotate();
    for (ledstate=0;ledstate<4;ledstate++) {
      for (ledloop=COUNTDOWNINIT+1;ledloop>0;) {
	mytime_t current;
	if (mydifftime(mytime(&current), last) >= (3+(ledloop*2))) {
	  if (ledstate==0) TOGGLE(LED_PWM);
	  else if (ledstate==1) TOGGLE(LED_B);
	  else if (ledstate==2) TOGGLE(LED_LEFT);
	  else if (ledstate==3) TOGGLE(LED_RIGHT);
	  last=current;
	  ledloop--;
	}
	pollHID_timed();
	if (IS_PRESSED(BUTTON_PROG)) {
	  reset_rotate();
	  dotyping();
	  reset_rotate();
	}
      }
    }

    /* disconnect the USB and start the bootloader */
    usbDeviceDisconnect();
    SET_HIGH(LED_RIGHT);
    bootloader_startup(); /* on success it never returns */
  } /* end - no watchdog reset has happend before */


  /* 
   * this should never be reached by the IP 
   * probably the bootloader doesn't support the firmware entry point or
   * some unknown watchdog timeout happend (even when the watchdog was disabled)...
   * anyhow: Show watchdog persistent error if it happens 
   */
  wdt_reset(); /* in case sth. went wrong in bootloader_startup and watchdog staid on */
  reset_rotate();
  SET_LOW(LED_PWM);
  SET_LOW(LED_LEFT);
  while (1) {
    mytime_t current;
    wdt_reset();
    if (mydifftime(mytime(&current), last) >= 125) {
      toggle_all();
      last=current;
    }
  }
  
  return 0;
}

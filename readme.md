tinyUSBboard default firmware with/for board+usb selftest
=========================================================

WHEN PROGRAMMING THE DEFAULT FIRMWARE VIA EXTERNAL PROGRAMMER,
PLEASE ALWAYS CONFIGURE CORRECT FUSE-SETTING, TOO !
Also do NOT lock ANY bits (use default lockbits=0x3f) !

In order to test the boards solder joints and connections, this
firmware first rotates all red LEDs. (Check for shorts/cold joints)
This rotation will stop after about 1sec, when a proper host
(conntected to the USB) is found.
This step won't require any drivers, since USB-HID is used.
However, if no USB host is found, or the USB host doesn't support
simple boot HID protocol: Cycling the leds never will end.

If an USB connection is detected, all four red LEDs blink for about
one second and an animated countdown for about 20sec starts.
(The leds stop flashing one after another until no one is left.)

An USB HID keyboard is emulated during this period:

If the PROG button is pressed (or PD6 is grounded) during the
countdown, the countdown is reset.
When PROG (PD6 from GND) is released then, a greetings message starts
typing while the leds are cycling again. (This time inverted.)

If the keyboard LED state (NUM-, CAPS- and SCROLL- lock) is changing,
the countdown is reset, too. However a message won't be typed.

At the end of the countdown, the bootloader is invoked to enter PROGMODE: 
This default firmware then has stopped execution and the board is ready
to receive new firmware.

In cases an error occurs, two diagonal LEDs are flashing alternating,
all other functions stop and the USB becomes disconnected.


by Stephan Baerwolf (matrixstorm@gmx.de), Schwansee 2014
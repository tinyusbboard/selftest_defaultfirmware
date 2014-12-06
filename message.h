
#ifndef __MESSAGE_H_329c61819ae64005817bbe429450c873
#define __MESSAGE_H_329c61819ae64005817bbe429450c873 1

#include "asciimap.h"

#define TYPEDELAY_FOURMS	5

#ifndef MESSAGESECTION
#	define MESSAGESECTION	PROGMEM
#endif

static const uint8_t message_to_type[] MESSAGESECTION = 
#ifndef __MESSAGE_TO_TYPE__
#ifndef TINYUSBBOARD_REV2
#	if defined (__AVR_ATmega8__) || defined (__AVR_ATmega8A__) || defined (__AVR_ATmega8HVA__)
#		if (ASCIIMAP_LAYOUT==ASCIIMAP_LAYOUT_DE)
		  "\n"
		  "tinyUSBboard Selbsttest - die USB Schnittstelle funktioniert\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "Nach Ablauf des Countdowns startet der Bootloader und das Board kann programmiert werden.\n"
		  "\n"
		  "\n"
		  "Bei Anmerkungen, Fragen oder Problemen wenden Sie sich bitte an Stephan Baerwolf\n"
		  "stephan@matrixstorm.com, matrixstorm@gmx.de, stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID\t: 0xFB9B12DB\n"
		  "Fingerprint\t: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		else
		  "\n"
		  "tinyUSBboard - the USB interface has passed self testing\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "After the countdown the bootloader starts up and the board can be programmed.\n"
		  "\n"
		  "\n"
		  "In case you encouter problems, have any questions or in case\n"
		  "you just have remarks, please do not hesitate to contact:\n"
		  "Stephan Baerwolf  - stephan@matrixstorm.com\n"
		  "matrixstorm@gmx.de, or stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID\t: 0xFB9B12DB\n"
		  "Fingerprint\t: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		endif
#	elif defined (__AVR_ATmega328P__)
#		if (ASCIIMAP_LAYOUT==ASCIIMAP_LAYOUT_DE)
		  "\n"
		  "tinyUSBboard mit ATmega328p, Selbsttest - die USB Schnittstelle funktioniert\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "Nach Ablauf des Countdowns startet der Bootloader und das Board kann programmiert werden.\n"
		  "\n"
		  "\n"
		  "Bitte beachten Sie die INKOMPATIBILITAET der normalen ATmega8 tinyUSBboard\n"
		  "firmwares. Alle Beispiele muessen fuer ATmega328p, 16MHz uebersetzt sein.\n"
		  "\n"
		  "\n"
		  "\n"
		  "Bei Anmerkungen, Fragen oder Problemen wenden Sie sich bitte an Stephan Baerwolf\n"
		  "stephan@matrixstorm.com, matrixstorm@gmx.de, stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID	: 0xFB9B12DB\n"
		  "Fingerprint	: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		else
		  "\n"
		  "tinyUSBboard with ATmega328p - the USB interface has passed self testing\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "After the countdown the bootloader starts up and the board can be programmed.\n"
		  "\n"
		  "\n"
		  "Please care attention of the INCOMPATIBILITY of regular ATmega8 tinyUSBboard\n"
		  "firmwares. All examples need to be compiled for ATmega328p, 16MHz.\n"
		  "\n"
		  "\n"
		  "\n"
		  "In case you encouter problems, have any questions or in case\n"
		  "you just have remarks, please do not hesitate to contact:\n"
		  "Stephan Baerwolf  - stephan@matrixstorm.com\n"
		  "matrixstorm@gmx.de, or stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID	: 0xFB9B12DB\n"
		  "Fingerprint	: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		endif

/* secondary supported ATmegas */
#	elif defined (__AVR_ATmega88__) || defined (__AVR_ATmega88P__)
#		if (ASCIIMAP_LAYOUT==ASCIIMAP_LAYOUT_DE)
		  "\n"
		  "tinyUSBboard mit ATmega88, Selbsttest - die USB Schnittstelle funktioniert\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "Nach Ablauf des Countdowns startet der Bootloader und das Board kann programmiert werden.\n"
		  "\n"
		  "\n"
		  "Bitte beachten Sie die INKOMPATIBILITAET der normalen ATmega8 tinyUSBboard\n"
		  "firmwares. Alle Beispiele muessen fuer ATmega88, 16MHz uebersetzt sein.\n"
		  "\n"
		  "\n"
		  "\n"
		  "Bei Anmerkungen, Fragen oder Problemen wenden Sie sich bitte an Stephan Baerwolf\n"
		  "stephan@matrixstorm.com, matrixstorm@gmx.de, stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID	: 0xFB9B12DB\n"
		  "Fingerprint	: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		else
		  "\n"
		  "tinyUSBboard with ATmega88 - the USB interface has passed self testing\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "After the countdown the bootloader starts up and the board can be programmed.\n"
		  "\n"
		  "\n"
		  "Please care attention of the INCOMPATIBILITY of regular ATmega8 tinyUSBboard\n"
		  "firmwares. All examples need to be recompiled for ATmega88, 16MHz.\n"
		  "\n"
		  "\n"
		  "\n"
		  "In case you encouter problems, have any questions or in case\n"
		  "you just have remarks, please do not hesitate to contact:\n"
		  "Stephan Baerwolf  - stephan@matrixstorm.com\n"
		  "matrixstorm@gmx.de, or stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID	: 0xFB9B12DB\n"
		  "Fingerprint	: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		endif
#	elif defined (__AVR_ATmega168__) || defined (__AVR_ATmega168P__)
#		if (ASCIIMAP_LAYOUT==ASCIIMAP_LAYOUT_DE)
		  "\n"
		  "tinyUSBboard mit ATmega168, Selbsttest - die USB Schnittstelle funktioniert\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "Nach Ablauf des Countdowns startet der Bootloader und das Board kann programmiert werden.\n"
		  "\n"
		  "\n"
		  "Bitte beachten Sie die INKOMPATIBILITAET der normalen ATmega8 tinyUSBboard\n"
		  "firmwares. Alle Beispiele muessen fuer ATmega168, 16MHz uebersetzt sein.\n"
		  "\n"
		  "\n"
		  "\n"
		  "Bei Anmerkungen, Fragen oder Problemen wenden Sie sich bitte an Stephan Baerwolf\n"
		  "stephan@matrixstorm.com, matrixstorm@gmx.de, stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID	: 0xFB9B12DB\n"
		  "Fingerprint	: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		else
		  "\n"
		  "tinyUSBboard with ATmega168 - the USB interface has passed self testing\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "After the countdown the bootloader starts up and the board can be programmed.\n"
		  "\n"
		  "\n"
		  "Please care attention of the INCOMPATIBILITY of regular ATmega8 tinyUSBboard\n"
		  "firmwares. All examples need to be recompiled for ATmega168, 16MHz.\n"
		  "\n"
		  "\n"
		  "\n"
		  "In case you encouter problems, have any questions or in case\n"
		  "you just have remarks, please do not hesitate to contact:\n"
		  "Stephan Baerwolf  - stephan@matrixstorm.com\n"
		  "matrixstorm@gmx.de, or stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID	: 0xFB9B12DB\n"
		  "Fingerprint	: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		endif
#	elif defined (__AVR_ATmega328__)
#		if (ASCIIMAP_LAYOUT==ASCIIMAP_LAYOUT_DE)
		  "\n"
		  "tinyUSBboard mit ATmega328 (ohne p), Selbsttest - die USB Schnittstelle funktioniert\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "Nach Ablauf des Countdowns startet der Bootloader und das Board kann programmiert werden.\n"
		  "\n"
		  "\n"
		  "Bitte beachten Sie die INKOMPATIBILITAET der normalen ATmega8 tinyUSBboard\n"
		  "firmwares. Alle Beispiele muessen fuer ATmega328, 16MHz uebersetzt sein.\n"
		  "\n"
		  "\n"
		  "\n"
		  "Bei Anmerkungen, Fragen oder Problemen wenden Sie sich bitte an Stephan Baerwolf\n"
		  "stephan@matrixstorm.com, matrixstorm@gmx.de, stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID	: 0xFB9B12DB\n"
		  "Fingerprint	: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		else
		  "\n"
		  "tinyUSBboard with ATmega328 (without p) - the USB interface has passed self testing\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "After the countdown the bootloader starts up and the board can be programmed.\n"
		  "\n"
		  "\n"
		  "Please care attention of the INCOMPATIBILITY of regular ATmega8 tinyUSBboard\n"
		  "firmwares. All examples need to be recompiled for ATmega328, 16MHz.\n"
		  "\n"
		  "\n"
		  "\n"
		  "In case you encouter problems, have any questions or in case\n"
		  "you just have remarks, please do not hesitate to contact:\n"
		  "Stephan Baerwolf  - stephan@matrixstorm.com\n"
		  "matrixstorm@gmx.de, or stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID	: 0xFB9B12DB\n"
		  "Fingerprint	: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		endif
#	else
/* unknown MCU */
#		error unkown ATmega at tinyUSBboard rev3 or newer
#	endif

#else /* Rev2 or older */
#	if defined (__AVR_ATmega8__) || defined (__AVR_ATmega8A__) || defined (__AVR_ATmega8HVA__)
#		if (ASCIIMAP_LAYOUT==ASCIIMAP_LAYOUT_DE)
		  "\n"
		  "tinyUSBboard Rev.2 oder aelter, Selbsttest - die USB Schnittstelle funktioniert\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "Nach Ablauf des Countdowns startet der Bootloader und das Board kann programmiert werden.\n"
		  "\n"
		  "\n"
		  "Bei Anmerkungen, Fragen oder Problemen wenden Sie sich bitte an Stephan Baerwolf\n"
		  "stephan@matrixstorm.com, matrixstorm@gmx.de, stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID\t: 0xFB9B12DB\n"
		  "Fingerprint\t: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		else
		  "\n"
		  "tinyUSBboard Rev.2 or older - the USB interface has passed self testing\n"
		  "http://matrixstorm.com/avr/tinyusbboard/\n"
		  "\n"
		  "After the countdown the bootloader starts up and the board can be programmed.\n"
		  "\n"
		  "\n"
		  "In case you encouter problems, have any questions or in case\n"
		  "you just have remarks, please do not hesitate to contact:\n"
		  "Stephan Baerwolf  - stephan@matrixstorm.com\n"
		  "matrixstorm@gmx.de, or stephan.baerwolf@tu-ilmenau.de\n"
		  "\n"
		  "PGP-KeyID\t: 0xFB9B12DB\n"
		  "Fingerprint\t: 2252 B41E 12DF 41AD 476F 7F36 084A 0911 FB9B 12DB\n"
#		endif
#	else
#		error tinyUSBboard rev2 only is implemented for ATmega8, yet
#	endif
#endif
"";
#else
__MESSAGE_TO_TYPE__;
#endif

#endif

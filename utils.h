/*

Copyright (c) 2016, Embedded Adventures, www.embeddedadventures.com
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

- Neither the name of Embedded Adventures nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
THE POSSIBILITY OF SUCH DAMAGE.

Contact us at admin [at] embeddedadventures.com
*/

#ifndef __utils_h
#define __utils_h

#include "Arduino.h"

#ifndef	uns8
	#define	uns8	uint8_t
#endif
#ifndef	uns16
	#define	uns16	uint16_t
#endif
#ifndef	uns32
	#define	uns32	uint32_t
#endif
#ifndef	int8
	#define	int8	int8_t
#endif

#ifdef	DEBUG_FONTS
	#define DEBUG_FONT(x)	serial_print_str(x); serial_print_str(" ");
	#define	DEBUG_FONTX(x)	serial_print_int_hex(x, HEX);
	#define	DEBUG_FONTLN(x)	serial_print_nl(x);
#else
	#define DEBUG_FONT(x)	
	#define	DEBUG_FONTX(x)	
	#define	DEBUG_FONTLN(x)	
#endif
	
#if (ARDUINO_SAMD_VARIANT_COMPLIANCE)
	//#error		"SAMD21 works"
	#define 	serial_print_str(x) 	SerialUSB.print(x)
	#define		serial_print_int(x)		SerialUSB.print(x, DEC)
	#define		serial_print_int_hex(x)	SerialUSB.print(x, HEX)
	#define		serial_print_nl(x)		SerialUSB.println(x)
	#define		serial_print_var(x, y)	SerialUSB.print(x); SerialUSB.print(y)
	#define		serial_putc(x)			SerialUSB.print(x)
#else
	//#error		"SAMD21 not working"
	#define 	serial_print_str(x) 	Serial.print(x)
	#define		serial_print_int(x)		Serial.print(x, DEC)
	#define		serial_print_int_hex(x)	Serial.print(x, HEX)
	#define		serial_print_nl(x)		Serial.println(x)
	#define		serial_print_var(x, y)	Serial.print(x); Serial.print(y)
	#define		serial_putc(x)			Serial.print(x)
#endif

#define clear_bit( x, b )  ((x) &= ~(1 << (b)))
#define set_bit( x, b )   ((x) |= (1 << (b)))
#define test_bit( x, b )  ((x) & (1 << (b)))
#define toggle_bit( x, b )  ((x) ^= (1 << (b)))



#endif

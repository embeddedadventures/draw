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

#ifndef __config_h
#define __config_h

#include "Arduino.h"

#if defined(ARDUINO_ARCH_SAMD)
	#warning "Using a SAMD21 board, more fonts allowed!"
	#define DRAW_FONT_5NARROW
	#define DRAW_FONT_5NORMAL
	#define DRAW_FONT_7NORMAL
	#define DRAW_FONT_8NORMAL
	#define DRAW_FONT_8FIXED
	#define DRAW_FONT_10NARROW
	#define DRAW_FONT_10NORMAL
	#define DRAW_FONT_10DOUBLE
	#define DRAW_FONT_12DOUBLE
	#define DRAW_FONT_10NORMAL
	#define FONT_COUNT 	10
#elif defined(ESP8266) || defined(ESP32)
	#warning "Using an ESP8266 or ESP32, good memory!"
	#define DRAW_FONT_5NARROW
	#define DRAW_FONT_5NORMAL
	#define DRAW_FONT_7NORMAL
	#define DRAW_FONT_8NORMAL
	#define DRAW_FONT_8FIXED
	#define DRAW_FONT_10NARROW
	#define DRAW_FONT_10NORMAL
	#define DRAW_FONT_10DOUBLE
	#define DRAW_FONT_12DOUBLE
	#define DRAW_FONT_10NORMAL
	#define FONT_COUNT 	10
#else
	#warning "Using an Arduino board, only 2 fonts allowed!"
	#define DRAW_FONT_10NORMAL
	#define DRAW_FONT_10DOUBLE
	#define FONT_COUNT 	2
#endif

#define 	EPD200200B
//#define 	SSD1306_OLED6432
//#define 	SSD1306_OLED12864
//#define	PCD8544_EA

#define DRAW_BITS_PER_PIXEL 1
#define	FONTS_IN_FLASH

#ifdef	SSD1306_OLED6432
	#define DRAW_HW_Y_ORIGIN_BOTTOM_LEFT
	#define DRAW_HW_BUFFER_ORIENTATION_VERTICAL
	#define FONT_COUNT 		8
	#define	OLED_HEIGHT		32
	#define	OLED_WIDTH		64
	#define	OLED_OFFSET		32
#endif

#ifdef	SSD1306_OLED12864
	#define DRAW_HW_Y_ORIGIN_BOTTOM_LEFT
	#define DRAW_HW_BUFFER_ORIENTATION_VERTICAL
	#define FONT_COUNT 	8
	#define	OLED_HEIGHT		64
	#define	OLED_WIDTH		128
	#define	OLED_OFFSET		0
#endif

#ifdef	PCD8544_EA
	#define DRAW_HW_Y_ORIGIN_BOTTOM_LEFT
	#define DRAW_HW_BUFFER_ORIENTATION_VERTICAL
	#define FONT_COUNT 	6
#endif

#ifdef	EPD200200B
  #warning "EPD-20020B defined!"
	#define DRAW_HW_Y_ORIGIN_TOP_LEFT
	#define DRAW_HW_BUFFER_ORIENTATION_HORIZONTAL
#endif

#define DEBUG_FONTS


#define DRAW_DEBUG
#define DRAW_DOUBLE_BUFFER

#define DRAW_SCROLL_LENGTH 1000
#define DRAW_SCROLL_SPEED 100
/*
#define DRAW_FONT_5NARROW
#define DRAW_FONT_5NORMAL
#define DRAW_FONT_7NORMAL
#define DRAW_FONT_8NORMAL
#define DRAW_FONT_8FIXED
#define DRAW_FONT_10NARROW
#define DRAW_FONT_10NORMAL
#define DRAW_FONT_10DOUBLE
#define DRAW_FONT_12DOUBLE
//#define DRAW_FONT_16DOUBLE
//#define DRAW_FONT_16TRIPLE
//#define DRAW_FONT_24TRIPLE
//#define DRAW_FONT_28NORMAL
//#define DRAW_FONT_32SEGOE
//#define DRAW_FONT_32TAHOMA
#define DRAW_FONT_BIGNUM
*/
// Define to handle dirty rectangles
//#define DRAW_DIRTY_RECTANGLE


#endif

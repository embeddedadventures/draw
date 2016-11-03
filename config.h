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

#define EPD200200B
//#define SSD1306_EA
//#define	PCD8544_EA

#define DRAW_BITS_PER_PIXEL 1

#ifdef	SSD1306_EA
	#define DRAW_HW_Y_ORIGIN_BOTTOM_LEFT
	#define DRAW_HW_BUFFER_ORIENTATION_VERTICAL
	#define FONT_COUNT 	6
#endif

#ifdef	PCD8544_EA
	#define DRAW_HW_Y_ORIGIN_TOP_LEFT
	#define DRAW_HW_BUFFER_ORIENTATION_VERTICAL
	#define FONT_COUNT 	6
#endif

#ifdef	EPD200200B
	#define DRAW_HW_Y_ORIGIN_TOP_LEFT
	#define DRAW_HW_BUFFER_ORIENTATION_HORIZONTAL
	#define FONT_COUNT 	9
#endif

//#define DEBUG_FONTS

//#define DRAW_HW_Y_ORIGIN TOP_LEFT
//#define DRAW_HW_Y_ORIGIN_BOTTOM_LEFT

//#define DRAW_HW_BUFFER_ORIENTATION_HORIZONTAL
//#define DRAW_HW_BUFFER_ORIENTATION_VERTICAL

#define DRAW_DEBUG
#define DRAW_DOUBLE_BUFFER

#define DRAW_SCROLL_LENGTH 1000
#define DRAW_SCROLL_SPEED 100

//#define FONT_COUNT 6

#define DRAW_FONT_5NARROW
#define DRAW_FONT_5NORMAL
#define DRAW_FONT_7NORMAL
#define DRAW_FONT_8NORMAL
#define DRAW_FONT_8FIXED
//#define DRAW_FONT_10NARROW
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

// Define to handle dirty rectangles
//#define DRAW_DIRTY_RECTANGLE


#endif

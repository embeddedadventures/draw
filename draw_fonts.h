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

#ifndef __draw_fonts_h
#define __draw_fonts_h

#include "config.h"
#include "utils.h"
#include "draw.h"

#ifdef DRAW_FONT_8FIXED
	#include "draw_font_8fixed.h"
#endif


#ifdef DRAW_FONT_8NORMAL
	#include "draw_font_8normal.h"
#endif

#ifdef DRAW_FONT_16TRIPLE
	#include "draw_font_16triple.h"
#endif

#ifdef DRAW_FONT_7NORMAL
	#include "draw_font_7normal.h"
#endif

#ifdef DRAW_FONT_16DOUBLE
	#include "draw_font_16double.h"
#endif

#ifdef DRAW_FONT_12DOUBLE
	#include "draw_font_12double.h"
#endif

#ifdef DRAW_FONT_10NORMAL
	#include "draw_font_10normal.h"
#endif

#ifdef DRAW_FONT_10DOUBLE
	#include "draw_font_10double.h"
#endif

#ifdef DRAW_FONT_5NARROW
	#include "draw_font_5narrow.h"
#endif

#ifdef DRAW_FONT_5NORMAL
	#include "draw_font_5normal.h"
#endif
#ifdef DRAW_FONT_BIGNUM
	#include "draw_font_bignum.h"
#endif
#ifdef DRAW_FONT_32TAHOMA
	#include "draw_font_32tahoma.h"
#endif
#ifdef DRAW_FONT_32SEGOE
  #include "draw_font_32segoe.h"
#endif
#ifdef DRAW_FONT_5X7FIXED
	#include "draw_font_5x7fixed.h"
#endif


void draw_fonts_init(void);
void draw_fonts_print_str(uns8 font_id, draw_x_type x, draw_y_type y, draw_x_type width, uns16 start_pixel, uns8 colour, char *str);
void draw_fonts_print_str(uns8 font_id, draw_x_type x, draw_y_type y, draw_x_type width, uns16 start_pixel, uns8 colour, const char *str);
void draw_fonts_print_str_wiggle(uns8 font_id, draw_x_type x, draw_y_type y, draw_x_type width, uns16 start_pixel, uns8 colour, char *str, int8 wiggle, int8 start_wiggle, uns8 start_wiggle_inc);
void draw_fonts_bignum(draw_x_type x, draw_y_type y, draw_x_type width, draw_x_type start_pixel, uns8 colour, char *str);
void draw_fonts_print_str_vert(uns8 font_id, draw_x_type x, draw_y_type y, draw_y_type width, uns16 start_pixel, uns8 colour, char *str);
void draw_fonts_print_str_c(uns8 font_id, draw_x_type x, draw_y_type y, draw_x_type width, uns16 start_pixel, uns8 colour, char *str);
void draw_fonts_print_str_rj(uns8 font_id, draw_x_type x, draw_y_type y, draw_x_type width, uns16 start_pixel, uns8 colour, char *str);

uns16 draw_fonts_length_str(uns8 font_id, char *str);
draw_y_type draw_fonts_height(uns8 font_id);

//uns8 ICACHE_FLASH_ATTR read_rom_uint8(const uns8* addr);

//uns16 ICACHE_FLASH_ATTR read_rom_uint16(const uns16* addr);


#endif

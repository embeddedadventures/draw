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

/** \file draw.h
    \brief Buffered graphics routines


You will need to pick a hardware buffering mode for the draw routines.

 Draw buffer addressing

4 | U V W X Y
3 | P Q R S T
2 | K L M N O
1 | F G H I J
0 | A B C D E
	---------
	0 1 2 3 4
DRAW_HW_Y_ORIGIN == BOTTOM_LEFT
DRAW_HW_BUFFER_ORIENTATION == HORIZONTAL

0 | A B C D E
1 | F G H I J
2 | K L M N O
3 | P Q R S T
4 | U V W X Y
	---------
	0 1 2 3 4
DRAW_HW_Y_ORIGIN == TOP_LEFT
DRAW_HW_BUFFER_ORIENTATION == HORIZONTAL

0 | E J O T Y
1 | D I N S X
2 | C H M R W
3 | B G L Q V
4 | A F K P U
	---------
	0 1 2 3 4
DRAW_HW_Y_ORIGIN == BOTTOM_LEFT
DRAW_HW_BUFFER_ORIENTATION == VERTICAL


0 | A F K P U
1 | B G L Q V
2 | C H M R W
3 | D I N S X
4 | E J O T Y
	---------
	0 1 2 3 4
DRAW_HW_Y_ORIGIN == TOP_LEFT
DRAW_HW_BUFFER_ORIENTATION == VERTICAL



Put the following in your config.h:
\code
// - - - - - - - - - - - - - - - - - - - - 
// Draw defines
// - - - - - - - - - - - - - - - - - - - - 



#define DRAW_HW_Y_ORIGIN TOP_LEFT
// or BOTTOM_LEFT

#define DRAW_HW_BUFFER_ORIENTATION VERTICAL
// or HORIZONTAL

//Enable debug to see what's happening under the hood
//#define DRAW_DEBUG

// - - - - - - - - - - - - - - - - - - - - 

\endcode
*/


#ifndef __draw_h
#define __draw_h

#include "config.h"
#include "utils.h"

#define HORIZONTAL 0
#define VERTICAL   1

#define TOP_LEFT	0
#define BOTTOM_LEFT	1
 
#define DRAW_PIXELS_PER_BYTE (8 / draw_bits_per_pixel)

#define draw_x_type	uns16
#define draw_y_type	uns16


// One day we will have more colours...
#define draw_colour_type uns8

extern uns8 *draw_buffer;

extern draw_y_type draw_pixels_high;
extern draw_x_type draw_pixels_wide;
extern draw_y_type draw_bottom_pixel_y;
extern draw_y_type draw_top_pixel_y;
extern uns32 draw_total_buffer_size;

extern uns8 draw_pixels_per_byte;
extern uns8 draw_bits_per_pixel;


void draw_setup_io();
uns8 draw_init(draw_x_type width, draw_y_type height, uns8 bits_per_pixel);
void draw_clear_screen();

void draw_set_pixel(draw_x_type x, draw_y_type y, uns8 colour);
uns8 draw_get_pixel(draw_x_type x, draw_y_type y);

void draw_bitmap(draw_x_type x, draw_y_type y, uns8 colour, char *bitmap);

void draw_line(draw_x_type x0, draw_y_type y0, draw_x_type x1, draw_y_type y1, uns8 colour);
void draw_circle(draw_x_type x_centre, draw_y_type y_centre, int r, uns8 colour);
void draw_circle2(draw_x_type x_centre, draw_y_type y_centre, int r, uns8 colour);
void draw_filled_circle(draw_x_type x_centre, draw_y_type y_centre, int r, uns8 colour);
void draw_filled_circle2(draw_x_type x_centre, draw_y_type y_centre, int r, uns8 colour);
void draw_rect(draw_x_type x, draw_y_type y, uns16 width, draw_y_type height, uns8 colour);
void draw_print_buffer();
//void drv_enable_active_when(bit active);
// driver routines

void draw_paint();
void draw_paint_full();
extern void drv_paint();
void drv_paint_partial(draw_x_type x_left, draw_y_type y_top, draw_x_type x_right, draw_y_type y_bottom);
// For backwards compatibility:
#define drv_setup() drv_setup_io()
void drv_setup_io();
void drv_init(draw_x_type width, draw_y_type height);
void drv_refresh();
void drv_print_buffer();
void drv_set_display_brightness(uns8 brightness);
#define draw_set_display_brightness(brightness) drv_set_display_brightness(brightness)
#endif

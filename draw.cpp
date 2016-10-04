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
/** \file draw.c
    \brief Buffered graphics routines

*/



#include "utils.h"
#include "draw.h"
#include "config.h"

draw_y_type draw_pixels_high;
draw_x_type draw_pixels_wide;
uns8 draw_pixels_per_byte;
uns8 draw_bits_per_pixel;
draw_y_type draw_bottom_pixel_y;
draw_y_type draw_top_pixel_y;

uns32 draw_total_buffer_size;

#ifdef DRAW_DIRTY_RECTANGLE
  draw_x_type dirty_x_left;
  draw_x_type dirty_x_right;
  draw_y_type dirty_y_top;
  draw_y_type dirty_y_bottom;
  uns8 dirty_set = 0;
#endif

uns8 *draw_buffer = NULL;

void draw_clear_screen() {

uns32 count;


for (count=0; count != draw_total_buffer_size; count++) {
		draw_buffer[count] = 0;
	}
}



uns8 draw_init(draw_x_type width, draw_y_type height, uns8 bits_per_pixel) {

    draw_pixels_wide = width;
    draw_pixels_high = height;
    draw_pixels_per_byte = 8 / bits_per_pixel;
    draw_bits_per_pixel = bits_per_pixel;
    if (draw_bits_per_pixel <= 8) {
	// was: draw_total_buffer_size = draw_pixels_wide * draw_pixels_high / draw_pixels_per_byte;
	draw_total_buffer_size = draw_pixels_wide * draw_pixels_high * draw_bits_per_pixel / 8;
    } else {
	// does this work for 24bpp?
	draw_total_buffer_size = draw_pixels_wide * draw_pixels_high * draw_bits_per_pixel / 8;
    }
#ifdef DRAW_DIRTY_RECTANGLE
  dirty_set = 1;
#endif
    #ifdef DRAW_HW_Y_ORIGIN_TOP_LEFT
      draw_top_pixel_y = 0;
      draw_bottom_pixel_y = draw_pixels_high - 1;
    #else
	draw_top_pixel_y = draw_pixels_high - 1;
	draw_bottom_pixel_y = 0;
    #endif

	if (draw_buffer) {
	    free(draw_buffer);
	}
	draw_buffer = (uns8 *)malloc(draw_total_buffer_size);
	//drv_init(width, height);
	draw_clear_screen();
	if (draw_buffer != 0) {
    serial_print_str("Buffer size = ");
    serial_print_int(draw_total_buffer_size);
  	return 1;
	}

	serial_print_str("Could not allocate buffer for draw buffer\n");
	return 0;
}	



void draw_set_pixel(draw_x_type x, draw_y_type y, draw_colour_type colour) {

uns32 buffer_loc, loc_byte;
uns8  loc_bit, loc_in_buffer, buffer_num;
uns8  bit_count;

if ((x >= draw_pixels_wide) || (y >= draw_pixels_high)) {
    
    /*
    serial_print_str("<B:");
    serial_print_int(x);
    serial_putc(',');
    serial_print_int(y);
    serial_putc('>');
    */
    return;
}

#ifdef DRAW_DIRTY_RECTANGLE
  if (!dirty_set) {
    dirty_x_left = x;
    dirty_x_right = x;
    dirty_x_top = y;
    dirty_y_bottom = y;
  } else {
    if (x < dirty_x_left) {
       dirty_x_left = x;
    }
    if (x > dirty_x_right) {
      dirty_x_right = x;
    }
    if (y < dirty_y_bottom) { // assuming y=0 is bottom 
      dirty_y_bottom = y;
    }
    if (y > dirty_y_top) {
      dirty_y_top = y;
    }
    dirty_set = 1;
  }
#endif  
    /*
    serial_print_str("P<");
    serial_print_int(x);
    serial_putc(',');
    serial_print_int(y);
    serial_putc('>');
    */
     	// inverse here
	// y = DRAW_PIXELS_HIGH - 1 - y;
	 
    #ifdef DRAW_HW_Y_ORIGIN_TOP_LEFT
		#ifdef DRAW_HW_BUFFER_ORIENTATION_HORIZONTAL
			buffer_loc = y * draw_pixels_wide + x;
		#else
		// DRAW_HW_BUFFER_ORIENTATION == VERTICAL
			buffer_loc = x * draw_pixels_high + y;
		#endif
    #else
    // DRAW_HW_Y_ORIENTATION == BOTTOM_LEFT
		#ifdef DRAW_HW_BUFFER_ORIENTATION_HORIZONTAL
			buffer_loc = y * draw_pixels_wide + x;
		#else
		// DRAW_HW_BUFFER_ORIENTATION == VERTICAL
			buffer_loc = x * draw_pixels_high + y;
		#endif
    #endif
/*    serial_print_int(x);
    serial_putc(' ');
    serial_print_int(y);
    serial_print_nl();
    
    serial_print_str("->");
    serial_print_int(buffer_loc);
*/
	
	buffer_loc = buffer_loc * draw_bits_per_pixel;
	loc_byte = buffer_loc / draw_pixels_per_byte;
	loc_byte = buffer_loc / 8;
	loc_bit = (buffer_loc & (0x07));
	
/*byte	0	     1        2   
bit		0 2 4 6  0 2 4 6  0 2 4 6
pix	    0 1 2 3  4 5 6 7  8 9 a b 
bit pos 0 2 4 6  8 a c e
*/

	
	/* 
	// For debugging
	serial_print_str(" x=");
	serial_print_int(x);
	serial_print_str(" y=");
	serial_print_int(y);
	serial_print_str(" buffer_loc=");
	serial_print_int(buffer_loc);
	serial_print_str(" loc_byte=");
	serial_print_int(loc_byte);
	serial_print_str(" loc_bit=");
	serial_print_int(loc_bit); 
	serial_print_str(" LIB=");
	serial_print_int(loc_in_buffer);
	serial_print_nl();
	serial_print_str(" bnum=");
	serial_print_int(buffer_num);
	serial_print_str("\n");
	*/

	//buffer[loc_byte]
	if (draw_bits_per_pixel != 1) {
	
		bit_count = 0;
	
		while (bit_count < draw_bits_per_pixel) {
			if (test_bit(colour, bit_count)) {
				set_bit(draw_buffer[loc_byte], loc_bit);
			} else {
				clear_bit(draw_buffer[loc_byte], loc_bit);
			}
			bit_count++;
			loc_bit++;
			if (loc_bit == 8) { // spill over into next byte
			    loc_byte++;
			    loc_bit = 0;
			}
		}
	} else {
	
		if (colour) {
			set_bit(draw_buffer[loc_byte], loc_bit);
		} else {
			clear_bit(draw_buffer[loc_byte], loc_bit);
		}	
	}

}

	
uns8 draw_get_pixel(draw_x_type x, draw_y_type y) {
	return 0;
}	


void draw_rect(draw_x_type x, draw_y_type y, uns16 width, draw_y_type height, uns8 colour) {
uns16 dx, dy;

	//serial_print_var("x=", x);
	//serial_print_var("y=", y);
	//serial_print_var("w=", width);
	//serial_print_var("height=", height);
	//serial_print_var("col=", colour);
	


	#ifdef DRAW_HW_Y_ORIGIN_BOTTOM_LEFT
	for(dy = y ; dy < y + height ; dy++) {
	#else 	
	for(dy = y + 1 - height ; dy <= y ; dy++) {
	#endif
		//serial_print_var("\ny=", dy);
		for(dx = x ; dx < x + width ; dx++) {
			draw_set_pixel(dx, dy, colour);
			//serial_print_str(" ");
			//serial_print_int(dx);
			//serial_print_str(",");
			//serial_print_int(dy);
			//serial_print_nl();
			}
		}
	}	


void draw_print_buffer() {

uns16	inv_y, x , y,
		 byte_loc, bit_loc;
uns16	 buffer_loc;

	for(y = 0 ; y < draw_pixels_high ; y++) {
		#ifdef DRAW_HW_Y_ORIGIN_BOTTOM_LEFT
			inv_y = DRAW_PIXELS_HIGH - 1 - y; // need to print out from the top
		#else
			inv_y = y;
		#endif	
			
		if (inv_y < 10) {
			serial_putc('0');
		}
		serial_print_int(inv_y);
		serial_putc(' ');
		serial_print_int_hex(inv_y * draw_pixels_wide / draw_pixels_per_byte);
		serial_putc('|');
		for(x = 0 ; x < draw_pixels_wide  ; x++) {
			buffer_loc = inv_y * draw_pixels_wide + x;
			buffer_loc = buffer_loc * draw_bits_per_pixel;
			byte_loc = buffer_loc / 8;
			bit_loc = (buffer_loc & (0x07));

			uns8 bit_count = 0;
			uns8 pixel = 0;
			while (bit_count < draw_bits_per_pixel) {
				if (test_bit(draw_buffer[byte_loc], bit_loc)) {
				    pixel = pixel + (1 << bit_count);
				}
				bit_count++;
				bit_loc++;
			}
			serial_print_int(pixel);
		}
		
		serial_print_str("|\n");
		
	}
	
}			

void draw_line(draw_x_type x0, draw_y_type y0, draw_x_type x1, draw_y_type y1, uns8 colour) {

    int dy = y1 - y0;
    int dx = x1 - x0;
    int stepx, stepy;

    if (dy < 0) { dy = -dy;  stepy = -1; } else { stepy = 1; }
    if (dx < 0) { dx = -dx;  stepx = -1; } else { stepx = 1; }
    dy <<= 1;                                                  // dy is now 2*dy
    dx <<= 1;                                                  // dx is now 2*dx

    draw_set_pixel(x0, y0, colour);
    if (dx > dy) {
        int fraction = dy - (dx >> 1);                         // same as 2*dy - dx
        while (x0 != x1) {
            if (fraction >= 0) {
                y0 += stepy;
                fraction -= dx;                                // same as fraction -= 2*dx
            }
            x0 += stepx;
            fraction += dy;                                    // same as fraction -= 2*dy
	    draw_set_pixel(x0, y0, colour);
        }
    } else {
        int fraction = dx - (dy >> 1);
        while (y0 != y1) {
            if (fraction >= 0) {
                x0 += stepx;
                fraction -= dy;
            }
            y0 += stepy;
            fraction += dx;
	    draw_set_pixel(x0, y0, colour);
        }
    }
}


void draw_circle_lines (int ctr_x, int ctr_y, int pt_x, int pt_y, uns8 colour) {
	draw_line(ctr_x - pt_x, ctr_y + pt_y, ctr_x + pt_x, ctr_y + pt_y, colour);
	draw_line(ctr_x - pt_x, ctr_y - pt_y, ctr_x + pt_x, ctr_y - pt_y, colour);
	draw_line(ctr_x + pt_y, ctr_y + pt_x, ctr_x - pt_y, ctr_y + pt_x, colour);
	draw_line(ctr_x + pt_y, ctr_y - pt_x, ctr_x - pt_y, ctr_y - pt_x, colour);
}

void draw_filled_circle(draw_x_type x_centre, draw_y_type y_centre, int r, uns8 colour) {
	int x,y;
	int p = 1 - r;         // Initial value of decision parameter.

	x = 0;
	y = r;
	
	draw_circle_lines(x_centre, y_centre, x, y, colour);
    
	while (x < y) {
		x++;
		if (p < 0)
			p += 2 * x + 1;
		else {
			y--;
			p += 2 * (x - y) + 1;
		}
		draw_circle_lines (x_centre, y_centre, x, y, colour);
	}

}


void draw_circle_points (int ctr_x, int ctr_y, int pt_x, int pt_y, uns8 colour) {
	// the eight symmetric points
	draw_set_pixel (ctr_x + pt_x, ctr_y + pt_y, colour);
	draw_set_pixel (ctr_x - pt_x, ctr_y + pt_y, colour);

	draw_set_pixel (ctr_x + pt_x, ctr_y - pt_y, colour);
	draw_set_pixel (ctr_x - pt_x, ctr_y - pt_y, colour);
	
	draw_set_pixel (ctr_x + pt_y, ctr_y + pt_x, colour);
	draw_set_pixel (ctr_x - pt_y, ctr_y + pt_x, colour);
	
	draw_set_pixel (ctr_x + pt_y, ctr_y - pt_x, colour);
	draw_set_pixel (ctr_x - pt_y, ctr_y - pt_x, colour);
}

void draw_circle(draw_x_type x_centre, draw_y_type y_centre, int r, uns8 colour) {
	int x,y;
	int p = 1 - r;         // Initial value of decision parameter.

	x = 0;
	y = r;
	
	draw_circle_points(x_centre, y_centre, x, y, colour);

	while (x < y) {
		x++;
		if (p < 0)
			p += 2 * x + 1;
		else {
			y--;
			p += 2 * (x - y + 1);
		}
		draw_circle_points (x_centre, y_centre, x, y, colour);
	}

}
void draw_circle_points2 (int ctr_x, int ctr_y, int pt_x, int pt_y, uns8 colour) {
	// the eight symmetric points
	draw_set_pixel (ctr_x + pt_x + 1, ctr_y + pt_y +1, colour);
	draw_set_pixel (ctr_x + pt_y + 1, ctr_y + pt_x +1, colour);

	draw_set_pixel (ctr_x + pt_x + 1, ctr_y - pt_y, colour);
	draw_set_pixel (ctr_x + pt_y + 1, ctr_y - pt_x, colour);

	draw_set_pixel (ctr_x - pt_x, ctr_y - pt_y, colour);
	draw_set_pixel (ctr_x - pt_y, ctr_y - pt_x, colour);

	draw_set_pixel (ctr_x - pt_x, ctr_y + pt_y +1, colour);
	draw_set_pixel (ctr_x - pt_y, ctr_y + pt_x +1, colour);
	
}
void draw_circle2(draw_x_type x_centre, draw_y_type y_centre, int r, uns8 colour) {
	int x, y;
	//int p = 1 - r; // orig
	//int p = 3 - 2*r;         // (a) Initial value of decision parameter.
	//int p = 1-r; // (b)
	int p = 1 -r; // (c) 5//4 - r  
	x = 0;
	y = r;
	
	draw_circle_points2(x_centre, y_centre, x, y, colour);

	while (x < y) {
		x++;
		if (p < 0)
			//p += 2 * x + 2; // (orig)
			//p = p + (4 * x) + 6; // (a)
			//p = p + 2* x + 3; // (b)
			p = p + 2* x + 1; // (c)
		else {
			y--;
			//p += 2 * (x - y + 1); // (orig)
			// p = p + 4 * (x - y) + 10; // (a)
			//p = p + 2 * (x - y) + 5;
			p = p + 2*(x-y) + 1;
		}
		draw_circle_points2 (x_centre, y_centre, x, y, colour);
	}

}

void draw_circle_lines2 (int ctr_x, int ctr_y, int pt_x, int pt_y, uns8 colour) {
	// the eight symmetric points
	draw_line(ctr_x - pt_x, ctr_y + pt_y + 1, ctr_x + pt_x, ctr_y + pt_y + 1, colour);
	draw_line(ctr_x - pt_x, ctr_y - pt_y, ctr_x + pt_x, ctr_y - pt_y, colour);
	draw_line(ctr_x + pt_y, ctr_y + pt_x + 1, ctr_x - pt_y, ctr_y + pt_x + 1, colour);
	draw_line(ctr_x + pt_y, ctr_y - pt_x, ctr_x - pt_y, ctr_y - pt_x, colour);
	
	
}
void draw_filled_circle2(draw_x_type x_centre, draw_y_type y_centre, int r, uns8 colour) {
	int x, y;
	//int p = 1 - r; // orig
	//int p = 3 - 2*r;         // (a) Initial value of decision parameter.
	//int p = 1-r; // (b)
	int p = 1 -r; // (c) 5//4 - r  
	x = 0;
	y = r;
	
	draw_circle_lines2(x_centre, y_centre, x, y, colour);

	while (x < y) {
		x++;
		if (p < 0)
			//p += 2 * x + 2; // (orig)
			//p = p + (4 * x) + 6; // (a)
			//p = p + 2* x + 3; // (b)
			p = p + 2* x + 1; // (c)
		else {
			y--;
			//p += 2 * (x - y + 1); // (orig)
			// p = p + 4 * (x - y) + 10; // (a)
			//p = p + 2 * (x - y) + 5;
			p = p + 2*(x-y) + 1;
		}
		draw_circle_lines2 (x_centre, y_centre, x, y, colour);
	}

}



// currently only handles monochrome bitmaps
void draw_bitmap(draw_x_type x, draw_y_type y, uns8 colour, char *bitmap) {


uns8 bitpos = 0;
uns8 bytepos = 0;
uns8 value;
draw_x_type bitmap_width = bitmap[0];
draw_y_type bitmap_height = bitmap[1];
uns8 bitmap_bpp = bitmap[2];
draw_x_type xbitmap;
draw_y_type ybitmap;


	bytepos = 3;	// first byte of data - 1
	bitpos = 0b10000000;	// left most bit
	
	for (xbitmap = 0; xbitmap < bitmap_width; xbitmap++) {
		for (ybitmap = 0; ybitmap < bitmap_height; ybitmap++) {
			if (bitpos == 0b10000000) {
				bitpos = 0b00000001;
				bytepos++;
				value = bitmap[bytepos];
			} else {
				bitpos = bitpos << 1;
			}
			if (value & bitpos) {
				#ifdef DRAW_HW_Y_ORIGIN == TOP_LEFT
					draw_set_pixel(x + xbitmap, y + ybitmap, colour);
				#else
					draw_set_pixel(x + xbitmap, y - ybitmap, colour);
				#endif
			}
     //serial_print_str("bitmap draw");
		}	
	}	
}    

void draw_paint() {
  #ifdef DRAW_DIRTY_RECTANGLE
    drv_paint_partial(dirty_x_left, dirty_y_top, dirty_x_right, dirty_y_bottom);
  #else
    drv_paint();
  #endif  
}

void draw_paint_full() {
  drv_paint();
}
	


/*

 notes:


http://www.gamedev.net/reference/articles/article767.asp

    d := 3 - (2 * RADIUS)
    x := 0
    y := RADIUS


Now for each pixel we do the following operations:


    Draw the 8 circle pixels
    if d < 0 then
        d := d + (4 * x) + 6
    else
      begin
        d := d + 4 * (x - y) + 10
        y := y - 1;
      end;

http://www.mandelbrot-dazibao.com/Bresen/Bresen.htm

x% = 0
y% = Rad%
s% = 1 - Rad%

DO WHILE x% < y%
IF s% < 0 THEN
s% = s% + 2 * x% + 3

ELSE

s% = s% + 2 * (x% - y%) + 5
y% = y% - 1
END IF

x% = x% + 1
Pset x%,y%
LOOP

*/

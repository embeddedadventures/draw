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

#include "draw_fonts.h"
#include "draw_font_5narrow.h"
#include "draw_font_16triple.h"
#include "draw_font_16double.h"
#include "draw_font_24triple.h"
#include "draw_font_8normal.h"
#include "draw_font_10normal.h"
#include "draw_font_10narrow.h"
#include "draw_font_10double.h"
#include "draw_font_12double.h"
#include "draw_font_7normal.h"
#include "draw_font_bignum.h"
#include "draw_font_32tahoma.h"
#include "draw_font_32segoe.h"
#include "draw_font_10arial.h"
#include "draw_font_5x7fixed.h"
//#include "draw_font_28normal.h"
#include "draw.h"
#include "config.h"
#include "utils.h"

//#include "stdlib.h"

typedef struct _font_index {
		uns8 font_id;
		const uns16 *index;
		const uns8 *data;
		uns8 first_char;
		uns8 last_char;
		uns8 height;
		uns8 bytes_per_sliver;
		uns8 inter_gap;
} font_index;	


font_index draw_font_indexes[FONT_COUNT];
uns16 index_loc;
const uns16 *font_index_loc;
const uns8  *font_data_loc;
uns8 bytes_per_sliver;
uns8 first_char;
uns8 last_char;
uns8 inter_gap;
uns8 font_height;
uns8 last_font_id = 255;

uns8 max_index = 0;

void draw_fonts_init(void) {

uns8 index;

	index = 0;
	#ifdef DRAW_FONT_5NARROW

		draw_font_indexes[index].font_id = DRAW_FONT_5NARROW_ID;
		draw_font_indexes[index].index = font_5narrow_index;
		draw_font_indexes[index].data = font_5narrow_data;
		draw_font_indexes[index].first_char = DRAW_FONT_5NARROW_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_5NARROW_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_5NARROW_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_5NARROW_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_5NARROW_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_5NORMAL

		draw_font_indexes[index].font_id = DRAW_FONT_5NORMAL_ID;
		draw_font_indexes[index].index = font_5normal_index;
		draw_font_indexes[index].data = font_5normal_data;
		draw_font_indexes[index].first_char = DRAW_FONT_5NORMAL_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_5NORMAL_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_5NORMAL_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_5NORMAL_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_5NORMAL_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_7NORMAL

		draw_font_indexes[index].font_id = DRAW_FONT_7NORMAL_ID;
		draw_font_indexes[index].index = font_7normal_index;
		draw_font_indexes[index].data = font_7normal_data;
		draw_font_indexes[index].first_char = DRAW_FONT_7NORMAL_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_7NORMAL_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_7NORMAL_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_7NORMAL_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_7NORMAL_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_8NORMAL

		draw_font_indexes[index].font_id = DRAW_FONT_8NORMAL_ID;
		draw_font_indexes[index].index = font_8normal_index;
		draw_font_indexes[index].data = font_8normal_data;
		draw_font_indexes[index].first_char = DRAW_FONT_8NORMAL_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_8NORMAL_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_8NORMAL_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_8NORMAL_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_8NORMAL_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_8FIXED

		draw_font_indexes[index].font_id = DRAW_FONT_8FIXED_ID;
		draw_font_indexes[index].index = font_8fixed_index;
		draw_font_indexes[index].data = font_8fixed_data;
		draw_font_indexes[index].first_char = DRAW_FONT_8FIXED_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_8FIXED_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_8FIXED_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_8FIXED_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_8FIXED_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_10NARROW

		draw_font_indexes[index].font_id = DRAW_FONT_10NARROW_ID;
		draw_font_indexes[index].index = font_10narrow_index;
		draw_font_indexes[index].data = font_10narrow_data;
		draw_font_indexes[index].first_char = DRAW_FONT_10NARROW_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_10NARROW_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_10NARROW_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_10NARROW_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_10NARROW_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_10NORMAL

		draw_font_indexes[index].font_id = DRAW_FONT_10NORMAL_ID;
		draw_font_indexes[index].index = font_10normal_index;
		draw_font_indexes[index].data = font_10normal_data;
		draw_font_indexes[index].first_char = DRAW_FONT_10NORMAL_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_10NORMAL_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_10NORMAL_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_10NORMAL_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_10NORMAL_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_10DOUBLE

		draw_font_indexes[index].font_id = DRAW_FONT_10DOUBLE_ID;
		draw_font_indexes[index].index = font_10double_index;
		draw_font_indexes[index].data = font_10double_data;
		draw_font_indexes[index].first_char = DRAW_FONT_10DOUBLE_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_10DOUBLE_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_10DOUBLE_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_10DOUBLE_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_10DOUBLE_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_12DOUBLE

		draw_font_indexes[index].font_id = DRAW_FONT_12DOUBLE_ID;
		draw_font_indexes[index].index = font_12double_index;
		draw_font_indexes[index].data = font_12double_data;
		draw_font_indexes[index].first_char = DRAW_FONT_12DOUBLE_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_12DOUBLE_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_12DOUBLE_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_12DOUBLE_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_12DOUBLE_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_16DOUBLE

		draw_font_indexes[index].font_id = DRAW_FONT_16DOUBLE_ID;
		draw_font_indexes[index].index = font_16double_index;
		draw_font_indexes[index].data = font_16double_data;
		draw_font_indexes[index].first_char = DRAW_FONT_16DOUBLE_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_16DOUBLE_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_16DOUBLE_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_16DOUBLE_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_16DOUBLE_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_16TRIPLE
		draw_font_indexes[index].font_id = DRAW_FONT_16TRIPLE_ID;
		draw_font_indexes[index].index = font_16triple_index;
		draw_font_indexes[index].data = font_16triple_data;
		draw_font_indexes[index].first_char = DRAW_FONT_16TRIPLE_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_16TRIPLE_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_16TRIPLE_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_16TRIPLE_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_16TRIPLE_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_24TRIPLE
		draw_font_indexes[index].font_id = DRAW_FONT_24TRIPLE_ID;
		draw_font_indexes[index].index = font_24triple_index;
		draw_font_indexes[index].data = font_24triple_data;
		draw_font_indexes[index].first_char = DRAW_FONT_24TRIPLE_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_24TRIPLE_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_24TRIPLE_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_24TRIPLE_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_24TRIPLE_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_BIGNUM
		draw_font_indexes[index].font_id = DRAW_FONT_BIGNUM_ID;
		draw_font_indexes[index].index = font_bignum_index;
		draw_font_indexes[index].data = font_bignum_data;
		draw_font_indexes[index].first_char = DRAW_FONT_BIGNUM_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_BIGNUM_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_BIGNUM_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_BIGNUM_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_BIGNUM_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_28NORMAL
		draw_font_indexes[index].font_id = DRAW_FONT_28NORMAL_ID;
		draw_font_indexes[index].index_location = font_28normal_get_index_loc();
		draw_font_indexes[index].data_location = font_28normal_get_data_loc();
		draw_font_indexes[index].first_char = DRAW_FONT_28NORMAL_FIRST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_28NORMAL_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_28NORMAL_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_28NORMAL_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_32TAHOMA
		draw_font_indexes[index].font_id = DRAW_FONT_32TAHOMA_ID;
		draw_font_indexes[index].index = font_32tahoma_index;
		draw_font_indexes[index].data = font_32tahoma_data;
		draw_font_indexes[index].first_char = DRAW_FONT_32TAHOMA_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_32TAHOMA_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_32TAHOMA_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_32TAHOMA_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_32TAHOMA_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_32SEGOE
		draw_font_indexes[index].font_id = DRAW_FONT_32SEGOE_ID;
		draw_font_indexes[index].index = font_32segoe_index;
		draw_font_indexes[index].data = font_32segoe_data;
		draw_font_indexes[index].first_char = DRAW_FONT_32SEGOE_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_32SEGOE_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_32SEGOE_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_32SEGOE_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_32SEGOE_INTER_GAP;
	#endif	
	#ifdef DRAW_FONT_10ARIAL
		draw_font_indexes[index].font_id = DRAW_FONT_10ARIAL_ID;
		draw_font_indexes[index].index = font_10arial_index;
		draw_font_indexes[index].data = font_10arial_data;
		draw_font_indexes[index].first_char = DRAW_FONT_10ARIAL_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_10ARIAL_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_10ARIAL_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_10ARIAL_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_10ARIAL_INTER_GAP;
	#endif
	#ifdef DRAW_FONT_5x7FIXED
		draw_font_indexes[index].font_id = DRAW_FONT_5X7FIXED_ID;
		draw_font_indexes[index].index = font_5x7fixed_index;
		draw_font_indexes[index].data = font_5x7fixed_index;
		draw_font_indexes[index].first_char = DRAW_FONT_5X7FIXED_FIRST_CHAR;
		draw_font_indexes[index].last_char = DRAW_FONT_5X7FIXED_LAST_CHAR;
		draw_font_indexes[index].height = DRAW_FONT_5X7FIXED_HEIGHT;
		draw_font_indexes[index].bytes_per_sliver = DRAW_FONT_5X7FIXED_BYTES_PER_SLIVER;
		draw_font_indexes[index++].inter_gap = DRAW_FONT_5X7FIXED_INTER_GAP;
	#endif
  max_index = index-1;
  serial_print_str("Max index = ");
  serial_print_int(max_index);
}

uns8 ICACHE_FLASH_ATTR read_rom_uint8(const uns8* addr){
    uint32 bytes;
    bytes = *(uint32*)((uint32)addr & ~3);
    return ((uns8*)&bytes)[(uint32)addr & 3];
}
 

uns16 draw_fonts_get_index_loc(uns8 id) {

uns8 count;
	//serial_print_str("Finding font ");
	//serial_print_int(id);
	for (count = 0; count != FONT_COUNT; count++) {
		if (draw_font_indexes[count].font_id == id) {
			//serial_print_str(" found!\n");
			return count;
		}
	}
	serial_print_str("Bad font!\n");
	return 255;
}			
	
uns8 draw_fonts_prepare(uns8 font_id) {
	if (font_id != last_font_id) {
		//serial_print_str("Updating font to ");
		//serial_print_int(font_id);
		//serial_print_nl();
		index_loc = draw_fonts_get_index_loc(font_id);
		if (index_loc != 255) {
		    font_index_loc = draw_font_indexes[index_loc].index;
		    font_data_loc  = draw_font_indexes[index_loc].data;

		    first_char = draw_font_indexes[index_loc].first_char;
		    last_char = draw_font_indexes[index_loc].last_char;

		    inter_gap = draw_font_indexes[index_loc].inter_gap;
		    font_height = draw_font_indexes[index_loc].height;
		    bytes_per_sliver = draw_font_indexes[index_loc].bytes_per_sliver;
		    last_font_id = font_id;
		    return 1;
		}  else {
		    return 0;
		}
	}
	return 1;
}	

draw_y_type draw_fonts_height(uns8 font_id) {
    uns8 my_index_loc;

    my_index_loc = draw_fonts_get_index_loc(font_id);
    if (index_loc != 255) {
        return draw_font_indexes[my_index_loc].height;
    } else {
	return 0;
    }

}	

uns16 draw_fonts_length_str(uns8 font_id, char *str) {

uns8 my_char;
uns16 length;
uns16 index_pos;
uns16 index_pos_next;
uns16 total_slivers;

	draw_fonts_prepare(font_id);
	
	length = 0;
	index_pos = 0;
	index_pos_next = 0;

	
	while (*str != 0) {
		my_char = *str;
		if ((my_char < first_char) || (my_char > last_char)) {
			my_char = '?';
		}

		my_char = my_char - first_char;
		index_pos = font_index_loc[my_char];
		index_pos_next = font_index_loc[my_char+1];
		total_slivers = index_pos_next - index_pos + inter_gap;
		length = length + total_slivers;
		str++;
	}
	
	length = length - inter_gap;	// no gap at the end
	return length;
}

void draw_fonts_print_str_rj(uns8 font_id, draw_x_type x, draw_y_type y, draw_x_type width, uns16 start_pixel, uns8 colour, char *str) {


uns16 length;

	length = draw_fonts_length_str(font_id, str);


	if (x + 1 >= length) {
		x = x - length + 1;
		draw_fonts_print_str(font_id, x, y, width, start_pixel, colour, str);
	} else {
		serial_print_str("Error\n");
	}

}

void draw_fonts_print_str_c(uns8 font_id, draw_x_type x, draw_y_type y, draw_x_type width, uns16 start_pixel, uns8 colour, char *str) {


uns16 length;

	length = draw_fonts_length_str(font_id, str);


	if (x + 1 >= (length / 2)) {
		x = x - (length / 2) + 1;
		draw_fonts_print_str(font_id, x, y, width, start_pixel, colour, str);
	} else {
		serial_print_str("Error\n");
	}

}



void draw_fonts_print_str(uns8 font_id, draw_x_type x, draw_y_type y, draw_x_type width, uns16 start_pixel, uns8 colour, char *str) {

uns8 my_char;
uns16 index_pos = 0;
uns16 index_pos_next = 0;
uns16 count, s_count;
uns16 sliver, x_origin, y_origin, pixel;
uns16 lookup;


	y_origin = y;
	x_origin = x;
	pixel = 0;


// prep the font
	#ifdef DEBUG_FONTS
		serial_print_str("FONT\n");
		serial_print_var("x", x);
		serial_print_var("y", y);
		serial_print_var("width", width);
		serial_print_var("sp", start_pixel);
	#endif
	if (!draw_fonts_prepare(font_id)) {
	    serial_print_str("Not doing font, bad font!\n");
	    return;
	}

	#ifdef DEBUG_FONTS
		serial_print_str("Print:\"");
		serial_print_str(str);
		serial_print_str("\"\n");	
	#endif
	
	while (*str) {
		
		#ifdef DEBUG_FONTS
			serial_print_str("Print:\"");
			serial_print_str(str);
			serial_print_str("\"\n");	
		
			serial_print_str(" Char=");
			serial_putc(*str);
			serial_print_nl();
			serial_print_var("fh=", font_height);
			serial_print_nl();
		#endif
			
		// first look up character in index
		my_char = *str;

		if ((my_char < first_char) || (my_char > last_char)) {
			my_char = '?';
		}	
		my_char = my_char - first_char;

		index_pos = font_index_loc[my_char];
		index_pos_next = font_index_loc[my_char+1];
				
		#ifdef DEBUG_FONTS
			serial_print_var("my_char=", my_char);
			serial_print_var("first_char	=", first_char);

			serial_print_var("my_char - first_char =", index_pos);
			serial_print_var("index_pos=", index_pos);
			serial_print_var("index_pos_next=", index_pos_next);
		#endif
		
		uns8 total_slivers = index_pos_next - index_pos;

		index_pos = index_pos * bytes_per_sliver;

		lookup =  index_pos;

		#ifdef DEBUG_FONTS
			serial_print_var("datalookup=", lookup);
			serial_print_var("total_slivers=", total_slivers);
			serial_print_var("font_height=", font_height);
			serial_print_var("first_char=", first_char);

		#endif
		if (pixel + total_slivers > start_pixel) {
		     for(count = 0 ; count != total_slivers ; count++) {	// interate over slivers
			    #ifdef DEBUG_FONTS
				    serial_print_var("Count=", count);
			    #endif
			    // Now iterate over sliver

			    s_count = 0;
				while (s_count < font_height) {	// interate over a single sliver

				    if (s_count % 8 == 0) {	// grab another byte of the sliver
					sliver = font_data_loc[lookup++];
					//sliver = read_rom_uint8(&font_data_loc[lookup++]);
					#ifdef DEBUG_FONTS
						serial_print_str("sliver=");
						serial_print_int_hex(sliver);
						serial_print_nl();
					#endif
				    }
				    if (pixel >= start_pixel) {
					if (test_bit(sliver, 7)) {
					    #ifdef DRAW_HW_Y_ORIGIN_TOP_LEFT
              //#error "BOttom left"
						    draw_set_pixel(x, y + s_count, colour);
					    #else
					    // DRAW_HW_Y_ORIGIN_BOTTOM_LEFT
               //#error "top left"
						    draw_set_pixel(x, y - s_count, colour);
					    #endif
					} else {
					    #ifdef DRAW_HW_Y_ORIGIN_TOP_LEFT
						    draw_set_pixel(x, y + s_count, 0);
					    #else
					    // DRAW_HW_Y_ORIGIN_BOTTOM_LEFT
						    draw_set_pixel(x, y - s_count, 0);
					    #endif

					}
				    }
				    sliver <<= 1;
				    s_count++;
				}	// display sliver
			    if (pixel >= start_pixel) {
				x++;
			    }
			    if (x - x_origin >= width) {
				return;
			    }
			    pixel++;
		    } // all slivers
		} else {
		    pixel = pixel + total_slivers;
		}
		str++;	// next character
    delay(0);
		uns8 intergap_count;
		intergap_count = inter_gap;
		while (intergap_count) {


		    if (pixel >= start_pixel) {
			s_count = 0;
			while (s_count < font_height) {	// interate over a single sliver
			    #ifdef DRAW_HW_Y_ORIGIN_BOTTOM_LEFT
				    draw_set_pixel(x, y + s_count, 0);
			    #else
			    // DRAW_HW_Y_ORIGIN == TOP_LEFT
				    draw_set_pixel(x, y - s_count, 0);
			    #endif
			    s_count++;
			}

			x++;
		    }
		    pixel++;
		    intergap_count--;
		}
			
		if (x - x_origin >= width) {
			return;
		}	
	}
}    



void draw_fonts_print_str_wiggle(uns8 font_id, draw_x_type x, draw_y_type y, draw_x_type width, uns16 start_pixel, uns8 colour, char *str, int8 wiggle, int8 start_wiggle, uns8 start_wiggle_inc) {

uns8 my_char;
uns16 index_pos = 0;
uns16 index_pos_next = 0;
uns16 count, s_count;
uns16 sliver, x_origin, y_origin, pixel;
uns16 lookup;
int8  local_wiggle;
uns8 wiggle_inc = start_wiggle_inc;


	y_origin = y;
	x_origin = x;
	pixel = 0;
	local_wiggle = start_wiggle;
	

// prep the font
	if (!draw_fonts_prepare(font_id)) {
	    serial_print_str("Not doing font, bad font!\n");
	    return;
	}

	while (*str) {
		// first look up character in index
		my_char = *str;

		if ((my_char < first_char) || (my_char > last_char)) {
			my_char = '?';
		}
		my_char = my_char - first_char;

		index_pos = font_index_loc[my_char];
		index_pos_next = font_index_loc[my_char+1];

		uns8 total_slivers = index_pos_next - index_pos;

		index_pos = index_pos * bytes_per_sliver;

		lookup =  index_pos;

		if (pixel + total_slivers > start_pixel) {
		    for(count = 0 ; count < total_slivers ; count++) {	// interate over slivers

		     // Now iterate over sliver

			s_count = 0;

			while (s_count < font_height) {	// interate over a single sliver

			    if (s_count % 8 == 0) {	// grab another byte of the sliver
				//sliver = read_rom_uint8(&font_data_loc[lookup++]);
				sliver = font_data_loc[lookup++];
			    }
			    if (pixel >= start_pixel) {
				if (test_bit(sliver, 7)) {
				    #ifdef DRAW_HW_Y_ORIGIN_BOTTOM_LEFT
					    draw_set_pixel(x, y + s_count + local_wiggle, colour);
				    #else
				    // DRAW_HW_Y_ORIGIN == TOP_LEFT
					    draw_set_pixel(x, y - s_count + local_wiggle, colour);
				    #endif
				}
			    }
			    sliver <<= 1;
			    s_count++;
			}	// display sliver
			if (pixel >= start_pixel) {
			    x++;
			}
			if (x - x_origin >= width) {
			    return;
			}
			pixel++;
		    } // all slivers
		} else {
		    pixel = pixel + total_slivers;
		}
		str++;	// next character

		uns8 intergap_count;
		intergap_count = inter_gap;

		while (intergap_count) {
		    if (pixel >= start_pixel) {
			x++;
		    }
		    pixel++;
		    intergap_count--;
		}

		if (x - x_origin >= width) {
			return;
		}
		if (wiggle_inc) {
		    local_wiggle++;
		    if (local_wiggle > wiggle) {
			local_wiggle = wiggle - 1;
			wiggle_inc = 0;
		    }
		} else {
		    local_wiggle--;
		    if (abs(local_wiggle) > wiggle) {
			local_wiggle = 0 - wiggle + 1;
			wiggle_inc = 1;
		    }
		}

	}
}

// todo: must refactor this at some point
void draw_fonts_bignum(draw_x_type x, draw_y_type y, draw_x_type width, draw_x_type start_pixel, uns8 colour, char *str) {

uns8 my_char;

	while (*str) {

		my_char = *str;

		switch (my_char) {
			case '0' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "#$\'");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, "\" \"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, "\" \"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "!$%");
				break;
			case '1' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, " \' ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, " \" ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, " \" ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, " & ");
				break;
			case '2' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "#$\'");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, "() ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, ".*\"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "!$%");
				break;
			case '3' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "#$\'");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, " )\"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, " *\"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "!$%");
				break;
			case '4' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "  \'");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, "))\"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, "+*\"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "& &");
				break;
			case '5' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "#$\'");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, "))\"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, "+*-");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "!$,");
				break;
			case '6' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "#$\'");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, "()\"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, "+*-");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "!$,");
				break;
			case '7' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "  \'");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, "  \"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, "  \"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "!$%");
				break;
			case '8' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "#$\'");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, "()\"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, "+*\"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "!$%");
				break;
			case '9' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "  \'");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, "))\"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, "+*\"");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "!$%");
				break;
			case ':' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, " ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, ",");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, ",");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, " ");
				break;
			case '\'' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, " ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, " ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, " ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "/");
				break;
			case 'F' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "\'  ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, "() ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, "+* ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "!$,");
				break;
			case 'C' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "#$\'");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, "\"  ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, "\"  ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "!$%");
			case ' ' :
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y,    width, start_pixel, colour, "   ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-7,  width, start_pixel, colour, "   ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-14, width, start_pixel, colour, "   ");
				draw_fonts_print_str(DRAW_FONT_BIGNUM_ID, x, y-21, width, start_pixel, colour, "   ");
				break;

		}
		if ((my_char != ':') && (my_char != '\'') && (my_char != ' ' )) {
			x = x + 15;
		} else {
			x = x + 5;
		}
		str++;
	}
}

void draw_fonts_print_str_vert(uns8 font_id, draw_x_type x, draw_y_type y, draw_y_type width, uns16 start_pixel, uns8 colour, char *str) {

uns8 my_char;
uns16 index_pos = 0;
uns16 index_pos_next = 0;
uns16 count, s_count;
uns16 sliver, x_origin, y_origin, pixel;
uns16 lookup;


	y_origin = y;
	x_origin = x;
	pixel = 0;


// prep the font
	#ifdef DEBUG_FONTS
		serial_print_str("FONT\n");
		serial_print_var("x", x);
		serial_print_var("y", y);
		serial_print_var("width", width);
		serial_print_var("sp", start_pixel);
	#endif
	if (!draw_fonts_prepare(font_id)) {
	    serial_print_str("Not doing font, bad font!\n");
	    return;
	}

	#ifdef DEBUG_FONTS
		serial_print_str("Print:\"");
		serial_print_str(str);
		serial_print_str("\"\n");
	#endif

	while (*str) {

		#ifdef DEBUG_FONTS
			serial_print_str("Print:\"");
			serial_print_str(str);
			serial_print_str("\"\n");

			serial_print_str(" Char=");
			serial_putc(*str);
			serial_print_nl();
			serial_print_var("fh=", font_height);
			serial_print_nl();
		#endif

		// first look up character in index
		my_char = *str;

		if ((my_char < first_char) || (my_char > last_char)) {
			my_char = '?';
		}
		my_char = my_char - first_char;

		index_pos = font_index_loc[my_char];
		index_pos_next = font_index_loc[my_char+1];

		#ifdef DEBUG_FONTS
			serial_print_var("my_char=", my_char);
			serial_print_var("first_char	=", first_char);

			serial_print_var("my_char - first_char =", index_pos);
			serial_print_var("index_pos=", index_pos);
			serial_print_var("index_pos_next=", index_pos_next);
		#endif

		uns8 total_slivers = index_pos_next - index_pos;

		index_pos = index_pos * bytes_per_sliver;

		lookup =  index_pos;

		#ifdef DEBUG_FONTS
			serial_print_var("datalookup=", lookup);
			serial_print_var("total_slivers=", total_slivers);
			serial_print_var("font_height=", font_height);
			serial_print_var("first_char=", first_char);

		#endif
		if (pixel + total_slivers > start_pixel) {
		     for(count = 0 ; count != total_slivers ; count++) {	// interate over slivers
			    #ifdef DEBUG_FONTS
				    serial_print_var("Count=", count);
			    #endif
			    // Now iterate over sliver

			    s_count = 0;
				while (s_count < font_height) {	// interate over a single sliver

				    if (s_count % 8 == 0) {	// grab another byte of the sliver
					sliver = font_data_loc[lookup++];
					//sliver = read_rom_uint8(&font_data_loc[lookup++]);
					#ifdef DEBUG_FONTS
						serial_print_str("sliver=");
						serial_print_int_hex(sliver);
						serial_print_nl();
					#endif
				    }
				    if (pixel >= start_pixel) {
					if (test_bit(sliver, 7)) {
					    #ifdef DRAW_HW_Y_ORIGIN_BOTTOM_LEFT
						    draw_set_pixel(x - s_count, y, colour);
					    #else
					    // DRAW_HW_Y_ORIGIN == TOP_LEFT
						    draw_set_pixel(x - s_count, y, colour);
					    #endif
					}
				    }
				    sliver <<= 1;
				    s_count++;
				}	// display sliver
			    if (pixel >= start_pixel) {
				y--;	// for bottom 0
			    }
			    if (y - y_origin >= width) {
				return;
			    }
			    pixel++;
		    } // all slivers
		} else {
		    pixel = pixel + total_slivers;
		}
		str++;	// next character

		uns8 intergap_count;
		intergap_count = inter_gap;
		while (intergap_count) {
		    if (pixel >= start_pixel) {
			y--;
		    }
		    pixel++;
		    intergap_count--;
		}

		if (y - y_origin >= width) {
			return;
		}
	}
}



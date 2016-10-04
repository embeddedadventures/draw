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

#include "utils.h"
#include "config.h"
#include "draw_border.h"
#include "draw.h"

uns8 border_style = 0;
uns8 border_frame = 0;
uns16 x, y, width, height;

void draw_border_set_style(uns8 style) {
    border_style = style;
    x = 0;
    y = 0;
    width = draw_pixels_wide;
    height = draw_pixels_high;
}

void border_alternate_dots_update(uns8 next_frame) {
uns16 col1, col2;

    if (next_frame) {
	border_frame++;
	if (border_frame == 2) {
	    border_frame = 0;
	}
    }
    if (border_frame == 0) {

	col1 = 1;
	col2 = 2;
    } else {

	col1 = 2;
	col2 = 1;
    }

    uns16 count;
    // top
    for (count=0; count < width; count = count + 2) {
	draw_set_pixel(x + count, y, col1);
	draw_set_pixel(x + count + 1, y, col2);
    }
    // right side
    for (count=0; count < height; count = count + 2) {
	draw_set_pixel(x + width - 1, y + count, col1);
	draw_set_pixel(x + width - 1, y + count + 1, col2);
    }
    // bottom
    for (count=0; count < width; count = count + 2) {
	draw_set_pixel(x + count, y + height - 1, col1);
	draw_set_pixel(x + count + 1, y + height - 1, col2);
    }
    // left side
    for (count=0; count < height; count = count + 2) {
	draw_set_pixel(x , y + count, col1);
	draw_set_pixel(x, y + count + 1, col2);
    }


}

void border_one_of_four_update(uns8 next_frame) {
uns16 col1, col2, col3, col4;

    if (next_frame) {
	border_frame++;
	if (border_frame == 4) {
	    border_frame = 0;
	}
    }
    if (border_frame == 0) {

	col1 = 1;
	col2 = 0;
	col3 = 0;
	col4 = 0;
    } else if (border_frame == 1) {
	col1 = 0;
	col2 = 1;
	col3 = 0;
	col4 = 0;
    } else if (border_frame == 2) {
	col1 = 0;
	col2 = 0;
	col3 = 1;
	col4 = 0;
    } else if (border_frame == 3) {
	col1 = 0;
	col2 = 0;
	col3 = 0;
	col4 = 1;
    }
    uns16 count;
    // top
    for (count=0; count < width; count = count + 4) {
	draw_set_pixel(x + count, y,     col1);
	draw_set_pixel(x + count + 1, y, col2);
	draw_set_pixel(x + count + 2, y, col3);
	draw_set_pixel(x + count + 3, y, col4);
    }
    // right side
    for (count=0; count < height; count = count + 4) {
	draw_set_pixel(x + width - 1, y + count,     col4);
	draw_set_pixel(x + width - 1, y + count + 1, col1);
	draw_set_pixel(x + width - 1, y + count + 2, col2);
	draw_set_pixel(x + width - 1, y + count + 3, col3);
    }
    // bottom
    for (count=0; count < width; count = count + 4) {
	draw_set_pixel(x + count, y + height - 1,     col2);
	draw_set_pixel(x + count + 1, y + height - 1, col1);
	draw_set_pixel(x + count + 2, y + height - 1, col4);
	draw_set_pixel(x + count + 3, y + height - 1, col3);
    }
    // left side
    for (count=0; count < height; count = count + 4) {
	draw_set_pixel(x, y + count,     col1);
	draw_set_pixel(x, y + count + 1, col4);
	draw_set_pixel(x, y + count + 2, col3);
	draw_set_pixel(x, y + count + 3, col2);
    }


}

void border_one_of_four_multi_update(uns8 next_frame) {
uns16 col1, col2, col3, col4;
uns8 col = 1;

    if (next_frame) {
	border_frame++;
	if (border_frame == 4) {
	    border_frame = 0;
	}

    }
    if (border_frame == 0) {

	col1 = 0;
	col2 = col;
	col3 = col;
	col4 = col;
    } else if (border_frame == 1) {
	col1 = col;
	col2 = 0;
	col3 = col;
	col4 = col;
    } else if (border_frame == 2) {
	col1 = col;
	col2 = col;
	col3 = 0;
	col4 = col;
    } else if (border_frame == 3) {
	col1 = col;
	col2 = col;
	col3 = col;
	col4 = 0;
    }
    uns16 count;
    // top
    for (count=0; count < width; count = count + 4) {
	draw_set_pixel(x + count, y,     col1);
	draw_set_pixel(x + count + 1, y, col2);
	draw_set_pixel(x + count + 2, y, col3);
	draw_set_pixel(x + count + 3, y, col4);
    }
    // right side
    for (count=0; count < height; count = count + 4) {
	draw_set_pixel(x + width - 1, y + count,     col4);
	draw_set_pixel(x + width - 1, y + count + 1, col1);
	draw_set_pixel(x + width - 1, y + count + 2, col2);
	draw_set_pixel(x + width - 1, y + count + 3, col3);
    }
    // bottom
    for (count=0; count < width; count = count + 4) {
	draw_set_pixel(x + count, y + height - 1,     col2);
	draw_set_pixel(x + count + 1, y + height - 1, col1);
	draw_set_pixel(x + count + 2, y + height - 1, col4);
	draw_set_pixel(x + count + 3, y + height - 1, col3);
    }
    // left side
    for (count=0; count < height; count = count + 4) {
	draw_set_pixel(x, y + count,     col1);
	draw_set_pixel(x, y + count + 1, col4);
	draw_set_pixel(x, y + count + 2, col3);
	draw_set_pixel(x, y + count + 3, col2);
    }


}

void border_one_of_four_3d_update(uns8 next_frame) {
uns16 col1, col2, col3, col4;
uns8 col = 1;

    if (next_frame) {
	border_frame++;
	if (border_frame == 4) {
	    border_frame = 0;
	}

    }
    if (border_frame == 0) {

	col1 = col;
	col2 = 0;
	col3 = 0;
	col4 = 0;
    } else if (border_frame == 1) {
	col1 = 0;
	col2 = col;
	col3 = 0;
	col4 = 0;
    } else if (border_frame == 2) {
	col1 = 0;
	col2 = 0;
	col3 = col;
	col4 = 0;
    } else if (border_frame == 3) {
	col1 = 0;
	col2 = 0;
	col3 = 0;
	col4 = col;
    }
    uns16 count;
    // top
    for (count=0; count < width; count = count + 4) {
	draw_set_pixel(x + count, y,     col1);
	draw_set_pixel(x + count + 1, y+1, col2);
	draw_set_pixel(x + count + 2, y, col3);
	draw_set_pixel(x + count + 3, y+1, col4);
    }
    // right side
    for (count=0; count < height; count = count + 4) {
	draw_set_pixel(x + width - 1, y + count,     col4);
	draw_set_pixel(x + width - 1 - 1, y + count + 1, col1);
	draw_set_pixel(x + width - 1 , y + count + 2, col2);
	draw_set_pixel(x + width - 1 - 1, y + count + 3, col3);
    }
    // bottom
    for (count=0; count < width; count = count + 4) {
	draw_set_pixel(x + count,     y + height - 1, col2);
	draw_set_pixel(x + count + 1, y + height - 1 - 1, col1);
	draw_set_pixel(x + count + 2, y + height - 1, col4);
	draw_set_pixel(x + count + 3, y + height - 1 - 1, col3);
    }
    // left side
    for (count=0; count < height; count = count + 4) {
	draw_set_pixel(x, y + count,     col1);
	draw_set_pixel(x+1, y + count + 1, col4);
	draw_set_pixel(x, y + count + 2, col3);
	draw_set_pixel(x + 1, y + count + 3, col2);
    }


}


uns8 draw_border_update(uns8 next_frame) {

    switch (border_style) {
	case 0: return 0; break;
	case 1: border_alternate_dots_update(next_frame); break;
	case 2: border_one_of_four_update(next_frame); break;
	case 3: border_one_of_four_multi_update(next_frame); break;
	case 4: border_one_of_four_3d_update(next_frame); break;
	default: break;
    }
    return 1;
}

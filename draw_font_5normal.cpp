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

#include "draw_font_5normal.h"

uns8 const font_5normal_data[] PROGMEM = {
   // 0,  32 -
 0x00, 0x00, 0x00,
//
//
//

    // 3,  33 - !
 0xb8,
// * ***

    // 4,  34 - "
 0x20, 0x18, 0x00, 0x20, 0x18,
//   *
//    **
//
//   *
//    **

    // 9,  35 - #
 0x50, 0xf8, 0x50, 0xf8, 0x50,
//  * *
// *****
//  * *
// *****
//  * *

    // 14,  36 - $
 0xa8, 0x50, 0xa8, 0x50, 0xa8,
// * * *
//  * *
// * * *
//  * *
// * * *

    // 19,  37 - %
 0x98, 0x58, 0x20, 0xd0, 0xc8,
// *  **
//  * **
//   *
// ** *
// **  *

    // 24,  38 - &
 0x50, 0xa8, 0x50, 0xa8, 0x50,
//  * *
// * * *
//  * *
// * * *
//  * *

    // 29,  39 - '
 0x20, 0x18,
//   *
//    **

    // 31,  40 - (
 0x70, 0x88,
//  ***
// *   *

    // 33,  41 - )
 0x88, 0x70,
// *   *
//  ***

    // 35,  42 - *
 0xa8, 0x70, 0xf8, 0x70, 0xa8,
// * * *
//  ***
// *****
//  ***
// * * *

    // 40,  43 - +
 0x20, 0x20, 0xf8, 0x20, 0x20,
//   *
//   *
// *****
//   *
//   *

    // 45,  44 - ,
 0x80, 0x60,
// *
//  **

    // 47,  45 - -
 0x20, 0x20, 0x20, 0x20,
//   *
//   *
//   *
//   *

    // 51,  46 - .
 0xc0, 0xc0,
// **
// **

    // 53,  47 - /
 0x80, 0x40, 0x20, 0x10, 0x08,
// *
//  *
//   *
//    *
//     *

    // 58,  48 - 0
 0x70, 0x88, 0x88, 0x88, 0x70,
//  ***
// *   *
// *   *
// *   *
//  ***

    // 63,  49 - 1
 0x10, 0xf8,
//    *
// *****

    // 65,  50 - 2
 0xc8, 0xa8, 0xa8, 0xa8, 0x90,
// **  *
// * * *
// * * *
// * * *
// *  *

    // 70,  51 - 3
 0x88, 0xa8, 0xa8, 0xa8, 0x50,
// *   *
// * * *
// * * *
// * * *
//  * *

    // 75,  52 - 4
 0x60, 0x50, 0x48, 0xf8, 0x40,
//  **
//  * *
//  *  *
// *****
//  *

    // 80,  53 - 5
 0xb8, 0xa8, 0xa8, 0xa8, 0x40,
// * ***
// * * *
// * * *
// * * *
//  *

    // 85,  54 - 6
 0x70, 0xa8, 0xa8, 0xa8, 0x40,
//  ***
// * * *
// * * *
// * * *
//  *

    // 90,  55 - 7
 0x08, 0xc8, 0x28, 0x18,
//     *
// **  *
//   * *
//    **

    // 94,  56 - 8
 0x50, 0xa8, 0xa8, 0xa8, 0x50,
//  * *
// * * *
// * * *
// * * *
//  * *

    // 99,  57 - 9
 0x10, 0xa8, 0xa8, 0xa8, 0x70,
//    *
// * * *
// * * *
// * * *
//  ***

    // 104,  58 - :
 0xd8, 0xd8,
// ** **
// ** **

    // 106,  59 - ;
 0x58, 0xd8,
//  * **
// ** **

    // 108,  60 - <
 0x20, 0x50, 0x88,
//   *
//  * *
// *   *

    // 111,  61 - =
 0x50, 0x50, 0x50, 0x50,
//  * *
//  * *
//  * *
//  * *

    // 115,  62 - >
 0x88, 0x50, 0x20,
// *   *
//  * *
//   *

    // 118,  63 - ?
 0x80, 0xc0, 0xe0, 0xf0, 0xf8,
// *
// **
// ***
// ****
// *****

    // 123,  64 - @
 0xf8, 0x78, 0x38, 0x18, 0x08,
// *****
//  ****
//   ***
//    **
//     *

    // 128,  65 - A
 0xf0, 0x28, 0x28, 0x28, 0xf0,
// ****
//   * *
//   * *
//   * *
// ****

    // 133,  66 - B
 0xf8, 0xa8, 0xa8, 0xa8, 0x50,
// *****
// * * *
// * * *
// * * *
//  * *

    // 138,  67 - C
 0x70, 0x88, 0x88, 0x88, 0x88,
//  ***
// *   *
// *   *
// *   *
// *   *

    // 143,  68 - D
 0xf8, 0x88, 0x88, 0x88, 0x70,
// *****
// *   *
// *   *
// *   *
//  ***

    // 148,  69 - E
 0xf8, 0xa8, 0xa8, 0xa8, 0x88,
// *****
// * * *
// * * *
// * * *
// *   *

    // 153,  70 - F
 0xf8, 0x28, 0x28, 0x28, 0x08,
// *****
//   * *
//   * *
//   * *
//     *

    // 158,  71 - G
 0x70, 0x88, 0x88, 0xa8, 0xe8,
//  ***
// *   *
// *   *
// * * *
// *** *

    // 163,  72 - H
 0xf8, 0x20, 0x20, 0x20, 0xf8,
// *****
//   *
//   *
//   *
// *****

    // 168,  73 - I
 0x88, 0xf8, 0x88,
// *   *
// *****
// *   *

    // 171,  74 - J
 0x40, 0x80, 0x80, 0x80, 0x78,
//  *
// *
// *
// *
//  ****

    // 176,  75 - K
 0xf8, 0x20, 0x50, 0x88,
// *****
//   *
//  * *
// *   *

    // 180,  76 - L
 0xf8, 0x80, 0x80, 0x80,
// *****
// *
// *
// *

    // 184,  77 - M
 0xf8, 0x10, 0x20, 0x10, 0xf8,
// *****
//    *
//   *
//    *
// *****

    // 189,  78 - N
 0xf8, 0x10, 0x20, 0x40, 0xf8,
// *****
//    *
//   *
//  *
// *****

    // 194,  79 - O
 0x70, 0x88, 0x88, 0x88, 0x70,
//  ***
// *   *
// *   *
// *   *
//  ***

    // 199,  80 - P
 0xf8, 0x28, 0x28, 0x28, 0x10,
// *****
//   * *
//   * *
//   * *
//    *

    // 204,  81 - Q
 0x70, 0x88, 0xa8, 0x48, 0xb0,
//  ***
// *   *
// * * *
//  *  *
// * **

    // 209,  82 - R
 0xf8, 0x28, 0x68, 0xa8, 0x90,
// *****
//   * *
//  ** *
// * * *
// *  *

    // 214,  83 - S
 0x90, 0xa8, 0xa8, 0xa8, 0x48,
// *  *
// * * *
// * * *
// * * *
//  *  *

    // 219,  84 - T
 0x08, 0x08, 0xf8, 0x08, 0x08,
//     *
//     *
// *****
//     *
//     *

    // 224,  85 - U
 0x78, 0x80, 0x80, 0x80, 0x78,
//  ****
// *
// *
// *
//  ****

    // 229,  86 - V
 0x38, 0x40, 0x80, 0x40, 0x38,
//   ***
//  *
// *
//  *
//   ***

    // 234,  87 - W
 0xf8, 0x40, 0x20, 0x40, 0xf8,
// *****
//  *
//   *
//  *
// *****

    // 239,  88 - X
 0x88, 0x50, 0x20, 0x50, 0x88,
// *   *
//  * *
//   *
//  * *
// *   *

    // 244,  89 - Y
 0x18, 0x20, 0xc0, 0x20, 0x18,
//    **
//   *
// **
//   *
//    **

    // 249,  90 - Z
 0x88, 0xc8, 0xa8, 0x98, 0x88,
// *   *
// **  *
// * * *
// *  **
// *   *

    // 254,  91 - [
 0xe8, 0x50, 0x50, 0x50, 0xe8,
// *** *
//  * *
//  * *
//  * *
// *** *

    // 259,  92 - backslash
 0x68, 0x90, 0x90, 0x90, 0x68,
//  ** *
// *  *
// *  *
// *  *
//  ** *

    // 264,  93 - ]
 0x68, 0x80, 0x80, 0x80, 0x68,
//  ** *
// *
// *
// *
//  ** *
00,
};
uns16 const font_5normal_index[] PROGMEM = {
    0, // 32 -
    3, // 33 - !
    4, // 34 - "
    9, // 35 - #
    14, // 36 - $
    19, // 37 - %
    24, // 38 - &
    29, // 39 - '
    31, // 40 - (
    33, // 41 - )
    35, // 42 - *
    40, // 43 - +
    45, // 44 - ,
    47, // 45 - -
    51, // 46 - .
    53, // 47 - /
    58, // 48 - 0
    63, // 49 - 1
    65, // 50 - 2
    70, // 51 - 3
    75, // 52 - 4
    80, // 53 - 5
    85, // 54 - 6
    90, // 55 - 7
    94, // 56 - 8
    99, // 57 - 9
    104, // 58 - :
    106, // 59 - ;
    108, // 60 - <
    111, // 61 - =
    115, // 62 - >
    118, // 63 - ?
    123, // 64 - @
    128, // 65 - A
    133, // 66 - B
    138, // 67 - C
    143, // 68 - D
    148, // 69 - E
    153, // 70 - F
    158, // 71 - G
    163, // 72 - H
    168, // 73 - I
    171, // 74 - J
    176, // 75 - K
    180, // 76 - L
    184, // 77 - M
    189, // 78 - N
    194, // 79 - O
    199, // 80 - P
    204, // 81 - Q
    209, // 82 - R
    214, // 83 - S
    219, // 84 - T
    224, // 85 - U
    229, // 86 - V
    234, // 87 - W
    239, // 88 - X
    244, // 89 - Y
    249, // 90 - Z
    254, // 91 - [
    259, // 92 - backslash
    264, // 93 - ]
    269, // 94 - ^
};

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

#include "draw_font_10narrow.h"

uns16  const font_10narrow_index[] PROGMEM = {

    0, // 32 -  
    3, // 33 - !
    4, // 34 - "
    7, // 35 - #
    12, // 36 - $
    17, // 37 - %
    22, // 38 - &
    27, // 39 - '
    28, // 40 - (
    30, // 41 - )
    32, // 42 - *
    37, // 43 - +
    42, // 44 - ,
    44, // 45 - -
    47, // 46 - .
    48, // 47 - /
    53, // 48 - 0
    57, // 49 - 1
    59, // 50 - 2
    63, // 51 - 3
    67, // 52 - 4
    72, // 53 - 5
    76, // 54 - 6
    80, // 55 - 7
    84, // 56 - 8
    88, // 57 - 9
    92, // 58 - :
    93, // 59 - ;
    95, // 60 - <
    99, // 61 - =
    102, // 62 - >
    106, // 63 - ?
    111, // 64 - @
    116, // 65 - A
    120, // 66 - B
    124, // 67 - C
    128, // 68 - D
    132, // 69 - E
    136, // 70 - F
    140, // 71 - G
    144, // 72 - H
    148, // 73 - I
    151, // 74 - J
    155, // 75 - K
    160, // 76 - L
    164, // 77 - M
    169, // 78 - N
    174, // 79 - O
    178, // 80 - P
    182, // 81 - Q
    187, // 82 - R
    191, // 83 - S
    195, // 84 - T
    200, // 85 - U
    204, // 86 - V
    209, // 87 - W
    214, // 88 - X
    219, // 89 - Y
    224, // 90 - Z
    229, // 91 - [
    231, // 92 - backslash
    236, // 93 - ]
    238, // 94 - ^
    238, // 95 - _
    242, // 96 - `

};
uns8  const font_10narrow_data[] PROGMEM = {

    // 0,  32 -
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//
//
//

    // 3,  33 - !
 0xbf, 0xc0,
// * ********

    // 4,  34 - "
 0x01, 0xc0, 0x00, 0x00, 0x01, 0xc0,
//        ***
//
//        ***

    // 7,  35 - #
 0x12, 0x00, 0x7f, 0x80, 0x12, 0x00, 0x7f, 0x80, 0x12, 0x00,
//    *  *
//  ********
//    *  *
//  ********
//    *  *

    // 12,  36 - $
 0x23, 0x00, 0x44, 0x80, 0xff, 0xc0, 0x44, 0x80, 0x39, 0x00,
//   *   **
//  *   *  *
// **********
//  *   *  *
//   ***  *

    // 17,  37 - %
 0x23, 0x00, 0x14, 0x80, 0x6b, 0x00, 0x94, 0x00, 0x62, 0x00,
//   *   **
//    * *  *
//  ** * **
// *  * *
//  **   *

    // 22,  38 - &
 0x7b, 0x80, 0x8c, 0x40, 0x92, 0x40, 0x61, 0x80, 0x50, 0x00,
//  **** ***
// *   **   *
// *  *  *  *
//  **    **
//  * *

    // 27,  39 - '
 0x01, 0xc0,
//        ***

    // 28,  40 - (
 0x7f, 0x80, 0x80, 0x40,
//  ********
// *        *

    // 30,  41 - )
 0x80, 0x40, 0x7f, 0x80,
// *        *
//  ********

    // 32,  42 - *
 0x15, 0x00, 0x0e, 0x00, 0x1f, 0x00, 0x0e, 0x00, 0x15, 0x00,
//    * * *
//     ***
//    *****
//     ***
//    * * *

    // 37,  43 - +
 0x04, 0x00, 0x04, 0x00, 0x1f, 0x00, 0x04, 0x00, 0x04, 0x00,
//      *
//      *
//    *****
//      *
//      *

    // 42,  44 - ,
 0x80, 0x00, 0x60, 0x00,
// *
//  **

    // 44,  45 - -
 0x04, 0x00, 0x04, 0x00, 0x04, 0x00,
//      *
//      *
//      *

    // 47,  46 - .
 0xc0, 0x00,
// **

    // 48,  47 - /
 0x10, 0x00, 0x08, 0x00, 0x04, 0x00, 0x02, 0x00, 0x01, 0x00,
//    *
//     *
//      *
//       *
//        *

    // 53,  48 - 0
 0x7f, 0x80, 0x80, 0x40, 0x80, 0x40, 0x7f, 0x80,
//  ********
// *        *
// *        *
//  ********

    // 57,  49 - 1
 0x00, 0x80, 0xff, 0xc0,
//         *
// **********

    // 59,  50 - 2
 0xf0, 0x80, 0x88, 0x40, 0x84, 0x40, 0x83, 0x80,
// ****    *
// *   *    *
// *    *   *
// *     ***

    // 63,  51 - 3
 0x40, 0x80, 0x84, 0x40, 0x84, 0x40, 0x7b, 0x80,
//  *      *
// *    *   *
// *    *   *
//  **** ***

    // 67,  52 - 4
 0x0e, 0x00, 0x09, 0x00, 0x08, 0x80, 0xff, 0xc0, 0x08, 0x00,
//     ***
//     *  *
//     *   *
// **********
//     *

    // 72,  53 - 5
 0x47, 0xc0, 0x84, 0x40, 0x84, 0x40, 0x78, 0x40,
//  *   *****
// *    *   *
// *    *   *
//  ****    *

    // 76,  54 - 6
 0x7f, 0x80, 0x84, 0x40, 0x84, 0x40, 0x78, 0x80,
//  ********
// *    *   *
// *    *   *
//  ****   *

    // 80,  55 - 7
 0x00, 0x40, 0xfc, 0x40, 0x02, 0x40, 0x01, 0xc0,
//          *
// ******   *
//       *  *
//        ***

    // 84,  56 - 8
 0x7b, 0x80, 0x84, 0x40, 0x84, 0x40, 0x7b, 0x80,
//  **** ***
// *    *   *
// *    *   *
//  **** ***

    // 88,  57 - 9
 0x47, 0x80, 0x88, 0x40, 0x88, 0x40, 0x7f, 0x80,
//  *   ****
// *   *    *
// *   *    *
//  ********

    // 92,  58 - :
 0x36, 0x00,
//   ** **

    // 93,  59 - ;
 0x80, 0x00, 0x68, 0x00,
// *
//  ** *

    // 95,  60 - <
 0x08, 0x00, 0x14, 0x00, 0x22, 0x00, 0x41, 0x00,
//     *
//    * *
//   *   *
//  *     *

    // 99,  61 - =
 0x0a, 0x00, 0x0a, 0x00, 0x0a, 0x00,
//     * *
//     * *
//     * *

    // 102,  62 - >
 0x41, 0x00, 0x22, 0x00, 0x14, 0x00, 0x08, 0x00,
//  *     *
//   *   *
//    * *
//     *

    // 106,  63 - ?
 0x01, 0x80, 0x00, 0x40, 0xd8, 0x40, 0x04, 0x40, 0x03, 0x80,
//        **
//          *
// ** **    *
//      *   *
//       ***

    // 111,  64 - @
 0x3f, 0x00, 0x40, 0x80, 0x5e, 0x80, 0x56, 0x80, 0x1f, 0x00,
//   ******
//  *      *
//  * **** *
//  * * ** *
//    *****

    // 116,  65 - A
 0xff, 0x80, 0x08, 0x40, 0x08, 0x40, 0xff, 0x80,
// *********
//     *    *
//     *    *
// *********

    // 120,  66 - B
 0xff, 0xc0, 0x84, 0x40, 0x84, 0x40, 0x7b, 0x80,
// **********
// *    *   *
// *    *   *
//  **** ***

    // 124,  67 - C
 0x7f, 0x80, 0x80, 0x40, 0x80, 0x40, 0x40, 0x80,
//  ********
// *        *
// *        *
//  *      *

    // 128,  68 - D
 0xff, 0xc0, 0x80, 0x40, 0x80, 0x40, 0x7f, 0x80,
// **********
// *        *
// *        *
//  ********

    // 132,  69 - E
 0xff, 0xc0, 0x84, 0x40, 0x84, 0x40, 0x80, 0x40,
// **********
// *    *   *
// *    *   *
// *        *

    // 136,  70 - F
 0xff, 0xc0, 0x04, 0x40, 0x04, 0x40, 0x00, 0x40,
// **********
//      *   *
//      *   *
//          *

    // 140,  71 - G
 0x7f, 0x80, 0x80, 0x40, 0x88, 0x40, 0xf8, 0x80,
//  ********
// *        *
// *   *    *
// *****   *

    // 144,  72 - H
 0xff, 0xc0, 0x04, 0x00, 0x04, 0x00, 0xff, 0xc0,
// **********
//      *
//      *
// **********

    // 148,  73 - I
 0x80, 0x40, 0xff, 0xc0, 0x80, 0x40,
// *        *
// **********
// *        *

    // 151,  74 - J
 0x40, 0x00, 0x80, 0x00, 0x80, 0x00, 0x7f, 0xc0,
//  *
// *
// *
//  *********

    // 155,  75 - K
 0xff, 0xc0, 0x0c, 0x00, 0x12, 0x00, 0x21, 0x00, 0xc0, 0xc0,
// **********
//     **
//    *  *
//   *    *
// **      **

    // 160,  76 - L
 0xff, 0xc0, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
// **********
// *
// *
// *

    // 164,  77 - M
 0xff, 0xc0, 0x00, 0x80, 0x03, 0x00, 0x00, 0x80, 0xff, 0xc0,
// **********
//         *
//       **
//         *
// **********

    // 169,  78 - N
 0xff, 0xc0, 0x02, 0x00, 0x04, 0x00, 0x08, 0x00, 0xff, 0xc0,
// **********
//       *
//      *
//     *
// **********

    // 174,  79 - O
 0x7f, 0x80, 0x80, 0x40, 0x80, 0x40, 0x7f, 0x80,
//  ********
// *        *
// *        *
//  ********

    // 178,  80 - P
 0xff, 0xc0, 0x04, 0x40, 0x04, 0x40, 0x03, 0x80,
// **********
//      *   *
//      *   *
//       ***

    // 182,  81 - Q
 0x7f, 0x80, 0x80, 0x40, 0xa0, 0x40, 0x40, 0x40, 0xbf, 0x80,
//  ********
// *        *
// * *      *
//  *       *
// * *******

    // 187,  82 - R
 0xff, 0xc0, 0x0c, 0x40, 0x14, 0x40, 0xe3, 0x80,
// **********
//     **   *
//    * *   *
// ***   ***

    // 191,  83 - S
 0x43, 0x80, 0x84, 0x40, 0x84, 0x40, 0x78, 0x80,
//  *    ***
// *    *   *
// *    *   *
//  ****   *

    // 195,  84 - T
 0x00, 0x40, 0x00, 0x40, 0xff, 0xc0, 0x00, 0x40, 0x00, 0x40,
//          *
//          *
// **********
//          *
//          *

    // 200,  85 - U
 0x7f, 0xc0, 0x80, 0x00, 0x80, 0x00, 0x7f, 0xc0,
//  *********
// *
// *
//  *********

    // 204,  86 - V
 0x3f, 0xc0, 0x40, 0x00, 0x80, 0x00, 0x40, 0x00, 0x3f, 0xc0,
//   ********
//  *
// *
//  *
//   ********

    // 209,  87 - W
 0xff, 0xc0, 0x40, 0x00, 0x30, 0x00, 0x40, 0x00, 0xff, 0xc0,
// **********
//  *
//   **
//  *
// **********

    // 214,  88 - X
 0xf1, 0xc0, 0x0a, 0x00, 0x04, 0x00, 0x0a, 0x00, 0xf1, 0xc0,
// ****   ***
//     * *
//      *
//     * *
// ****   ***

    // 219,  89 - Y
 0x01, 0xc0, 0x02, 0x00, 0xfc, 0x00, 0x02, 0x00, 0x01, 0xc0,
//        ***
//       *
// ******
//       *
//        ***

    // 224,  90 - Z
 0xf0, 0x40, 0x88, 0x40, 0x84, 0x40, 0x82, 0x40, 0x81, 0xc0,
// ****     *
// *   *    *
// *    *   *
// *     *  *
// *      ***

    // 229,  91 - [
 0xff, 0xc0, 0x80, 0x40,
// **********
// *        *

    // 231,  92 - backalsh
 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08, 0x00, 0x10, 0x00,
//        *
//       *
//      *
//     *
//    *

    // 236,  93 - ]
 0x80, 0x40, 0xff, 0xc0,
// *        *
// **********

    // 238,  94 - ^


    // 238,  95 - _
 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
// *
// *
// *
// *

};



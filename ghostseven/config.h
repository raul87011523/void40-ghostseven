/*
Copyright 2020 GhostSeven

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xF055    // VOID
#define PRODUCT_ID 0x3531   // VOID40
#define DEVICE_VER 0x0002
#define MANUFACTURER Victor Lucachi
#define PRODUCT VOID40GS
#define DESCRIPTION A handwired 40% 12x4 ortholinear keyboard GS ver

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { C6, D4, D0, D1 }
#define MATRIX_COL_PINS { E6, D7, B5, B4, F5, F4, F7, F6, B1, B3, B2, B6 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/*
 * Rotary Encoder Support
 */
#define ENCODERS_PAD_A { D2 }
#define ENCODERS_PAD_B { D3 }
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 10

#define FORCE_NKRO

/* disable these deprecated features by default */
#ifndef LINK_TIME_OPTIMIZATION_ENABLE
  #define NO_ACTION_MACRO
  #define NO_ACTION_FUNCTION
#endif

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

//Mouse config.
//Define                             Default         Description
#define MK_3_SPEED                   //Not defined   Enable constant cursor speeds
#define MK_MOMENTARY_ACCEL           //Not defined   Enable momentary speed selection
//#define MK_C_OFFSET_UNMOD          //  16          Cursor offset per movement (unmodified)
//#define MK_C_INTERVAL_UNMOD        //  16          Time between cursor movements (unmodified)
//#define MK_C_OFFSET_0              //   1          Cursor offset per movement (KC_ACL0)
//#define MK_C_INTERVAL_0            //  32          Time between cursor movements (KC_ACL0)
//#define MK_C_OFFSET_1              //   4          Cursor offset per movement (KC_ACL1)
//#define MK_C_INTERVAL_1            //  16          Time between cursor movements (KC_ACL1)
//#define MK_C_OFFSET_2              //  32          Cursor offset per movement (KC_ACL2)
//#define MK_C_INTERVAL_2            //  16          Time between cursor movements (KC_ACL2)
//#define MK_W_OFFSET_UNMOD          //   1          Scroll steps per scroll action (unmodified)
//#define MK_W_INTERVAL_UNMOD        //  40          Time between scroll steps (unmodified)
//#define MK_W_OFFSET_0              //   1          Scroll steps per scroll action (KC_ACL0)
//#define MK_W_INTERVAL_0            // 360          Time between scroll steps (KC_ACL0)
//#define MK_W_OFFSET_1              //   1          Scroll steps per scroll action (KC_ACL1)
//#define MK_W_INTERVAL_1            // 120          Time between scroll steps (KC_ACL1)
//#define MK_W_OFFSET_2              //   1          Scroll steps per scroll action (KC_ACL2)
//#define MK_W_INTERVAL_2            //  20          Time between scroll steps (KC_ACL2)

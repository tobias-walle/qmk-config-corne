/* Copyright 2022 @toinux
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */


#include QMK_KEYBOARD_H
#include "keycodes.h"

#define RGB_WORKING_WHITE  30, 30, 30

static const char lower_leds[] = {
    24,  23,  18,  17,  10,   9,
    25,  22,  19, /*16,*/ 11, // 8,
    26,/*21,*/ 20,  15,  12,  // 7,
                         14,  13,  6,
    51,  50,  45,  44,  37,  36,
    52,  49,  46,  43, // 38,  35,
    // 53,  48,  47,  42,  39,  34,
                        41,  40,  33 
};

static const char raise_leds[] = {
    24,  23,  18,  17,  10,   9,
    25, // 22,  19,  16,  11,   8,
    26, // 21,  20,  15,  12,   7,
                         14,  13,  6,
    51,  50,  45,  44,  37,  36,
    52,  49,  46,  43,  38,  35,
    53,  48,  47,  42,  39,  34,
                        41,  40,  33 
};

static const char gaming_leds[] = {
    24,  23,  18,  17,  10,   9,
    25,  22,  19,  16,  11,   8,
    // 26, 21,  20,  15,  12,  7,
                       /*14,*/ 13,/*6,*/
    // 51,  50,  45,  44,  37,  36,
    /* 52,  49,  46,  43,*/  38,  35,
    53, // 48,  47,  42,  39,  34,
                       /*41,*/ 40, 33
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _BASE:
            rgb_matrix_set_color_all(RGB_WORKING_WHITE);
            break;
        case _LOWER:
            for (uint8_t i = 0; i < 30; i++) {
                rgb_matrix_set_color(lower_leds[i], RGB_GREEN);
            }
            break;
        case _RAISE:
            for (uint8_t i = 0; i < 32; i++) {
                rgb_matrix_set_color(raise_leds[i], RGB_BLUE);
            }
            break;
        case _GAMING:
            for (uint8_t i = 0; i < 18; i++) {
                rgb_matrix_set_color(gaming_leds[i], RGB_RED);
            }
            break;
    } return false;
}

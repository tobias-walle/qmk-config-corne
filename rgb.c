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

void rgb_matrix_sethsv_at(uint8_t led, uint8_t h, uint8_t s, uint8_t v) {
  HSV hsv = {h, s, v};
  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    int saturation = 150;
    int brightness = 50;
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _BASE:
            rgb_matrix_sethsv(100, saturation, brightness);
            break;
        case _LOWER:
            rgb_matrix_sethsv(50, saturation, brightness);
            break;
        case _RAISE:
            rgb_matrix_sethsv(150, saturation, brightness);
            break;
        case _META:
            rgb_matrix_sethsv( 0, 0, 10);
            break;
    };
    /* rgb_matrix_sethsv_at(5, 0, saturation, 255); */
    return false;
}

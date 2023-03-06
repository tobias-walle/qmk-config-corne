#include QMK_KEYBOARD_H
#include "keycodes.h"

void rgb_matrix_sethsv_at(uint8_t led, uint8_t h, uint8_t s, uint8_t v) {
  HSV hsv = {h, s, v};
  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
}

void set_board_colors_side(uint8_t offset, uint8_t h, uint8_t s, uint8_t v) {
  for(int i = 0; i < 24; i++) {
    uint8_t led = i + offset + 6;
    if (led > 0) {
      uint8_t x = i / 4 * 10;
      rgb_matrix_sethsv_at(led, h + x, s, v);
    }
  }
  // Backlight
  for(int i = 0; i < 6; i++) {
    uint8_t led = i + offset;
      rgb_matrix_sethsv_at(led, h - 100, 255, 180);
  }
}

void set_board_colors(uint8_t h, uint8_t s, uint8_t v) {
  // Left
  set_board_colors_side(0, h, s, v);
  // Right
  set_board_colors_side(27, h, s, v);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    int saturation = 180;
    int brightness = 50;
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _BASE:
            set_board_colors(100, saturation, brightness);
            break;
        case _LOWER:
            set_board_colors(50, saturation, brightness);
            break;
        case _RAISE:
            set_board_colors(150, saturation, brightness);
            break;
        case _META:
            rgb_matrix_sethsv(0, 0, 10);
            break;
    };
    /* rgb_matrix_sethsv_at(5, 0, saturation, 255); */
    return false;
}

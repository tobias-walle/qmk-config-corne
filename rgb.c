#include QMK_KEYBOARD_H
#include "keycodes.h"

void rgb_matrix_sethsv_at(uint8_t led, uint8_t h, uint8_t s, uint8_t v) {
  HSV hsv = {h, s, v};
  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
}

void set_board_colors_side(uint8_t offset, uint8_t hue, uint8_t hue_backglow) {
  int brightness = 90;

  // Keys
  int saturation = 180;
  for(int i = 0; i < 24; i++) {
    uint8_t led = i + offset + 6;
    if (led > 0) {
      uint8_t x = i / 4 * 7;
      rgb_matrix_sethsv_at(led, hue + x, saturation, brightness);
    }
  }

  // Backglow
  for(int i = 0; i < 6; i++) {
    uint8_t led = i + offset;
    rgb_matrix_sethsv_at(led, hue_backglow, 255, brightness + 120);
  }
}

void set_board_colors(uint8_t hue, uint8_t hue_backglow) {
  // Left
  set_board_colors_side(0, hue, hue_backglow);
  // Right
  set_board_colors_side(27, hue, hue_backglow);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _LOWER:
            set_board_colors(70, 180);
            break;
        case _BASE:
            set_board_colors(100, 5);
            break;
        case _RAISE:
            set_board_colors(150, 50);
            break;
        case _META:
            rgb_matrix_sethsv(0, 0, 10);
            break;
    };
    return false;
}

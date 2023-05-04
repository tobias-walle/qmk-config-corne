/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keycodes.h"

enum custom_keycodes {
  TMUX_P = SAFE_RANGE, // Tmux prefix
  TMUX_P_N, // Tmux select session
  TMUX_NXT, // Tmux next window
  TMUX_PRV, // Tmux previous window
  CTL_U,
  CTL_D,
};

// Keymap aliase
// -- Left
#define AL_A   LALT_T(KC_A)
#define AL_S   LCTL_T(KC_S)
#define AL_D   LGUI_T(KC_D)
#define AL_F   LSG_T(KC_F)
#define AL_V   RCS_T(KC_V)
#define AL_R   LSA_T(KC_R)
#define AL_G   LCAG_T(KC_G)
#define AL_B   KC_B
#define AL_T   KC_T
// -- Right
#define AL_QT  RALT_T(KC_QUOT)
#define AL_L   RCTL_T(KC_L)
#define AL_K   RGUI_T(KC_K)
#define AL_J   RSG_T(KC_J)
#define AL_M   RCS_T(KC_M)
#define AL_U   RSA_T(KC_U)
#define AL_H   LCAG_T(KC_H)
#define AL_N   KC_N
#define AL_Y   KC_Y
// -- Thumb
#define AL_ESC LT(_RAISE, KC_ESC)
#define AL_TAB LT(_LOWER, KC_TAB)
#define AL_ENT LSFT_T(KC_ENT)
#define AL_SPC RSFT_T(KC_SPC)
#define AL_BPC LT(_LOWER, KC_BSPC)
#define AL_DEL LT(_RAISE, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
       XXXXXXX,    KC_Q,    KC_W,    KC_E,    AL_R,   AL_T,                        AL_Y,    AL_U,    KC_I,    KC_O,   KC_P,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_HYPR,    AL_A,    AL_S,    AL_D,    AL_F,   AL_G,                        AL_H,    AL_J,    AL_K,    AL_L,   AL_QT,  KC_HYPR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,    KC_Z,    KC_X,    KC_C,    AL_V,   AL_B,                        AL_N,    AL_M, KC_COMM,  KC_DOT, KC_QUES,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            AL_ESC, AL_TAB,  AL_ENT,     AL_SPC, AL_BPC,  AL_DEL
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_0,    KC_1,    KC_2,    KC_3,    KC_4,                         KC_5,    KC_6,    KC_7,    KC_8,    KC_9, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+
      _______, KC_SLSH, KC_PAST, KC_MINS,  KC_EQL, KC_PERC,                       KC_DLR, KC_SCLN, KC_EXLM, KC_PIPE,  KC_GRV, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+
      _______, KC_TILD, KC_AMPR, KC_UNDS, KC_PLUS,   KC_AT,                      KC_HASH, KC_COLN, KC_CIRC, KC_BSLS,  TMUX_P, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             META, _______, _______,    _______, _______,    META
                                    //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+
      _______, _______, TMUX_P_N, KC_PGUP, CTL_U, KC_HOME,                       KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  KC_F11, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+
      _______, _______, _______,  KC_PGDN, CTL_D,  KC_END,                      TMUX_PRV,TMUX_NXT, _______, _______,  KC_F12, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             META, _______, _______,    _______, _______,    META
                                      //`--------------------------'  `--------------------------'
  ),

  [_META] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, KC_MNXT, KC_VOLU, XXXXXXX,                      XXXXXXX, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+
      _______, XXXXXXX, XXXXXXX, KC_MPLY, KC_MUTE, XXXXXXX,                      XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+
      _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, XXXXXXX,                      XXXXXXX, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

const uint16_t PROGMEM combo_1[] = {AL_J, AL_K, COMBO_END};
const uint16_t PROGMEM combo_2[] = {AL_R, AL_T, COMBO_END};
const uint16_t PROGMEM combo_3[] = {AL_Y, AL_U, COMBO_END};
const uint16_t PROGMEM combo_4[] = {AL_F, AL_G, COMBO_END};
const uint16_t PROGMEM combo_5[] = {AL_H, AL_J, COMBO_END};
const uint16_t PROGMEM combo_6[] = {AL_V, AL_B, COMBO_END};
const uint16_t PROGMEM combo_7[] = {AL_N, AL_M, COMBO_END};
const uint16_t PROGMEM combo_8[] = {KC_C, AL_V, COMBO_END};
const uint16_t PROGMEM combo_9[] = {AL_M, KC_COMM, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_1, KC_ESC),
    COMBO(combo_2, KC_LCBR),
    COMBO(combo_3, KC_RCBR),
    COMBO(combo_4, KC_LBRC),
    COMBO(combo_5, KC_RBRC),
    COMBO(combo_6, KC_LPRN),
    COMBO(combo_7, KC_RPRN),
    COMBO(combo_8, KC_LT),
    COMBO(combo_9, KC_GT),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case TMUX_P: {
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a"));
      }
      return false;
    }
    case TMUX_P_N: {
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("an") );
      }
      return false;
    }
    case TMUX_NXT: {
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") "n");
      }
      return false;
    }
    case TMUX_PRV: {
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") "p");
      }
      return false;
    }
    case CTL_U: {
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("u") );
      }
      return false;
    }
    case CTL_D: {
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("d") );
      }
      return false;
    }
  }
  return true;
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM meta_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_META)) {
        oled_write_P(meta_layer, false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

bool oled_task_user(void) {
    // Renders the current keyboard state (layers and mods)
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    return false;
}

#endif

void keyboard_post_init_user(void) {
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
#endif
}

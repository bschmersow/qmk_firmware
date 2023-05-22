// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "rgblight.h"



// Defines names for use in layer keycodes and the keymap
enum layer_names {
	_KOY,
	_NEOL3,
	_NEOL4,
    _SYS,
    _QWERTZ
};

// LAYOUT_ortho_7x5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_KOY] = LAYOUT_ortho_5x7(
        KC_ESC,           KC_1,            KC_2,            KC_3,            KC_4,                      KC_5,            KC_6,
        KC_TAB,           KC_K,            KC_DOT,          KC_O,            KC_Y,                      RALT(KC_Y),      KC_ENTER,
        LSFT_T(KC_ENTER), KC_H,            KC_A,            KC_E,            KC_I,                      KC_U,            MO(_SYS),
        KC_MEH,           KC_X,            KC_Q,            KC_F,            KC_COMM,                   RALT(KC_Q),      LCTL(KC_S),
        KC_LCTL,          KC_LWIN,         TO(_NEOL4),      KC_LALT,         MO(_NEOL3),                KC_SPC,          MO(_NEOL4)
    ),
    [_NEOL3] = LAYOUT_ortho_5x7(
        KC_ESC,           KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,           KC_F6,
        KC_TAB,           KC_EQL,          KC_UNDS,         KC_LBRC,         KC_RBRC,         KC_CIRC,         LCTL(KC_H),
        KC_LSFT,          KC_BSLS,         KC_SLSH,         KC_LCBR,         KC_RCBR,         KC_ASTR,         MO(_SYS),
        KC_LSFT,          KC_HASH,         KC_DLR,          KC_PIPE,         KC_TILD,         KC_QUOT,         LCTL(KC_F),
        KC_LCTL,          KC_LWIN,         KC_TRNS,         KC_LALT,         KC_TRNS,         KC_SPC,          KC_TRNS
    ),
    [_NEOL4] = LAYOUT_ortho_5x7(
        KC_ESC,           KC_F12,          KC_F13,          KC_F14,          KC_F15,          MI_C4,           MI_Cs4,
        KC_TAB,           KC_PGUP,         KC_BSPC,         KC_UP,           KC_DEL,          KC_PGDN,         KC_ENTER,
        KC_LSFT,          LCTL(KC_LEFT),   KC_LEFT,         KC_DOWN,         KC_RIGHT,        LCTL(KC_RIGHT),  MO(_SYS),
        KC_HOME,          LCTL(KC_Z),      LCTL(KC_X),      LCTL(KC_C),      LCTL(KC_V),      LCTL(KC_Y),      KC_END,
        KC_LCTL,          KC_LWIN,         TO(_KOY),       KC_LALT,         KC_TRNS,         KC_SPC,          MO(_NEOL4)
    ),
    [_SYS] = LAYOUT_ortho_5x7(
        QK_BOOTLOADER,    LCTL(KC_PWR),    KC_NO,                KC_MSTP,         KC_MPLY,           KC_VOLD,        KC_VOLU,
        TO(_QWERTZ),      KC_NO,           RGB_MODE_BREATHE,    RGB_VAI,         RGB_MODE_RAINBOW,  RGB_TOG,        KC_CALC,
        KC_CAPS,          KC_NO,           RGB_HUD,             RGB_VAD,         RGB_HUI,           KC_MNXT,        MO(_SYS),
        KC_LSFT,          KC_NO,           KC_NO,              KC_WBAK,          KC_WFWD,             KC_MPRV,       KC_PAUS,
        QK_REBOOT,        KC_LWIN,         KC_TRNS,             KC_LALT,         KC_TRNS,            KC_SPC,        MO(_NEOL4)
    ),
    [_QWERTZ] = LAYOUT_ortho_5x7(
        KC_ESC,           KC_1,            KC_2,            KC_3,            KC_4,            KC_5,            KC_6,
        KC_TAB,           KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,            KC_ENTER,
        KC_LSFT,          KC_A,            KC_S,            KC_D,            KC_F,            KC_G,            MO(_SYS),
        KC_LSFT,          KC_Y,            KC_X,            KC_C,            KC_V,            KC_B,            KC_PSCR,
        KC_LCTL,          KC_LWIN,         TO(_NEOL4),         KC_LALT,     MO(_NEOL3),      KC_SPC,          MO(_NEOL4)
    ),
};

//RALT(KC_Q) // for ä at position a
//RALT(KC_S) // for ß at position s
//RALT(KC_Y) // for ü at position u
//RALT(KC_P) // for ö at position o

#define COL_KOY    HSV_TEAL
#define COL_NL3     HSV_BLUE
#define COL_NL4     HSV_PURPLE
#define COL_NUMLOCK HSV_GOLD
#define COL_SYS     HSV_RED
#define COL_QWERT   HSV_GREEN

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO(_NEOL4):
            if (record->event.pressed) {
                // MO_LAYER key pressed
                rgblight_sethsv(COL_NL4);
            } else {
                rgblight_sethsv(COL_KOY);
            }
            return true;
        case MO(_SYS):
            if (record->event.pressed) {
                rgblight_sethsv(COL_SYS);
            } else {
                rgblight_sethsv(COL_KOY);
            }
            return true;
        case MO(_NEOL3):
            if (record->event.pressed) {
                rgblight_sethsv(COL_NL3);
            } else {
                rgblight_sethsv(COL_KOY);
            }
            return true;
        case TO(_NEOL4):
            if (record->event.pressed) {
                rgblight_sethsv(COL_NL4);
            } 
            return true;
        case KC_NUM:
            if (record->event.pressed) {
                led_t led_state = host_keyboard_led_state();
                if (led_state.num_lock) {
                    // Num Lock is on
                    rgblight_sethsv(COL_NUMLOCK);
                } else {
                    // Num Lock is off
                    rgblight_sethsv(COL_NL4);
                }
            }
            return true;
        case TO(_KOY):
            if (record->event.pressed) {
                rgblight_sethsv(COL_KOY);
            } 
            return true;
        default:
            return true; // Process all other keycodes normally
    }
    return true;
}

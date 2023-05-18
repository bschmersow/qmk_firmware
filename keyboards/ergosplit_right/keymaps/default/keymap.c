// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
	_BASE,
	_FN1,
};

// LAYOUT_ortho_7x5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_5x7(
        KC_6,           KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS,   KC_EQL,
        KC_T,           KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,      KC_LBRC,
        KC_G,           KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,   KC_QUOT,
        KC_N,           KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  TO(_FN1),  KC_UP,
        MO(_FN1),       KC_SPC,  KC_SPC,  KC_LGUI,  KC_LEFT,   KC_DOWN,
    ),
};

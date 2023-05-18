// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
	_BASE,
	_NEOL3,
	_NEOL4,
    _SYS
};

// LAYOUT_ortho_7x5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_5x7(
                QK_BOOTLOADER,  KC_6,   KC_7,    KC_8,    KC_9,     KC_0,     KC_BACKSPACE,
                KC_ENTER,       KC_Z,   KC_U,    KC_I,     KC_O,     KC_P,         RALT(KC_Y),
                KC_DEL,       KC_H,   KC_J,    KC_K,     KC_L,     RALT(KC_P),   RALT(KC_Q),
    MO(_SYS), KC_DEL,            KC_DOT,   KC_SLSH,  KC_M,  KC_2, KC_RSFT,
    MO(_NEOL3), KC_SPC,         TO(_NEOL4),  KC_RALT,  KC_LEFT,   KC_DOWN,
    ),
    [_NEOL3] = LAYOUT_ortho_5x7(
                QK_BOOTLOADER,  KC_6,       KC_7,    KC_8,    KC_9,     KC_0,     KC_BACKSPACE,
        KC_T,           KC_Z,    KC_U,      KC_I,     KC_O,     KC_P,         RALT(KC_Y),
        KC_G,           KC_H,    KC_LBRC,    KC_RBRC,     KC_L,     RALT(KC_P),   RALT(KC_Q),
        TO(_NEOL4),           KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MO(_NEOL3),       KC_SPC, TO(_NEOL4),  KC_LGUI,  KC_LEFT,   KC_DOWN,
    ),
    [_NEOL4] = LAYOUT_ortho_5x7(
                QK_BOOTLOADER,      KC_6, KC_7,    KC_8,    KC_9,     KC_0,     KC_BACKSPACE,
        KC_T,           KC_Z,       KC_P7,    KC_P8,     KC_P9,     KC_P,         RALT(KC_Y),
        KC_G,           KC_H,       KC_P4,    KC_P5,     KC_P6,     RALT(KC_P),   RALT(KC_Q),
        KC_N,           KC_M,       KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MO(_NEOL3),       KC_SPC,   TO(_BASE),  KC_LGUI,  KC_LEFT,   KC_DOWN,
    ),
    [_SYS] = LAYOUT_ortho_5x7(
        QK_BACKLIGHT_TOGGLE,      KC_6, KC_7,    KC_8,    KC_9,     KC_0,     QK_BOOTLOADER,
        QK_REBOOT,       KC_NO,       KC_P7,    QK_BACKLIGHT_UP,     KC_P9,     KC_P,         RALT(KC_Y),
        KC_NO,           KC_NO,       KC_P4,    QK_BACKLIGHT_DOWN,     KC_P6,     RALT(KC_P),   RALT(KC_Q),
        MO(_SYS),        KC_NO,       KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MO(_NEOL3),       KC_SPC,   TO(_NEOL4),  KC_LGUI,  KC_LEFT,   KC_DOWN,
    )
};

//RALT(KC_Q) // for ä at position a
//RALT(KC_S) // for ß at position s
//RALT(KC_Y) // for ü at position u
//RALT(KC_P) // for ö at position o

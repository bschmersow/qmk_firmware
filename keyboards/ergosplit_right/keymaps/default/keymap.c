// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "rgblight.h"


// Defines names for use in layer keycodes and the keymap
enum layer_names {
	_BASE,
	_NEOL3,
	_NEOL4,
    _SYS,
    _QWERT
};

// LAYOUT_ortho_7x5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_5x7(
            TO(_NEOL4),         KC_7,       KC_8,                       KC_9,           KC_0,     RALT(KC_S),     KC_BACKSPACE,
            KC_ENTER,           KC_W,       KC_B,                       KC_L,           KC_Y,     KC_J,           RALT(KC_Y),
            KC_DEL,             KC_M,       KC_N,                       KC_T,           KC_R,    KC_O,            RSFT_T(KC_ENTER),
            MO(_SYS),           KC_P,       KC_H,                       KC_COMM,        KC_DOT,   KC_K,           KC_MEH,
            MO(_NEOL3),         KC_SPC,     MO(_NEOL4),                 KC_RALT,        KC_RWIN,  TO(_NEOL4),     KC_RCTL
    ),
    [_NEOL3] = LAYOUT_ortho_5x7(
            TO(_NEOL4),         KC_F7,      KC_F8,          KC_F9,    KC_F10,   KC_GRV,     KC_BACKSPACE,
            KC_ENTER,           KC_EXLM,    KC_LT,          KC_GT,    KC_EQL,   KC_AMPR,        KC_PLUS,
            KC_DEL,             KC_QUES,    KC_LPRN,        KC_RPRN,  KC_MINS,  KC_COLN,        KC_AT,
            KC_NO,              KC_PLUS,    KC_PERC,        KC_DQT,   KC_QUOT,  KC_SCLN,        KC_RSFT,
            MO(_NEOL3),         KC_SPC,     MO(_NEOL4),     KC_RALT,  KC_RWIN,  TO(_NEOL4),     KC_RCTL
    ),
    [_NEOL4] = LAYOUT_ortho_5x7(
            KC_NUM,            KC_F19,     KC_F20,          KC_PSLS,  KC_PAST,  KC_MINS,         KC_BACKSPACE,
            KC_PENT,            KC_Z,       KC_P7,          KC_P8,    KC_P9,    KC_PPLS,        KC_PMNS,
            KC_DEL,             KC_H,       KC_P4,          KC_P5,    KC_P6,    KC_COMM,        KC_PDOT,
            QK_MIDI_SUSTAIN,    MI_LEG,     KC_P1,          KC_P2,    KC_P3,    KC_SCLN,        KC_UP,
            TO(_BASE),          KC_SPC,     MO(_NEOL4),     KC_RALT,  KC_LEFT,  TO(_BASE),      KC_RCTL
    ),
    [_SYS] = LAYOUT_ortho_5x7(
            QK_BOOTLOADER,      KC_INT1,    KC_INT2,        KC_PSLS,  KC_PAST,  KC_MINS,        QK_BOOTLOADER,
            TO(_QWERT),         KC_Z,       KC_P7,          KC_P8,    KC_P9,    KC_PPLS,        KC_PMNS,
            KC_DEL,             DT_UP,      KC_P4,          KC_P5,    KC_P6,    KC_COMM,        QK_UNICODE_MODE_WINDOWS,
            MO(_SYS),           DT_DOWN,    KC_P1,          KC_P2,    KC_P3,    KC_SCLN,        KC_UP,
            MO(_NEOL3),         KC_SPC,     TO(_BASE),      KC_RALT,  KC_LEFT,  KC_NUM,         QK_REBOOT
    ),
    [_QWERT] = LAYOUT_ortho_5x7(
            TO(_NEOL4),         KC_7,       KC_8,           KC_9,     KC_0,     RALT(KC_S),     KC_BACKSPACE,
            KC_ENTER,           KC_Z,       KC_U,           KC_I,     KC_O,     KC_P,           RALT(KC_Y),
            KC_DEL,             KC_H,       KC_J,           KC_K,     KC_L,     RALT(KC_P),     RALT(KC_Q),
            MO(_SYS),           KC_N,       KC_M,           KC_COMM,  KC_DOT,   KC_SCLN,        KC_RSFT,
            MO(_NEOL3),         KC_SPC,     MO(_NEOL4),     KC_RALT,  KC_RWIN,  TO(_NEOL4),     KC_RCTL
    )
};

//RALT(KC_Q) // for ä at position a
//RALT(KC_S) // for ß at position s
//RALT(KC_Y) // for ü at position u
//RALT(KC_P) // for ö at position o

#define COL_BASE    HSV_TEAL
#define COL_NL3     HSV_BLUE
#define COL_NL4     HSV_PURPLE
#define COL_NUMLOCK HSV_GOLD
#define COL_SYS     HSV_RED
#define COL_QWERT   HSV_GREEN

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_sethsv(COL_BASE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO(_NEOL4):
            if (record->event.pressed) {
                // MO_LAYER key pressed
                rgblight_sethsv(COL_NL4);
            } else {
                rgblight_sethsv(COL_BASE);
            }
            return true;
        case MO(_SYS):
            if (record->event.pressed) {
                rgblight_sethsv(COL_SYS);
            } else {
                rgblight_sethsv(COL_BASE);
            }
            return true;
        case MO(_NEOL3):
            if (record->event.pressed) {
                rgblight_sethsv(COL_NL3);
            } else {
                rgblight_sethsv(COL_BASE);
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
        case TO(_BASE):
            if (record->event.pressed) {
                rgblight_sethsv(COL_BASE);
            } 
            return true;
        default:
            return true; // Process all other keycodes normally
    }
    return true;
}
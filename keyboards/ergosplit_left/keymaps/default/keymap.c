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
    _SYS
};

// LAYOUT_ortho_7x5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_5x7(
        KC_ESC,           KC_0,            KC_1,            KC_2,            KC_3,            KC_4,            KC_5,
        KC_TAB,           KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,            KC_ENTER,
        TO(_NEOL4),       KC_A,            KC_S,            KC_D,            KC_F,            KC_G,            MO(_SYS),
        KC_LSFT,          KC_Y,            KC_X,            KC_C,            KC_V,            KC_B,            KC_NO,
        KC_LCTL,          KC_NO,           KC_NO,           KC_LALT,           MO(_NEOL4),      KC_SPC,          MO(_NEOL3)
    ),
    [_NEOL3] = LAYOUT_ortho_5x7(
        KC_ESC,           KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,           KC_F6,
        KC_TAB,           KC_Z,            KC_MINS,         KC_RBRC,         KC_RBRC,         KC_CIRC,         KC_EXLM,
        TO(_NEOL4),       KC_BSLS,         KC_SLSH,         KC_LCBR,         KC_RCBR,         KC_ASTR,         KC_QUES,
        KC_LSFT,          KC_HASH,         KC_DLR,         KC_PIPE,          KC_TILD,         KC_RSFT,         KC_UP,
        KC_LCTL,          KC_NO,           KC_NO,           KC_LALT,         MO(_NEOL4),      KC_SPC,          MO(_NEOL3)
    ),
    [_NEOL4] = LAYOUT_ortho_5x7(
        KC_ESC,           KC_6,            KC_7,            KC_8,            KC_9,            KC_0,            KC_BACKSPACE,
        KC_TAB,           KC_PGUP,         KC_BSPC,         KC_UP,           KC_DEL,          KC_PGDN,       KC_P,
        TO(_BASE),        LCTL(KC_LEFT),   KC_LEFT,         KC_DOWN,         KC_RIGHT,        LCTL(KC_RIGHT),  RALT(KC_Q),
        KC_N,             KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_RSFT,         KC_UP,
        KC_LCTL,          KC_NO,           KC_LALT,         KC_NO,           MO(_NEOL4),      KC_SPC,          MO(_NEOL3)
    ),
    [_SYS] = LAYOUT_ortho_5x7(
        QK_BOOTLOADER,    KC_0,            KC_1,            KC_2,            KC_3,            KC_4,            KC_5,
        KC_TAB,           KC_Q,            RGB_MODE_BREATHE, RGB_VAI,         RGB_MODE_RAINBOW, KC_T,            RGB_TOG,
        TO(_NEOL4),       KC_A,            RGB_HUD,           RGB_VAD,          RGB_HUI,            KC_G,            MO(_SYS), //quad btn up right
        KC_LSFT,          KC_Y,            KC_X,            KC_C,            KC_V,            KC_B,            KC_NO,
        QK_REBOOT,          KC_NO,           KC_LALT,         KC_NO,           MO(_NEOL4),      KC_SPC,          MO(_NEOL3)
    )
};

//RALT(KC_Q) // for ä at position a
//RALT(KC_S) // for ß at position s
//RALT(KC_Y) // for ü at position u
//RALT(KC_P) // for ö at position o



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
        case KC_LSFT:
            if (record->event.pressed) {
                // Shift key pressed
                rgblight_setrgb(RGB_AZURE);; // Change to breathing mode
            } else {
                // Shift key released
                rgblight_setrgb(RGB_TEAL);; // Change to static mode
            }
            return false; // Skip all further processing of this key
        case MO(_NEOL4):
            if (record->event.pressed) {
                // Shift key pressed
                rgblight_setrgb(RGB_ORANGE);; // Change to breathing mode
            } else {
                // Shift key released
                rgblight_setrgb(RGB_TEAL);; // Change to static mode
            }
            return false; // Skip all further processing of this key
        default:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            return true; // Process all other keycodes normally
    }
}

// // Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {9, 2, HSV_CYAN}
// );
// // Light LEDs 11 & 12 in purple when keyboard layer 2 is active
// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {11, 2, HSV_PURPLE}
// );
// // Light LEDs 13 & 14 in green when keyboard layer 3 is active
// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {13, 2, HSV_GREEN}
// );
// // Light LEDs 13 & 14 in green when keyboard layer 3 is active
// const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 10, HSV_RED}
// );


// // Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_layer1_layer,    // Overrides caps lock layer
//     my_layer2_layer,    // Overrides other layers
//     my_layer3_layer     // Overrides other layers
// );

// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;
// }


// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(1, layer_state_cmp(state, _BASE));
//     return state;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(2, layer_state_cmp(state, _NEOL3));
//     rgblight_set_layer_state(3, layer_state_cmp(state, _NEOL4));
//     rgblight_set_layer_state(4, layer_state_cmp(state, _SYS));
//     return state;
// }


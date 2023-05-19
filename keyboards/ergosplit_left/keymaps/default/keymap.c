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
        KC_ESC,           KC_1,            KC_2,            KC_3,            KC_4,            KC_5,            KC_6,
        KC_TAB,           KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,            KC_ENTER,
        LCA_T(KC_BTN1),   KC_A,            KC_S,            KC_D,            KC_F,            KC_G,            MO(_SYS),
        KC_LSFT,          KC_Y,            KC_X,            KC_C,            KC_V,            KC_B,            KC_PSCR,
        KC_LCTL,          KC_LWIN,         TO(_NEOL4),         KC_LALT,      MO(_NEOL4),      KC_SPC,          MO(_NEOL3)
    ),
    [_NEOL3] = LAYOUT_ortho_5x7(
        KC_ESC,           KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,           KC_F6,
        KC_TAB,           KC_Z,            KC_MINS,         KC_LBRC,         KC_RBRC,         KC_CIRC,         KC_ENTER,
        LCA_T(KC_BTN1),   KC_BSLS,         KC_SLSH,         KC_LCBR,         KC_RCBR,         KC_ASTR,         MO(_SYS),
        KC_LSFT,          KC_HASH,         KC_DLR,          KC_PIPE,         KC_TILD,         KC_QUOT,         LCTL(KC_H),
        KC_LCTL,          KC_LWIN,         KC_TRNS,         KC_LALT,         KC_TRNS,         KC_SPC,          KC_TRNS
    ),
    [_NEOL4] = LAYOUT_ortho_5x7(
        KC_ESC,           KC_F12,          KC_F13,          KC_F14,          KC_F15,          MI_C4,           MI_Cs4,
        KC_TAB,           KC_PGUP,         KC_BSPC,         KC_UP,           KC_DEL,          KC_PGDN,         KC_ENTER,
        KC_HOME,          LCTL(KC_LEFT),   KC_LEFT,         KC_DOWN,         KC_RIGHT,        LCTL(KC_RIGHT),  MO(_SYS),
        KC_LSFT,          KC_WBAK,         LCTL(KC_X),      LCTL(KC_C),      LCTL(KC_V),     KC_WFWD,         KC_END,
        KC_LCTL,          KC_LWIN,         TO(_BASE),       KC_LALT,         KC_TRNS,        KC_SPC,           MO(_NEOL3)
    ),
    [_SYS] = LAYOUT_ortho_5x7(
        QK_BOOTLOADER,    KC_NO,           KC_NO,                KC_MSTP,         KC_MPLY,           KC_VOLD,        KC_VOLU,
        KC_TAB,           KC_NO,           RGB_MODE_BREATHE,    RGB_VAI,         RGB_MODE_RAINBOW,  RGB_TOG,        KC_CALC,
        KC_NO,            KC_NO,           RGB_HUD,             RGB_VAD,         RGB_HUI,           KC_MNXT,        MO(_SYS),
        KC_LSFT,          KC_NO,           KC_NO,              KC_WBAK,          KC_WFWD,             KC_MPRV,       KC_PAUS,
        QK_REBOOT,        KC_LWIN,         KC_TRNS,             KC_LALT,         KC_TRNS,            KC_SPC,         MO(_NEOL3)
    )
};

//RALT(KC_Q) // for ä at position a
//RALT(KC_S) // for ß at position s
//RALT(KC_Y) // for ü at position u
//RALT(KC_P) // for ö at position o

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // switch (keycode) {
    //     case MO(_NEOL4):
    //         if (record->event.pressed) {
    //             // MO_LAYER key pressed
    //             rgblight_setrgb(12, 200, 80);
    //         } else {
    //             // MO_LAYER key released
    //             rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // Change to static mode
    //         }
    //         return false; // Skip all further processing of this key
    //     case MO(_SYS):
    //     if (record->event.pressed) {
    //         // MO_LAYER key pressed
    //         rgblight_set_layer_state(1, 1);
    //     } else {
    //         // MO_LAYER key released
    //         rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // Change to static mode
    //     }
    //     return false; // Skip all further processing of this key
    //     default:
    //         return true; // Process all other keycodes normally
    // }
    return true;
}

// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM _base_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_AZURE}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM _neo3_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, HSV_CYAN}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM _neo4_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 1, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM _sys_light_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 1, HSV_RED}
);


// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    _base_light_layer, 
    _neo3_light_layer,
    _neo4_light_layer,
    _sys_light_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_set();
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, 0);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _NEOL3));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NEOL4));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYS));
    return state;
}


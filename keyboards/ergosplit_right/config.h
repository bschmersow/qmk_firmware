// Copyright 2023 bschmersow (@bschmersow)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* ws2812 RGB LED */
#define RGB_DI_PIN B5

#define RGBLED_NUM 12    // Number of LEDs

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//["16", "15", "14", "A0", "A1", "A2", "A3"],
//["5", "3", "2", "1", "0"]
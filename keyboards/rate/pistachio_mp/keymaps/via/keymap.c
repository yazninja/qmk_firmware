/* Copyright 2020 rate
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE = 0,
    _FN,
    _RESERVE_0,
    _RESERVE_1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
                                           KC_MPLY,
    LT(_FN, KC_NUM),   KC_PSLS,  KC_PAST,  KC_PMNS,
    KC_P7,             KC_P8,    KC_P9,
    KC_P4,             KC_P5,    KC_P6,    KC_PPLS,
    KC_P1,             KC_P2,    KC_P3,
    KC_P0,                       KC_PDOT,  KC_PENT
    ),
    /* Fn */
    [_FN] = LAYOUT(
                                KC_NO,
    KC_NO,   KC_NO,   KC_NO,    KC_NO,
    RGB_HUI, RGB_SAI, RGB_VAI,
    RGB_HUD, RGB_SAD, RGB_VAD,  RGB_TOG,
    KC_NO,   KC_NO,   KC_NO,
    KC_NO,            KC_NO,    KC_NO
    ),
    /* Reserve */
    [_RESERVE_0] = LAYOUT(
                                KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,          KC_TRNS,  KC_TRNS
    ),
    /* Reserve */
    [_RESERVE_1] = LAYOUT(
                                KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,          KC_TRNS,  KC_TRNS
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______) },
};
#endif

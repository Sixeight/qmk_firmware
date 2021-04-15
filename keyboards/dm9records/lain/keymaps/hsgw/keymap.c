/* Copyright 2019 Takuya Urakawa, Dm9Recoreds.com
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
#include "keymap_jp.h"
#include "leds.h"

#define NUM_SPC LT(NUM, KC_SPC)
#define S_SPC LSFT_T(KC_SPC)
#define CTL_ZH LCTL_T(JP_ZHTG)
#define FUNC_BS LT(FUNC, KC_BSPC)
#define FUNC_ENT LT(FUNC, KC_ENT)
#define TAB_CTL LCTL_T(KC_TAB)
#define G2_GUI LT(GAME2, KC_LGUI)
#define WIN_PS LSFT(LGUI(KC_S))
#define VS_FMT LSFT(LALT(KC_F))
#define SFT_ZK LSFT_T(JP_ZHTG)

enum layers { BASE, NUM, FUNC, CONF, GAME, GAME2, L_NUM, XKEY };
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    JP_LBRC,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     JP_AT, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    JP_RBRC,   KC_H,   KC_J,    KC_K,    KC_L,    JP_SCLN,  JP_COLN,\
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_INS, KC_N,    KC_M,    JP_COMM, JP_DOT,   JP_SLSH, \
        KC_LALT,                   KC_LGUI, JP_ZHTG, NUM_SPC,  KC_TAB,  FUNC_ENT, KC_BSPC, MO(FUNC),JP_LBRC, JP_RBRC,  JP_BSLS\
    ),
    [NUM] = LAYOUT(
        KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    S(JP_LBRC),   KC_6,      KC_7,    KC_8,  KC_9,     KC_0,      JP_YEN, \
        _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(JP_RBRC), S(KC_6),   S(KC_7), S(KC_8), S(KC_9),  JP_MINS,   S(JP_MINS),\
        _______, C(KC_Z), VS_FMT,  C(KC_C), C(KC_V), WIN_PS,              VS_FMT,  JP_LBRC, JP_RBRC, S(JP_COMM), S(JP_DOT), JP_CIRC, \
        _______,                   _______, _______, _______, _______,   _______, _______, _______,  S(JP_LBRC), S(JP_RBRC),S(JP_BSLS) \
    ),
    [FUNC] = LAYOUT(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
        _______, _______, _______, _______, _______, _______, _______,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
        _______, _______, _______, _______, _______, _______,             KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, \
        _______,                   _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______ \
    ),
    [CONF] = LAYOUT(
        RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        TG(GAME),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    ),
    [GAME] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    JP_LBRC,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     TG(GAME), \
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    JP_RBRC,   KC_H,   KC_J,    KC_K,    KC_L,    JP_SCLN,  JP_COLN,\
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_PSCR, KC_N,    KC_M,    JP_COMM, JP_DOT,   JP_SLSH, \
        KC_LCTL,                   KC_LALT, G2_GUI, KC_SPC,  KC_ENT,    KC_ENT, KC_BSPC, MO(FUNC),KC_MENU, JP_CIRC,  JP_BSLS\
    ),
    [GAME2] = LAYOUT(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX,                   XXXXXXX, G2_GUI,  XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    ),
    [L_NUM] = LAYOUT(
        KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_TAB, KC_7,    KC_8,    KC_9,    KC_0,    JP_COMM, JP_DOT,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_LSFT,JP_YEN,  JP_PLUS, JP_MINS, JP_ASTR, JP_SLSH,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_LCTL,                  XXXXXXX, KC_BSPC, KC_SPC,  TG(L_NUM),  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    ),
    [XKEY] = LAYOUT(
        KC_ESC,   S(KC_TAB), KC_7,    KC_8,    KC_9,   JP_YEN,  JP_DLR,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_TAB,   KC_TAB,    KC_4,    KC_5,    KC_6,   JP_COMM, JP_DOT,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_LSFT,  KC_0,      KC_1,    KC_2,    KC_3,   JP_MINS,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_0,                         JP_YEN, KC_BSPC, KC_ENT,  TG(XKEY),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) { return true; }

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

uint32_t layer_state_set_user(uint32_t state) {
    uint32_t computed = update_tri_layer_state(state, NUM, FUNC, CONF);
    switch (biton32(computed)) {
        case L_NUM:
        case XKEY:
            set_led(1, 1);
            set_led(2, 0);
            break;
        case GAME:
            set_led(1, 0);
            set_led(2, 1);
            break;
        case CONF:
            set_led(1, 1);
            set_led(2, 1);
            break;
        default:
            set_led(1, 0);
            set_led(2, 0);
            break;
    }
    return computed;
}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        set_led(0, 1);
    } else {
        set_led(0, 0);
    }
}

/* Luke J. Suttey 2024
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details. <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Delete|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LALT | LCMD | MO(1)| /Enter  /       \Space \  | MO(2)| TG(3)| RALT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

 [0] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_MINUS,
    KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_DEL, KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LCTL, KC_LALT, KC_LGUI, MO(1),   KC_ENT,    KC_SPC, MO(2),    TG(3),    KC_RALT, KC_RCTL
),

/*
 * Extra Keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | Prev | Next |      |  [   |  ]   |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | PgUp | Home | Up   |  End |  +   | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | Find |      |-------.    ,-------| PgDm |Left  | Down |Right |  =   |      |
 * |------+------+------+------+------+------|       |    | Calc  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| Cut  | Copy | Paste|      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      | MO(1)| /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

 [1] = LAYOUT(
    KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                       KC_MPRV,   KC_MNXT,   KC_NO,    KC_LBRC,  KC_RBRC,    KC_BSLS,
    KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                       KC_PGUP,   KC_HOME,   KC_UP,    KC_END,   KC_PPLS,    KC_BSPC,
    KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_FIND,  KC_NO,                       KC_PGDN,   KC_Left,   KC_DOWN,  KC_RIGHT, KC_PEQL,    KC_NO,
    KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_CALC,  KC_CUT,    KC_COPY,   KC_PASTE, KC_NO,    KC_NO,      KC_NO,
                     KC_NO,    KC_NO,    KC_NO,    MO(1),    KC_NO,   KC_NO,    KC_NO,     KC_NO,     KC_NO,    KC_NO
),

/*
 * RGB Control and Function Keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  | F2   | F3   | F4   | F5   | F6   |                    | F7   | F8   | F9   | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBTgl|Mode+ | Hue+ | Sat+ | Brt+ | Eff+ |                    |      |ModeP |ModeB |ModeR |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |Mode- | Hue- | Sat- | Brt- | Eff- |-------.    ,-------|      |ModeSW|ModeSN|ModeK |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |Modex |ModeG |ModeT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  | MO(2)|      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

 [2] = LAYOUT(
    KC_F1,  KC_F2,   KC_F3,    KC_F4,    KC_F5,    KC_F6,                       KC_F7,     KC_F8,     KC_F9,    KC_F10,   KC_F11,     KC_F12,
    RGB_TOG,RGB_MOD, RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI,                     KC_NO,     RGB_M_P,   RGB_M_B,  RGB_M_R,  KC_NO,      KC_NO,
    KC_NO,  RGB_RMOD,RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_SPD,                     KC_NO,     RGB_M_SW,  RGB_M_SN, RGB_M_K,  KC_NO,      KC_NO,
    KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,     RGB_M_X,   RGB_M_G,  RGB_M_PT, KC_NO,      KC_NO,
                     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    MO(2),     KC_NO,     KC_NO,    KC_NO
),

/*
 * Number Pad
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |  /   |  *   |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |  7   |  8   |  9   |  +   | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |  4   |  5   |  6   |  =   | Tab  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  1   |  2   |  3   |Enter |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |  LALT| /       /       \      \  |  0   | TG(3)|      |   .  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

 [3] = LAYOUT(
    KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                       KC_NO,     KC_NO,     KC_PSLS,  KC_PAST,  KC_PMNS,      KC_NO,
    KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                       KC_NO,     KC_P7,     KC_P8,    KC_P9,    KC_PPLS,      KC_BSPC,
    KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,                       KC_NO,     KC_P4,     KC_P5,    KC_P6,    KC_PEQL,      KC_TAB,
    KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_P1,     KC_P2,    KC_P3,    KC_PENT,      KC_NO,
                     KC_NO,    KC_NO,    KC_NO,    KC_LALT,  KC_NO,   KC_NO,    KC_P0,     TG(3),     KC_NO,    KC_PDOT
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
};
#endif

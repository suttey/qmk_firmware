/* Copyright 2020 noclew
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
    _BASE,
    _LOWER,
    _RAISE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE
 * ,---------------------------------------------------------------------------------------------------------------.
 * | =    |   7  |   8  |   9  | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+-------------+------+------+------+------+------|
 * |  -   |  4   |   5  |   6  | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------|------+------+------+------+------+------|
 * |  +   |  1   |  2   |   3  | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |  /   |  *   |  .   |   0  | Brite| Ctrl | Alt  | GUI  |Lower | Space|Space |Raise | Left | Down |  Up  |Right |
 * '---------------------------------------------------------------------------------------------------------------'
 * */
[_BASE] = LAYOUT_ss_6x12(
KC_KP_EQUAL,    KC_7,           KC_8,           KC_9,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
KC_KP_MINUS,    KC_4,           KC_5,           KC_6,    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
KC_KP_PLUS,     KC_1,           KC_2,           KC_3,    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_DOT,      KC_0,    KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

 /* Lower
 * ,---------------------------------------------------------------------------------------------------------------.
 * | =    |   7  |   8  |   9  |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+-------------+------+------+------+------+------|
 * |  -   |  4   |   5  |   6  | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------|------+------+------+------+------+------|
 * |  +   |  1   |  2   |   3  |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |  /   |  *   |  .   |   0  |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `---------------------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ss_6x12(
KC_KP_EQUAL,    KC_7,           KC_8,           KC_TILDE, KC_9,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
KC_KP_MINUS,    KC_4,           KC_5,           KC_DEL,   KC_6,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
KC_KP_PLUS,     KC_1,           KC_2,           _______,  KC_3,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______,
KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_DOT,      _______,  KC_0,    _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,---------------------------------------------------------------------------------------------------------------.
 * | =    |   7  |   8  |   9  |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+-------------+------+------+------+------+------|
 * |  -   |  4   |   5  |   6  | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------|------+------+------+------+------+------|
 * |  +   |  1   |  2   |   3  |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |  PGUP|  PGDN|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |  /   |  *   |  .   |   0  |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `---------------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ss_6x12(
  KC_KP_EQUAL,    KC_7,           KC_8,           KC_9,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_KP_MINUS,    KC_4,           KC_5,           KC_6,    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  KC_KP_PLUS,     KC_1,           KC_2,           KC_3,    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_DOT,      KC_0,    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* FN (Lower + Raise)
 * ,---------------------------------------------------------------------------------------------------------------.
 * | =    |   7  |   8  |   9  | Reset|      | Debug|      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------+------+------+------+-------------+------+------+------+------+------|
 * |  -   |  4   |   5  |   6  |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------+------+------+------+------|------+------+------+------+------+------|
 * |  +   |  1   |  2   |   3  |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |  /   |  *   |  .   |   0  |      |      |      |      |      |             |      |      |      |      |      |
 * `---------------------------------------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_ss_6x12(
KC_KP_EQUAL,    KC_7,           KC_8,           KC_9,   QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
KC_KP_MINUS,    KC_4,           KC_5,           KC_6,   _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
KC_KP_PLUS,     KC_1,           KC_2,           KC_3,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_DOT,      KC_0,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _FN);
  return state;
}

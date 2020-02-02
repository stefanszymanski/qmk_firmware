/* Copyright 2019 Stefan Szynanski
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
#include "keymap_german.h"

enum Layers {
  dv,
  num_l,
  num_r,
  sym_l,
  sym_r,
  nav_l,
  nav_r
};

// Special Keys
#define _LSFT MO(sft_l)
#define _RSFT MO(sft_r)

#define _SFT_UE LSFT_T(DE_UE)
#define _NAV_Q LT(nav_l, DE_Q)
#define _NUM_J LT(num_l, DE_J)
#define _SYM_K LT(sym_l, DE_K)
#define _SYM_M LT(sym_r, DE_M)
#define _NUM_W LT(num_r, DE_W)
#define _NAV_V LT(nav_r, DE_V)
#define _SFT_Z RSFT_T(DE_Z)

#define _ESC LGUI_T(KC_ESC)
#define _DEL LALT_T(KC_DEL)
#define _ENT RALT_T(KC_ENT)
#define _BSPC LCTL_T(KC_BSPC)
#define _SPC RCTL_T(KC_SPC)
#define _TAB RGUI_T(KC_TAB)
#define _MENU MEH_T(KC_MENU)

#define _DE_SQ1 ALGR(DE_1)
#define _DE_QRT ALGR(DE_4)
#define _DE_HLF ALGR(DE_5)
#define _DE_NEG ALGR(DE_6)

enum custom_keycodes {
  _QUOTE = SAFE_RANGE,
  _SLASH
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * .-----------------------------------------------------------------------------------------------------------.
 * |        | ' "    | , ;    | . :    | P      | Y      | F      | G      | C      | R      | L      | ß      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | Ä      | A      | O      | E      | U      | I      | D      | H      | T      | N      | S      | - _    |
 * |-----------------------------------------------------------------------------------------------------------|
 * | Ö      | Ü      | Q      | J      | K      | X      | B      | M      | W      | V      | Z      | / \    |
 * |        | SHIFT  | NAV    | NUM    | SYMBOL |        |        | SYMBOL | NUM    | NAV    | SHIFT  |        |
 * |-----------------------------------------------------------------------------------------------------------|
 * |        |        |        | Esc    | Bkspc  | Delete | Enter  | Space  | Tab    | Menu   |        |        |
 * |        |        | HYPER  | LGUI   | LCTRL  | ALT    | ALTGR  | RCTRL  | RGUI   | MEH    |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
[dv] = LAYOUT_ortho_4x12 (
    XXXXXXX, _QUOTE,  DE_COMM, DE_DOT,  DE_P,    DE_Y,    DE_F,    DE_G,    DE_C,    DE_R,    DE_L,    DE_SS,
    DE_AE,   DE_A,    DE_O,    DE_E,    DE_U,    DE_I,    DE_D,    DE_H,    DE_T,    DE_N,    DE_S,    DE_MINS,
    DE_OE,   _SFT_UE, _NAV_Q,  _NUM_J,  _SYM_K,  DE_X,    DE_B,    _SYM_M,  _NUM_W,  _NAV_V,  _SFT_Z,  _SLASH,
    XXXXXXX, XXXXXXX, KC_CAPS, _ESC,    _BSPC,   _DEL,    _ENT,    _SPC,    _TAB,    _MENU,   XXXXXXX, XXXXXXX
),

/* Numbers
 * .-----------------------------------------------------------------------------------------------------------.
 * |        |        | F7     | F8     | F9     | F12    | *      | 7      | 8      | 9      | ,      |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | F4     | F5     | F6     | F11    | =      | 4      | 5      | 6      | .      | -      |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        | F1     | F2     | F3     | F10    | +      | 1      | 2      | 3      | 0      | /      |
 * |-----------------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        | Esc    | Bkspc  | Delete | Enter  | Space  | Tab    | Menu   |        |        |
 * |        |        | HYPER  | LGUI   | LCTRL  | ALT    | ALTGR  | RCTRL  | RGUI   | MEH    |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
[num_l] = LAYOUT_ortho_4x12 (
    XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  DE_DOT,  DE_7,    DE_8,    DE_9,    DE_COMM, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  DE_EQL,  DE_4,    DE_5,    DE_6,    DE_ASTR, _______,
    XXXXXXX, XXXXXXX, KC_F1,   _______, KC_F3,   KC_F10,  DE_PLUS, DE_1,    DE_2,    DE_3,    DE_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[num_r] = LAYOUT_ortho_4x12 (
    XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  DE_DOT,  DE_7,    DE_8,    DE_9,    DE_COMM, DE_SLSH,
    XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  DE_EQL,  DE_4,    DE_5,    DE_6,    DE_ASTR, DE_MINS,
    XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  DE_PLUS, DE_1,    _______, DE_3,    DE_0,    XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Navigation
 * .-----------------------------------------------------------------------------------------------------------.
 * |        | End    | PgDn   | PgUp   | Home   |        |        | MNext  | MPrev  | MPlay  |        |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | Left   | Down   | Up     | Right  |        |        | VolUp  | VolDn  | Mute   |        |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        | Print  | Pause  | Insert |        |        | BriUp  | BriDn  |        |        |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        | Esc    | Bkspc  | Delete | Enter  | Space  | Tab    | Menu   |        |        |
 * |        |        | HYPER  | LGUI   | LCTRL  | ALT    | ALTGR  | RCTRL  | RGUI   | MEH    |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
[nav_l] = LAYOUT_ortho_4x12 (
    XXXXXXX, KC_END,  KC_PGDN, KC_PGUP, KC_HOME, XXXXXXX, XXXXXXX, KC_MNXT, KC_MPRV, KC_MPLY, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, KC_VOLU, KC_VOLD, KC_MUTE, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, _______, KC_PAUS, KC_INS,  XXXXXXX, XXXXXXX, KC_BRIU, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[nav_r] = LAYOUT_ortho_4x12 (
    _______, KC_END,  KC_PGDN, KC_PGUP, KC_HOME, XXXXXXX, XXXXXXX, KC_MNXT, KC_MPRV, KC_MPLY, XXXXXXX, XXXXXXX,
    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, KC_VOLU, KC_VOLD, KC_MUTE, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_PSCR, KC_PAUS, KC_INS,  XXXXXXX, XXXXXXX, KC_BRIU, KC_BRID, _______, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Symbols
 * .-----------------------------------------------------------------------------------------------------------.
 * |        | ¬      | °      | §      | %      | `      | <      | {      | }      | >      | |      |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | €      | ^      | ?      | !      | ´      | =      | (      | )      | @      | &      |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        | ¹      | ²      | ³      | ¼      | ½      | $      | [      | ]      | ~      | #      |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        | Esc    | Bkspc  | Delete | Enter  | Space  | Tab    | Menu   |        |        |
 * |        |        | HYPER  | LGUI   | LCTRL  | ALT    | ALTGR  | RCTRL  | RGUI   | MEH    |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 *
 * TODO remove symbols that are also on default layer
 */
[sym_l] = LAYOUT_ortho_4x12 (
    XXXXXXX, _DE_NEG, DE_RING, DE_PARA, DE_PERC, DE_GRV,  DE_LESS, DE_LCBR, DE_RCBR, DE_MORE, DE_PIPE, XXXXXXX,
    XXXXXXX, DE_EURO, DE_CIRC, DE_QST,  DE_EXLM, DE_ACUT, DE_EQL,  DE_LPRN, DE_RPRN, DE_AT,   DE_AMPR, XXXXXXX,
    XXXXXXX, _DE_SQ1, DE_SQ2,  DE_SQ3,  _______, _DE_HLF, DE_DLR,  DE_LBRC, DE_RBRC, DE_TILD, DE_HASH, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[sym_r] = LAYOUT_ortho_4x12 (
    XXXXXXX, _DE_NEG, DE_RING, DE_PARA, DE_PERC, DE_GRV,  DE_LESS, DE_LCBR, DE_RCBR, DE_MORE, DE_PIPE, XXXXXXX,
    XXXXXXX, DE_EURO, DE_CIRC, DE_QST,  DE_EXLM, DE_ACUT, DE_EQL,  DE_LPRN, DE_RPRN, DE_AT,   DE_AMPR, XXXXXXX,
    XXXXXXX, _DE_SQ1, DE_SQ2,  DE_SQ3,  _DE_QRT, _DE_HLF, DE_DLR,  _______, DE_RBRC, DE_TILD, DE_HASH, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
      bool is_lshift_pressed = 0 < (keyboard_report->mods & MOD_BIT(KC_LSFT));
      bool is_rshift_pressed = 0 < (keyboard_report->mods & MOD_BIT(KC_RSFT));
      bool is_shift_pressed = is_lshift_pressed || is_rshift_pressed;
      switch (keycode) {
        case _QUOTE:
          tap_code16(is_shift_pressed ? DE_DQOT : DE_QUOT);
          return false;
        case _SLASH:
          /* German backslash is AltGr + ß without shift.
           * Therefore pressed shift keys get unregistered before and registered
           * again after the backslash is triggered.
           */
          if (is_shift_pressed) {
              if (is_lshift_pressed) {
                unregister_code(KC_LSFT);
              }
              if (is_rshift_pressed) {
                unregister_code(KC_RSFT);
              }
              tap_code16(DE_BSLS);
              if (is_lshift_pressed) {
                register_code(KC_LSFT);
              }
              if (is_rshift_pressed) {
                register_code(KC_RSFT);
              }
          } else {
            tap_code16(DE_SLSH);
          }
          return false;
      }
  }
  return true;
}

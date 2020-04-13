/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0
#define SYMB 1
#define NUMB 2

#define A__LCTL    MT(MOD_LCTL, KC_A)
#define Z__LSFT    MT(MOD_LSFT, KC_Z)
#define SCLN__RCTL MT(MOD_RCTL, KC_SCLN)
#define SLSH__RSFT MT(MOD_RSFT, KC_SLSH)

#define ESC__LGUI  MT(MOD_LGUI, KC_ESC)
#define ENT__LALT  MT(MOD_LALT, KC_ENT)
#define SPC__SYMB  LT(SYMB, KC_SPC)
#define SPC__NUMB  LT(NUMB, KC_SPC)
#define TAB__RSFT  MT(MOD_RSFT, KC_TAB)

// Combomap
// ,-----------,-----------,-----------,-----------,-----------,          ,-----------,-----------,-----------,-----------,-----------,
// |           |         KC_ESC        |           |           |          |           |         KC_ESC        |         KC_BSLS       |
// |-----------+-----------+-----------+-----------+-----------|          |-----------+-----------+-----------+-----------+-----------|
// |           |         KC_BSPC     KC_TAB        |           |          |         KC_LT       KC_COLN     KC_GT         |           |
// |-----------+-----------+-----------+--KC_BTN2--+--KC_BTN1--|          |---KC_ENT--+-----------+-----------+-----------+-----------|
// |           |         KC_MINS     KC_ENT        |           |          |         KC_QUOT     KC_UNDS       |           |           |
// '-----------'-----------'-----------'-----------'-----------'          '-----------'-----------'-----------'-----------'-----------'

//                               ,----------,----------,----------,    ,----------,----------,----------,
//                               |          |          |          |    |          |          |          |
//                               '----------'----------'----------'    '----------'----------'----------'


// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_gergoplex(
// ,-----------,-----------,-----------,-----------,-----------,          ,-----------,-----------,-----------,-----------,-----------,
           KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                  KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
// |-----------+-----------+-----------+-----------+-----------|          |-----------+-----------+-----------+-----------+-----------|
        A__LCTL,       KC_S,       KC_D,       KC_F,       KC_G,                  KC_H,       KC_J,       KC_K,       KC_L, SCLN__RCTL,
// |-----------+-----------+-----------+-----------+-----------|          |-----------+-----------+-----------+-----------+-----------|
        Z__LSFT,       KC_X,       KC_C,       KC_V,       KC_B,                  KC_N,       KC_M,    KC_COMM,     KC_DOT, SLSH__RSFT,
// '-----------'-----------'-----------'-----------'-----------'          '-----------'-----------'-----------'-----------'-----------'

//                               ,----------,----------,----------,    ,----------,----------,----------,
                                   ESC__LGUI, ENT__LALT, SPC__SYMB,      SPC__NUMB,   KC_BSPC, TAB__RSFT
//                               '----------'----------'----------'    '----------'----------'----------'
    ),
[SYMB] = LAYOUT_gergoplex(
<<<<<<< HEAD
// ,-----------,-----------,-----------,-----------,-----------,          ,-----------,-----------,-----------,-----------,-----------,
        KC_EXLM,      KC_AT,    KC_LCBR,    KC_RCBR,    KC_PIPE,                KC_GRV,    KC_TILD,    KC_TRNS,    KC_TRNS,    KC_BSLS,
// |-----------+-----------+-----------+-----------+-----------|          |-----------+-----------+-----------+-----------+-----------|
        KC_HASH,     KC_DLR,    KC_LPRN,    KC_RPRN,    KC_BTN2,               KC_PLUS,    KC_MINS,    KC_SLSH,    KC_ASTR,    KC_QUOT,
// |-----------+-----------+-----------+-----------+-----------|          |-----------+-----------+-----------+-----------+-----------|
        KC_PERC,    KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_BTN1,               KC_AMPR,     KC_EQL,    KC_COMM,     KC_DOT,    KC_MINS,
// '-----------'-----------'-----------'-----------'-----------'          '-----------'-----------'-----------'-----------'-----------'

//                               ,----------,----------,----------,    ,----------,----------,----------,
                                     KC_BTN3,   KC_SCLN,    KC_EQL,         KC_EQL,   KC_SCLN,    KC_DEL
//                               '----------'----------'----------'    '----------'----------'----------'
=======
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,   KC_GRV,  KC_TILD, KC_TRNS, KC_TRNS, KC_BSLS,
    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_BTN2,   KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT,
    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BTN1,   KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_MINS,
                      CMB_TOG, KC_SCLN, KC_EQL,   KC_EQL,  KC_SCLN, KC_DEL
>>>>>>> upstream/gboards-consolidate
    ),
[NUMB] = LAYOUT_gergoplex(
// ,-----------,-----------,-----------,-----------,-----------,          ,-----------,-----------,-----------,-----------,-----------,
           KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                  KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
// |-----------+-----------+-----------+-----------+-----------|          |-----------+-----------+-----------+-----------+-----------|
          KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,               KC_LEFT,    KC_DOWN,      KC_UP,    KC_RGHT,    KC_VOLU,
// |-----------+-----------+-----------+-----------+-----------|          |-----------+-----------+-----------+-----------+-----------|
          KC_F6,      KC_F7,      KC_F8,      KC_F9,     KC_F10,               KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_VOLD,
// '-----------'-----------'-----------'-----------'-----------'          '-----------'-----------'-----------'-----------'-----------'

//                               ,----------,----------,----------,    ,----------,----------,----------,
                                      KC_F11,    KC_F12,   KC_TRNS,        KC_TRNS,   KC_MPLY,   KC_MNXT
//                               '----------'----------'----------'    '----------'----------'----------'
    )
};

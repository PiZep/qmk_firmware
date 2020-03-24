/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion
#define ACCE 3 // current accentuated letters

#define CTL_Q MT(MOD_LCTL, KC_A)
#define SHT_W MT(MOD_RSFT, KC_Z)
#define ALG_P MT(MOD_ALTG, KC_P)
#define CTL_M MT(MOD_LCTL, KC_SCLN)
#define SHT_EXLM MT(MOD_RSFT, KC_SLSH)
#define ESC_META MT(MOD_LGUI, KC_ESC)
#define ENT_LALT MT(MOD_LALT, KC_ENT)
#define SPC_SYMB LT(SYMB, KC_SPC)
#define SPC_NUMB LT(NUMB, KC_SPC)
#define TAB_RSFT MT(MOD_RSFT, KC_TAB)

/* Combomap
 *
 * .-----.-----.-----.-----.-----.      .-----.-----.-----.-----.-----.
 * |     |    ESC    |     |     |      |     |    ESC    |    BSLH   |
 * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
 * |     |    BSPC  ENT    |     |      |    LES   COLN  GRT    |     | 
 * |-----+-----+-----+--RMB+-LMB-+      |-----+-----+-----+-----+-----|
 * |     |   MINS    |     |     |      |    QUO   UNDR   |     |     |
 * '-----'-----'-----'-----'-----'      '-----'-----'-----'-----'-----'
 *               .-----.-----.-----.   .-----.-----.-----. 
 *               |     |     |     |   |     |     |     |
 *               '-----'-----'-----'   '-----'-----'-----'
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * .------.-----.-----.-----.-----.      .-----.-----.-----.-----.------.
 * |    A |  Z  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |ALTG/P|
 * |------+-----+-----+-----+-----|      |-----+-----+-----+-----+------|
 * |CTRL/Q|  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  |CTRL/M| 
 * |------+-----+-----+-----+-----|      |-----+-----+-----+-----+------|
 * |SHFT/W|  X  |  C  |  V  |  B  |      |  N  |  ,  |  ;  |  :  |SHFT/!|
 * '------'-----'-----'-----'-----'      '-----'-----'-----'-----'------'
 *        .--------.-------.--------.   .--------.----.-----.   
 *        |ESC/META|ENT/ALT|SPC(SYM)|   |SPC(NUM)|LSFT| TAB |
 *        '--------'-------'--------'   '--------'----'-----' 
 */
[BASE] = LAYOUT_gergoplex(
    FR_A,  FR_Z, FR_E, FR_R, FR_T,         FR_Y, FR_U,    FR_I,    FR_O,    ALG_P, 
    CTL_Q, FR_S, FR_D, FR_F, FR_G,         FR_H, FR_J,    FR_K,    FR_L,    CTL_M,
    SHT_W, FR_X, FR_C, FR_V, FR_B,         FR_N, FR_COMM, FR_SCLN, FR_COLN, SHT_EXLM,

        ESC_META, ENT_LALT, SPC_SYMB,      SPC_NUMB, KC_LSFT, TAB_RSFT
    ),


/* Keymap 1: Symbols layer
 * .-----.-----.-----.-----.-----.      .-----.-----.-----.-----.-----.
 * |  @  |  #  |  {  |  }  |  |  |      | _`  |  ~  |  "  | _^  | \   |
 * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
 * |     |  $  |  (  |  )  | LMB |      |  +  |  -  |  /  |  *  |  '  | 
 * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
 * |  %  |  ^  |  [  |  ]  | RMB |      |  &  |  =  |  ,  |  .  |  -  |
 * '-----'-----'-----'-----'-----'      '-----'-----'-----'-----'-----'
 *               .-----.-----.-----.   .-----.-----.-----. 
 *               | MMB |  ;  |     |   |  =  |  '  | DEL |
 *               '-----'-----'-----'   '-----'-----'-----'
 */
[SYMB] = LAYOUT_gergoplex(
    FR_AT, FR_HASH,   FR_LCBR, FR_RCBR, FR_PIPE,       FR_GRV,  FR_TILD, FR_QUOT, FR_CIRC, FR_BSLS,
    FR_TRNS, FR_DLR,  FR_LPRN, FR_RPRN, KC_BTN2,       FR_PLUS, FR_MINS, FR_SLSH, FR_ASTR, FR_QUOT,
    FR_PERC, FR_CCIRC, FR_LBRC, FR_RBRC, KC_BTN1,      FR_AMPR, FR_EQL,  FR_COMM, FR_DOT,  FR_MINS,
                        KC_BTN3, KC_SCLN, KC_TRNS,     KC_EQL,  FR_APOS, KC_DEL
    ),


/* Keymap 2: Pad/Function layer
 * .-----.-----.-----.-----.-----.      .-----.-----.-----.-----.-------.
 * |  1  |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
 * |  F1 | F2  | F3  | F4  |  F5 |      | LFT | DWN | UP  | RGT | VOLUP | 
 * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
 * |  F6 | F7  | F8  | F9  | F10 |      |MLFT | MDWN| MUP | MRGT| VOLDN |
 * '-----'-----'-----'-----'-----'      '-----'-----'-----'-----'-------'
 *               .-----.-----.-----.   .-----.-----.-----. 
 *               | F11 | F12 |     |   |     | PLY | SKP |
 *               '-----'-----'-----'   '-----'-----'-----'
 */
[NUMB] = LAYOUT_gergoplex(
    FR_1,  FR_2,  FR_3,  FR_4,  FR_5,             FR_6,   FR_7,   FR_8,   FR_9,   FR_0,
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,           KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,
                    KC_F11,KC_F12,KC_TRNS,        KC_TRNS,KC_MPLY,KC_MNXT
    ),

/* Keymap 3: Accents layer
 * .-----.-----.-----.-----.-----.      .-----.-----.-----.-----.-----.
 * |  à  |  ê  |  é  |  è  |     |      |     |  ù  |  î  |  ô  |     |
 * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
 * |     |  $  |     |     |     |      |     |     |     |  £  |     |
 * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
 * |     |     |  ç  |     |     |      |     |     |     |     |     |
 * '-----'-----'-----'-----'-----'      '-----'-----'-----'-----'-----'
 *               .-----.-----.-----.   .-----.-----.-----. 
 *               |     |     |     |   |     |     |     |
 *               '-----'-----'-----'   '-----'-----'-----'
 */
[ACCE] = LAYOUT_gergoplex(
    
)
};

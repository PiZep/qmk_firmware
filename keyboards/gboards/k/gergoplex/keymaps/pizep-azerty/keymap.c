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

#define CTL_Q MT(MOD_LCTL, KC_A)
#define SFT_W MT(MOD_RSFT, KC_Z)
#define AG_BSP MT(MOD_RALT, KC_BSPC)
#define CTL_M MT(MOD_LCTL, KC_SCLN)
#define S_EXLM MT(MOD_RSFT, KC_SLSH)
#define S_DOT MT(MOD_RSFT, KC_PDOT)
#define G_ESC MT(MOD_LGUI, KC_ESC)
#define A_ENT MT(MOD_LALT, KC_ENT)
#define SP_SYM LT(SYMB, KC_SPC)
#define SP_NUM LT(NUMB, KC_SPC)
#define RS_TAB MT(MOD_RSFT, KC_TAB)

#include "keymap_french.h"
/* Combomap
 *
 * .-----.-----.-----.-----.-----.      .-----.-----.-----.-----.-----.
   |    ESC  E_ACU   |     |     |      |     |     |   A_GRA  ESC    |
 * |-----+-----+-QUO-+-APO-+-----|      |-----+E_GRA+-----+C_CED+-----|
 * |     |    BSPC  TAB    |     |      |    LRT   _^    GRT    |     |
 * |-----+-----+-----+--RMB+-LMB-+      |-ENT-+-----+-----+U_GRA+-----|
 * |     |   MINS   ENT  LA(ENT) |      |    APO   UNDR   |     |     |
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
    * |    A |  Z  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  | P    |
    * |------+-----+-----+-----+-----|      |-----+-----+-----+-----+------|
    * |CTRL/Q|  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  |CTRL/M|
    * |------+-----+-----+-----+-----|      |-----+-----+-----+-----+------|
    * |SHFT/W|  X  |  C  |  V  |  B  |      |  N  |  ,  |  ;  |  :  |SHFT/!|
    * '------'-----'-----'-----'-----'      '-----'-----'-----'-----'------'
    *        .--------.-------.--------.   .--------.----------.------.
    *        |ESC/META|ENT/ALT|SPC(SYM)|   |SPC(NUM)| ALTG/BSPC|LSFT/.|
    *        '--------'-------'--------'   '--------'----------'------'
    */
    [BASE] = LAYOUT_gergoplex(
      FR_A,  FR_Z,  FR_E,  FR_R,  FR_T,             FR_Y,    FR_U,    FR_I,    FR_O,   KC_P,
     CTL_Q,  FR_S,  FR_D,  FR_F,  FR_G,             FR_H,    FR_J,    FR_K,    FR_L,  CTL_M,
     SFT_W,  FR_X,  FR_C,  FR_V,  FR_B,             FR_N, FR_COMM, FR_SCLN, FR_COLN, S_EXLM,

                    G_ESC, A_ENT, SP_SYM,      SP_NUM, S_DOT, AG_BSP
        ),


    /* Keymap 1: Symbols layer
    * .-----.-----.-----.-----.-----.      .-----.-----.-----.-----.-----.
    * |  @  |  #  |  {  |  }  |  |  |      | _`  |  ~  |  "  | _^  | \   |
    * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
    * |  %  |  $  |  (  |  )  | LMB |      |  +  |  -  |  /  |  *  |  '  |
    * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-----|
    * | SFT |  ^  |  [  |  ]  | RMB |      |  &  |  =  |  ,  |  .  |  -  |
    * '-----'-----'-----'-----'-----'      '-----'-----'-----'-----'-----'
    *               .-----.-----.-----.   .-----.-----.-----.
    *               | MMB |  ;  |     |   |  =  | DEL |     |
    *               '-----'-----'-----'   '-----'-----'-----'
    */
    [SYMB] = LAYOUT_gergoplex(
        FR_AT,   FR_HASH,  FR_LCBR, FR_RCBR, FR_PIPE,       FR_GRV,  FR_TILD, FR_QUOT, FR_CIRC, FR_BSLS,
        FR_PERC, FR_DLR,   FR_LPRN, FR_RPRN, KC_BTN2,       FR_PLUS, FR_MINS, FR_SLSH, FR_ASTR, FR_QUOT,
        KC_LSFT, FR_CCIRC, FR_LBRC, FR_RBRC, KC_BTN1,       FR_AMPR, FR_EQL,  FR_COMM, FR_DOT,  FR_MINS,

                           KC_BTN3, KC_SCLN, KC_TRNS,       KC_EQL,  KC_TRNS, KC_DEL
        ),


    /* Keymap 2: Pad/Function layer
    * FR_[0-9] replaced by KC_P[0-9] in order to add combos, as FR_[0-9] are
    * shifted keycodes
    * .-----.-----.-----.-----.-----.      .-----.-----.-----.-----.-------.
    * |  1  |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
    * |-----+-----+-----+-----+-----|      |-HOME+-PGDN+-PGUP+-END-+-------|
    * |  F1 | F2  | F3  | F4  |  F5 |      | LFT | DWN | UP  | RGT | VOLUP |
    * |-----+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
    * |  F6 | F7  | F8  | F9  | F10 |      |MLFT | MDWN| MUP | MRGT| VOLDN |
    * '-----'-----'-----'-----'-----'      '-----'-----'-----'-----'-------'
    *               .-----.-----.-----.   .-----.-----.-----.
    *               | F11 | F12 | PDOT|   |     | PLY | SKP |
    *               '-----'-----'-----'   '-----'-----'-----'
    */
    [NUMB] = LAYOUT_gergoplex(
        KC_P1, KC_P2, KC_P3, KC_P4, KC_P5,            KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,           KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,

                      KC_F11, KC_F12, KC_PDOT,        KC_TRNS, KC_MPLY, KC_MNXT
        ),
};

void led_set_keymap(uint8_t usb_led) {
    if (!(usb_led & (1 << USB_LED_NUM_LOCK))) {
        register_code(KC_NUMLOCK);
        unregister_code(KC_NUMLOCK);
    }
}

void matric_init_user(void) {
    if (!(host_keyboard_leds() & (1 << USB_LED_NUM_LOCK))) {
        register_code(KC_NUMLOCK);
        unregister_code(KC_NUMLOCK);
    }
}

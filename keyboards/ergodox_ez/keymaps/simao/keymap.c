#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols

enum custom_keycodes {
                      EPRM = SAFE_RANGE,
                      VRSN,
                      SM_TILDE,
                      SM_CEDILLA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(
  // left hand
  LT(SYMB,KC_NO),  KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_HOME,
  KC_TAB,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_ESC,
  KC_LCTL,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_GRV,
  KC_MUTE,         KC_NO,       KC_NO,         LT(SYMB,KC_NO),   KC_LALT,

                                                                   KC_WBAK, KC_NO,
                                                                            KC_NO,
                                                         KC_BSPC, KC_LGUI, KC_DEL,
  // right hand
  KC_END,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_LBRC,     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_RBRC,
               KC_H,    KC_J,    KC_K,    KC_L,              KC_SCLN,        KC_QUOT,
  KC_EQL,      KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH,        KC_BSLS,
  KC_INS,      KC_F6,   KC_F7,   KC_NO,   KC_RCTL,

  KC_LEFT, KC_RGHT,
  KC_UP,
  KC_DOWN, KC_ENT, KC_SPC
),

[SYMB] = LAYOUT_ergodox(
  // Left hand
  DEBUG,       KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,    KC_TRNS,
  KC_TRNS,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,    KC_TRNS,
  KC_TRNS,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,
  KC_TRNS,     KC_TRNS,     KC_TRNS,     SM_CEDILLA,  KC_TRNS,     KC_NO,    SM_TILDE,
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

                                                                       KC_NO, KC_TRNS,
                                                                              KC_TRNS,
                                                                KC_NO, KC_NO, KC_TRNS,

  // Right hand
  KC_TRNS,     KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,
  KC_TRNS,     KC_NO,       KC_UP,       KC_NO,       KC_NO,       KC_NO,       KC_F12,
               KC_LEFT,     KC_DOWN,     KC_RGHT,     KC_NO,       KC_PLUS,     KC_TRNS,
  KC_TRNS,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_TRNS,
               KC_TRNS,     KC_TRNS,     KC_MUTE,     KC_VOLD,     KC_VOLU,

  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    case SM_TILDE:
      SEND_STRING(SS_TAP(X_RCTRL) SS_LSFT("`") SS_TAP(X_A));
      return false;
    case SM_CEDILLA:
      SEND_STRING(SS_TAP(X_RCTRL) SS_TAP(X_COMMA) SS_TAP(X_C));
      return false;
    case EPRM:
      eeconfig_init();
      return false;
    case VRSN:
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      return false;
    }
  };

  return true;
}

#include <print.h>

#include QMK_KEYBOARD_H

enum custom_keycodes {
                      SM_TILDE = SAFE_RANGE,
                      SM_CEDILLA
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SM_TILDE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL) SS_LSFT("`") SS_TAP(X_A));
    } else {
      // when keycode SM_TILDE is released
    }
    break;
  case SM_CEDILLA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RCTRL) SEND_STRING(",c"));
    } else {
      // release
    }
    break;

  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
                                                              [0] = LAYOUT_ergodox(LT(1,KC_NO), KC_1, KC_2, KC_3, KC_4, KC_5, KC_HOME, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_ESC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_GRV, KC_MUTE, KC_NO, KC_NO, LT(1,KC_NO), KC_LALT, KC_WBAK, KC_NO, KC_NO, KC_BSPC, KC_LGUI, KC_DEL, KC_END, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_LBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_EQL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, KC_INS, KC_F6, KC_F7, KC_NO, KC_RCTL, KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, KC_ENT, KC_SPC),
                                                              [1] = LAYOUT_ergodox(DEBUG, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, SM_TILDE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_F12, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_PLUS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU),
                                                              [2] = LAYOUT_ergodox(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WBAK)
};

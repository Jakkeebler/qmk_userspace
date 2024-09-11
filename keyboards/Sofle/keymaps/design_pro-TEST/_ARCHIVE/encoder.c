#include QMK_KEYBOARD_H
#include "keymap.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Encoder Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool encoder_update_user(uint8_t index, bool clockwise)
{
  // Print the current layer for debugging
  printf("Current layer: %d\n", get_highest_layer(layer_state));

  if (index == 0)
  {
    switch (get_highest_layer(layer_state)) {
    case _QWERTY:
    case _FUNCPAD:
      if (clockwise) {
        register_code(KC_WH_D);
        unregister_code(KC_WH_D);
      } else {
        register_code(KC_WH_U);
        unregister_code(KC_WH_U);
      }
      break;
    case _ILSTR:
      if (clockwise) {
        register_code(KC_LCTL);
        register_code(KC_EQL);
        unregister_code(KC_EQL);
        unregister_code(KC_LCTL);
      } else {
        register_code(KC_LCTL);
        register_code(KC_MINS);
        unregister_code(KC_MINS);
        unregister_code(KC_LCTL);
      }
      break;
    case _SWITCH:
      if (clockwise) {
        register_code(KC_LCTL);
        register_code(KC_RBRC);
        unregister_code(KC_RBRC);
        unregister_code(KC_LCTL);
      } else {
        register_code(KC_LCTL);
        register_code(KC_LBRC);
        unregister_code(KC_LBRC);
        unregister_code(KC_LCTL);
      }
      break;
    default:
      if (clockwise) {
        register_code(KC_D);
        unregister_code(KC_D);
      } else {
        register_code(KC_U);
        unregister_code(KC_U);
      }
      break;
    }
  }
  else if (index == 1)
  {
    switch (get_highest_layer(layer_state)) {
    case _QWERTY:
    case _FUNCPAD:
      if (clockwise) {
        register_code(KC_WH_D);
        unregister_code(KC_WH_D);
      } else {
        register_code(KC_WH_U);
        unregister_code(KC_WH_U);
      }
      break;
    case _ILSTR:
      if (clockwise) {
        register_code(KC_LCTL);
        register_code(KC_RBRC);
        unregister_code(KC_RBRC);
        unregister_code(KC_LCTL);
      } else {
        register_code(KC_LCTL);
        register_code(KC_LBRC);
        unregister_code(KC_LBRC);
        unregister_code(KC_LCTL);
      }
      break;
    case _SWITCH:
      if (clockwise) {
        register_code(KC_LCTL);
        register_code(KC_RBRC);
        unregister_code(KC_RBRC);
        unregister_code(KC_LCTL);
      } else {
        register_code(KC_LCTL);
        register_code(KC_LBRC);
        unregister_code(KC_LBRC);
        unregister_code(KC_LCTL);
      }
      break;
    default:
      if (clockwise) {
        register_code(KC_WH_D);
        unregister_code(KC_WH_D);
      } else {
        register_code(KC_WH_U);
        unregister_code(KC_WH_U);
      }
      break;
    }
  }

  return false;
}

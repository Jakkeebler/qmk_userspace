/*
Copyright 2017 Balz Guenat <balz.guenat@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Tap Dance declarations
enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_7,
  DANCE_8,
  DANCE_A,
  DANCE_B,
  DANCE_C,
  DANCE_F,
  DANCE_G,
  DANCE_Q,
  DANCE_S,
  DANCE_V,
  DANCE_W,
  DANCE_X,
  DANCE_Y,
  DANCE_Z,
  TAP_DANCE_COUNT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain Qwerty without layer switching
     * ,---.   |---------------| |---------------| |---------------|
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12|
     * `---'   `---------------' `---------------' `---------------'
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
     * |-----------------------------------------------------------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  "|  #|Retn|
     * |-----------------------------------------------------------|     ,---.
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |
     * |-----------------------------------------------------------| ,-----------.
     * |fn  |Ctl|Alt|GUI| Space               |Gui|Alt             | |Lef|Dow|Rig|
     * `-----------------------------------------------------------' `-----------'
     */
    [0] = LAYOUT_all(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,              KC_UP,
    KC_F,    KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,                                   KC_LNG1, KC_RGUI, KC_RALT,                       KC_LEFT, KC_DOWN, KC_RGHT,
    ),
    [1] = LAYOUT_all(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,              KC_UP,
    KC_F,    KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,                                   KC_LNG1, KC_RGUI, KC_RALT,                       KC_LEFT, KC_DOWN, KC_RGHT,
    ),
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
    TD_MORE_TAPS
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

static td_state_t dance_state[TAP_DANCE_COUNT];

td_state_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->pressed) return TD_TRIPLE_HOLD;
        else return TD_TRIPLE_TAP;
    }
    return TD_MORE_TAPS;
}

// Dance Functions
// Dance 0
void on_dance_0(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_0] = dance_step(state);
    switch (dance_state[DANCE_0]) {
        case TD_SINGLE_TAP: register_code16(KC_0); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_0)); break;
        case TD_TRIPLE_TAP: register_code16(LCA(KC_0)); break;
        default: break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_0]) {
        case TD_SINGLE_TAP: unregister_code16(KC_0); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_0)); break;
        case TD_TRIPLE_TAP: unregister_code16(LCA(KC_0)); break;
        default: break;
    }
    dance_state[DANCE_0] = 0;
}


// Dance 1
void on_dance_1(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_1] = dance_step(state);
    switch (dance_state[DANCE_1]) {
        case TD_SINGLE_TAP: register_code16(KC_1); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_1)); break;
        default: break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_1]) {
        case TD_SINGLE_TAP: unregister_code16(KC_1); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_1)); break;
        default: break;
    }
    dance_state[DANCE_1] = 0;
}


// Dance 2
void on_dance_2(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_2] = dance_step(state);
    switch (dance_state[DANCE_2]) {
        case TD_SINGLE_TAP: register_code16(KC_2); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_2)); break;
        case TD_TRIPLE_TAP: register_code16(LCA(KC_2)); break;
        default: break;
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_2]) {
        case TD_SINGLE_TAP: unregister_code16(KC_2); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_2)); break;
        case TD_TRIPLE_TAP: unregister_code16(LCA(KC_2)); break;
        default: break;
    }
    dance_state[DANCE_2] = 0;
}



// Dance 3
void on_dance_3(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {

    dance_state[DANCE_3] = dance_step(state);
    switch (dance_state[DANCE_3]) {
        case TD_SINGLE_TAP: register_code16(KC_3); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_3)); break;
        case TD_TRIPLE_TAP: register_code16(LCA(KC_3)); break;
        default: break;
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_3]) {
        case TD_SINGLE_TAP: unregister_code16(KC_3); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_3)); break;
        case TD_TRIPLE_TAP: unregister_code16(LCA(KC_3)); break;
        default: break;
    }
    dance_state[DANCE_3] = 0;
}


// Dance 7
void on_dance_7(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_7] = dance_step(state);
    switch (dance_state[DANCE_7]) {
        case TD_SINGLE_TAP: register_code16(KC_7); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_7)); break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_7);
            break;
        default: break;
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_7]) {
        case TD_SINGLE_TAP: unregister_code16(KC_7); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_7)); break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_7);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_7] = 0;
}


// Dance 8
void on_dance_8(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_8] = dance_step(state);
    switch (dance_state[DANCE_8]) {
        case TD_SINGLE_TAP: register_code16(KC_8); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_8)); break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_8);
            break;
        default: break;
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_8]) {
        case TD_SINGLE_TAP: unregister_code16(KC_8); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_8)); break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_8);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_8] = 0;
}

// Dance A
void on_dance_A(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_A_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_A] = dance_step(state);
    switch (dance_state[DANCE_A]) {
        case TD_SINGLE_TAP: register_code16(KC_A); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_A)); break;
        default: break;
    }
}

void dance_A_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_A]) {
        case TD_SINGLE_TAP: unregister_code16(KC_A); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_A)); break;
        default: break;
    }
    dance_state[DANCE_A] = 0;
}

// Dance B
void on_dance_B(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_B_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_B] = dance_step(state);
    switch (dance_state[DANCE_B]) {
        case TD_SINGLE_TAP: register_code16(KC_B); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_B)); break;
        default: break;
    }
}

void dance_B_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_B]) {
        case TD_SINGLE_TAP: unregister_code16(KC_B); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_B)); break;
        default: break;
    }
    dance_state[DANCE_B] = 0;
}

// Dance C
void on_dance_C(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_C_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_C] = dance_step(state);
    switch (dance_state[DANCE_C]) {
        case TD_SINGLE_TAP: register_code16(KC_C); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_C)); break;
        default: break;
    }
}

void dance_C_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_C]) {
        case TD_SINGLE_TAP: unregister_code16(KC_C); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_C)); break;
        default: break;
    }
    dance_state[DANCE_C] = 0;
}

// Dance F
void on_dance_F(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_F_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_F] = dance_step(state);
    switch (dance_state[DANCE_F]) {
        case TD_SINGLE_TAP: register_code16(KC_F); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_F)); break;
        default: break;
    }
}

void dance_F_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_F]) {
        case TD_SINGLE_TAP: unregister_code16(KC_F); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_F)); break;
        default: break;
    }
    dance_state[DANCE_F] = 0;
}

// Dance G
void on_dance_G(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_G_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_G] = dance_step(state);
    switch (dance_state[DANCE_G]) {
        case TD_SINGLE_TAP: register_code16(KC_G); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_G)); break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_G);
            break;
        default: break;
    }
}

void dance_G_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_G]) {
        case TD_SINGLE_TAP: unregister_code16(KC_G); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_G)); break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_G);
            break;
        default: break;
    }
    dance_state[DANCE_G] = 0;
}

// Dance Q
void on_dance_Q(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_Q_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_Q] = dance_step(state);
    switch (dance_state[DANCE_Q]) {
        case TD_SINGLE_TAP: register_code16(KC_Q); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_Q)); break;
        default: break;
    }
}

void dance_Q_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_Q]) {
        case TD_SINGLE_TAP: unregister_code16(KC_Q); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_Q)); break;
        default: break;
    }
    dance_state[DANCE_Q] = 0;
}

// Dance S
void on_dance_S(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_S_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_S] = dance_step(state);
    switch (dance_state[DANCE_S]) {
        case TD_SINGLE_TAP: register_code16(KC_S); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_S)); break;
        case TD_DOUBLE_HOLD: register_code16(LCA(KC_S)); break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_S);
            break;
        default: break;
    }
}

void dance_S_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_S]) {
        case TD_SINGLE_TAP: unregister_code16(KC_S); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_S)); break;
        case TD_DOUBLE_HOLD: unregister_code16(LCA(KC_S)); break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_S);
            break;
        default: break;
    }
    dance_state[DANCE_S] = 0;
}

// Dance V
void on_dance_V(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_V_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_V] = dance_step(state);
    switch (dance_state[DANCE_V]) {
        case TD_SINGLE_TAP: register_code16(KC_V); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_V)); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_V);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_V);
            break;
        default: break;
    }
}

void dance_V_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_V]) {
        case TD_SINGLE_TAP: unregister_code16(KC_V); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_V);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            unregister_code(KC_LSFT);
            unregister_code(KC_V);
            break;
        default: break;
    }
    dance_state[DANCE_V] = 0;
}

// Dance W
void on_dance_W(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_W_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_W] = dance_step(state);
    switch (dance_state[DANCE_W]) {
        case TD_SINGLE_TAP: register_code16(KC_W); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_W)); break;
        default: break;
    }
}

void dance_W_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_W]) {
        case TD_SINGLE_TAP: unregister_code16(KC_W); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_W)); break;
        default: break;
    }
    dance_state[DANCE_W] = 0;
}

// Dance X
void on_dance_X(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_X_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_X] = dance_step(state);
    switch (dance_state[DANCE_X]) {
        case TD_SINGLE_TAP: register_code16(KC_X); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LSFT);
            register_code(KC_X);
            break;
        case TD_TRIPLE_TAP: register_code16(LCTL(KC_X)); break;
        default: break;
    }
}

void dance_X_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_X]) {
        case TD_SINGLE_TAP: unregister_code16(KC_X); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_LSFT);
            unregister_code(KC_X);
            break;
        case TD_TRIPLE_TAP: unregister_code16(LCTL(KC_X)); break;
        default: break;
    }
    dance_state[DANCE_X] = 0;
}

// Dance Y
void on_dance_Y(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_Y_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_Y] = dance_step(state);
    switch (dance_state[DANCE_Y]) {
        case TD_SINGLE_TAP: register_code16(KC_Y); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_Y)); break;
        default: break;
    }
}

void dance_Y_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_Y]) {
        case TD_SINGLE_TAP: unregister_code16(KC_Y); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_Y)); break;
        default: break;
    }
    dance_state[DANCE_Y] = 0;
}

// Dance Z
void on_dance_Z(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_Z_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_Z] = dance_step(state);
    switch (dance_state[DANCE_Z]) {
        case TD_SINGLE_TAP: register_code16(KC_Z); break;
        case TD_DOUBLE_TAP: register_code16(LCTL(KC_Z)); break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_Z);
            break;
        default: break;
    }
}

void dance_Z_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_Z]) {
        case TD_SINGLE_TAP: unregister_code16(KC_Z); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_Z)); break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_Z);
            break;
        default: break;
    }
    dance_state[DANCE_Z] = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_A] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_A, dance_A_finished, dance_A_reset),
        [DANCE_B] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_B, dance_B_finished, dance_B_reset),
        [DANCE_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_C, dance_C_finished, dance_C_reset),
        [DANCE_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_F, dance_F_finished, dance_F_reset),
        [DANCE_G] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_G, dance_G_finished, dance_G_reset),
        [DANCE_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Q, dance_Q_finished, dance_Q_reset),
        [DANCE_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_S, dance_S_finished, dance_S_reset),
        [DANCE_V] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_V, dance_V_finished, dance_V_reset),
        [DANCE_W] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_W, dance_W_finished, dance_W_reset),
        [DANCE_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_X, dance_X_finished, dance_X_reset),
        [DANCE_Y] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Y, dance_Y_finished, dance_Y_reset),
        [DANCE_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Z, dance_Z_finished, dance_Z_reset),
};

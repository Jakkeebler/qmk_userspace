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
#define TAPPING_TERM 200

// Layers
enum layers {
    BASE
};

// Tap Dance declarations
enum tap_dance_codes {
    DANCE_MINS,
    DANCE_EQL,
    DANCE_LBRC,
    DANCE_RBRC,
    DANCE_0,
    DANCE_1,
    DANCE_2,
    DANCE_3,
    DANCE_5,
    DANCE_7,
    DANCE_8,
    DANCE_A,
    DANCE_B,
    DANCE_C,
    DANCE_D,
    DANCE_E,
    DANCE_F,
    DANCE_G,
    DANCE_I,
    DANCE_N,
    DANCE_O,
    DANCE_Q,
    DANCE_R,
    DANCE_S,
    DANCE_T,
    DANCE_V,
    DANCE_W,
    DANCE_X,
    DANCE_Y,
    DANCE_Z,
    TAP_DANCE_COUNT
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
// Dance Minus
void on_dance_MINS(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_MINS_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_MINS] = dance_step(state);
    switch (dance_state[DANCE_MINS]) {
        case TD_SINGLE_TAP: register_code16(KC_MINS); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_MINS);
            break;
        default: break;
    }
}

void dance_MINS_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_MINS]) {
        case TD_SINGLE_TAP: unregister_code16(KC_MINS); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_MINS);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_MINS] = 0;
}


// Dance Equals
void on_dance_EQL(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_EQL_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_EQL] = dance_step(state);
    switch (dance_state[DANCE_EQL]) {
        case TD_SINGLE_TAP: register_code16(KC_EQL); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_EQL);
            break;
        default: break;
    }
}

void dance_EQL_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_EQL]) {
        case TD_SINGLE_TAP: unregister_code16(KC_EQL); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_EQL);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_EQL] = 0;
}


// Dance Left Bracket
void on_dance_LBRC(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_LBRC_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_LBRC] = dance_step(state);
    switch (dance_state[DANCE_LBRC]) {
        case TD_SINGLE_TAP: register_code16(KC_LBRC); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LBRC);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_LBRC);
            break;
        default: break;
    }
}

void dance_LBRC_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_LBRC]) {
        case TD_SINGLE_TAP: unregister_code16(KC_LBRC); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_LBRC);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_LBRC);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_LBRC] = 0;
}


// Dance Right Bracket
void on_dance_RBRC(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_RBRC_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_RBRC] = dance_step(state);
    switch (dance_state[DANCE_RBRC]) {
        case TD_SINGLE_TAP: register_code16(KC_RBRC); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_RBRC);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_RBRC);
            break;
        default: break;
    }
}

void dance_RBRC_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_RBRC]) {
        case TD_SINGLE_TAP: unregister_code16(KC_RBRC); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_LCTL);
            unregister_code(KC_RBRC);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_RBRC);
            break;
        default: break;
    }
    dance_state[DANCE_RBRC] = 0;
}


// Dance 0
void on_dance_0(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_0] = dance_step(state);
    switch (dance_state[DANCE_0]) {
        case TD_SINGLE_TAP: register_code16(KC_0); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_0);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_0);
            break;
        default: break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_0]) {
        case TD_SINGLE_TAP: unregister_code16(KC_0); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_0);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_0);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
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
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_1);
        default: break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_1]) {
        case TD_SINGLE_TAP: unregister_code16(KC_1); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_1);
            unregister_code(KC_LCTL);
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
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_2);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_2);
            break;
        default: break;
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_2]) {
        case TD_SINGLE_TAP: unregister_code16(KC_2); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_2);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_2);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
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
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_3);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_3);
            break;
        default: break;
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_3]) {
        case TD_SINGLE_TAP: unregister_code16(KC_3); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_3);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_3);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_3] = 0;
}


// Dance 5
void on_dance_5(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {

    dance_state[DANCE_5] = dance_step(state);
    switch (dance_state[DANCE_5]) {
        case TD_SINGLE_TAP: register_code16(KC_5); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_5);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_5);
            break;
        default: break;
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_5]) {
        case TD_SINGLE_TAP: unregister_code16(KC_5); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_5);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_5);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_5] = 0;
}


// Dance 7
void on_dance_7(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_7] = dance_step(state);
    switch (dance_state[DANCE_7]) {
        case TD_SINGLE_TAP: register_code16(KC_7); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_7);
            break;
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
        case TD_DOUBLE_TAP:
            unregister_code(KC_7);
            unregister_code(KC_LCTL);
            break;
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
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_8);
            break;
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
        case TD_DOUBLE_TAP:
            unregister_code(KC_8);
            unregister_code(KC_LCTL);
            break;
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
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_A);
            break;
        default: break;
    }
}

void dance_A_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_A]) {
        case TD_SINGLE_TAP: unregister_code16(KC_A); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_A);
            unregister_code(KC_LCTL);
            break;
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
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_B);
            break;
        default: break;
    }
}

void dance_B_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_B]) {
        case TD_SINGLE_TAP: unregister_code16(KC_B); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_B);
            unregister_code(KC_LCTL);
            break;
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
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_C);
            break;
        default: break;
    }
}

void dance_C_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_C]) {
        case TD_SINGLE_TAP: unregister_code16(KC_C); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_C);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_C] = 0;
}


// Dance D
void on_dance_D(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_D_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_D] = dance_step(state);
    switch (dance_state[DANCE_D]) {
        case TD_SINGLE_TAP: register_code16(KC_D); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_D);
            break;
        default: break;
    }
}

void dance_D_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_D]) {
        case TD_SINGLE_TAP: unregister_code16(KC_D); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_D);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_D] = 0;
}


// Dance E
void on_dance_E(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_E_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_E] = dance_step(state);
    switch (dance_state[DANCE_E]) {
        case TD_SINGLE_TAP: register_code16(KC_E); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_E);
            break;
        default: break;
    }
}

void dance_E_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_E]) {
        case TD_SINGLE_TAP: unregister_code16(KC_E); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_E);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_E] = 0;
}


// Dance F
void on_dance_F(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_F_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_F] = dance_step(state);
    switch (dance_state[DANCE_F]) {
        case TD_SINGLE_TAP: register_code16(KC_F); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_F);
            break;
        default: break;
    }
}

void dance_F_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_F]) {
        case TD_SINGLE_TAP: unregister_code16(KC_F); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_F);
            unregister_code(KC_LCTL);
            break;
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
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_G);
            break;
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
        case TD_DOUBLE_TAP:
            unregister_code(KC_G);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP: 
            unregister_code(KC_G);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_G] = 0;
}


// Dance I
void on_dance_I(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_I_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_I] = dance_step(state);
    switch (dance_state[DANCE_I]) {
        case TD_SINGLE_TAP: register_code16(KC_I); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_I);
            break;
        case TD_TRIPLE_TAP: 
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_I);
            break;
        default: break;
    }
}

void dance_I_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_I]) {
        case TD_SINGLE_TAP: unregister_code16(KC_I); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_I);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP: 
            unregister_code(KC_I);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_I] = 0;
}


// Dance N
void on_dance_N(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_N_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_N] = dance_step(state);
    switch (dance_state[DANCE_N]) {
        case TD_SINGLE_TAP: register_code16(KC_N); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_N);
            break;
        case TD_TRIPLE_TAP: 
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_N);
            break;
        default: break;
    }
}

void dance_N_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_N]) {
        case TD_SINGLE_TAP: unregister_code16(KC_N); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_N);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP: 
            unregister_code(KC_N);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_N] = 0;
}


// Dance O
void on_dance_O(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_O_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_O] = dance_step(state);
    switch (dance_state[DANCE_O]) {
        case TD_SINGLE_TAP: register_code16(KC_O); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_O);
            break;
        case TD_TRIPLE_TAP: 
            register_code(KC_LSFT);
            register_code(KC_O);
            break;
        default: break;
    }
}

void dance_O_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_O]) {
        case TD_SINGLE_TAP: unregister_code16(KC_O); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_O);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP: 
            unregister_code(KC_O);
            unregister_code(KC_LSFT);
            break;
        default: break;
    }
    dance_state[DANCE_O] = 0;
}


// Dance Q
void on_dance_Q(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_Q_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_Q] = dance_step(state);
    switch (dance_state[DANCE_Q]) {
        case TD_SINGLE_TAP: register_code16(KC_Q); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_Q);
            break;
        default: break;
    }
}

void dance_Q_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_Q]) {
        case TD_SINGLE_TAP: unregister_code16(KC_Q); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_Q);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_Q] = 0;
}


// Dance R
void on_dance_R(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_R_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_R] = dance_step(state);
    switch (dance_state[DANCE_R]) {
        case TD_SINGLE_TAP: register_code16(KC_R); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_R);
        default: break;
    }
}

void dance_R_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_R]) {
        case TD_SINGLE_TAP: unregister_code16(KC_R); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_R);
            unregister_code(KC_LCTL);
        default: break;
    }
    dance_state[DANCE_R] = 0;
}


// Dance S
void on_dance_S(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_S_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_S] = dance_step(state);
    switch (dance_state[DANCE_S]) {
        case TD_SINGLE_TAP: register_code16(KC_S); break;
        case TD_DOUBLE_TAP: 
            register_code(KC_LCTL);
            register_code(KC_S);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_S);
            break;
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
        case TD_DOUBLE_TAP: 
            unregister_code(KC_S);
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_S);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP: 
            unregister_code(KC_S);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_S] = 0;
}


// Dance T
void on_dance_T(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_T_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_T] = dance_step(state);
    switch (dance_state[DANCE_T]) {
        case TD_SINGLE_TAP: register_code16(KC_T); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_T);
        default: break;
    }
}

void dance_T_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_T]) {
        case TD_SINGLE_TAP: unregister_code16(KC_T); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_T);
            unregister_code(KC_LCTL);
        default: break;
    }
    dance_state[DANCE_T] = 0;
}


// Dance V
void on_dance_V(tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_V_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_V] = dance_step(state);
    switch (dance_state[DANCE_V]) {
        case TD_SINGLE_TAP: register_code16(KC_V); break;
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_V);
            break;
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
        case TD_DOUBLE_TAP:
            unregister_code(KC_V);
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_V);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP: 
            unregister_code(KC_V);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
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
        case TD_DOUBLE_TAP: 
            register_code(KC_LCTL);
            register_code(KC_W); 
            break;
        default: break;
    }
}

void dance_W_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_W]) {
        case TD_SINGLE_TAP: unregister_code16(KC_W); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_W); 
            unregister_code(KC_LCTL);
            break;
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
            register_code(KC_LCTL);
            register_code(KC_X);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_LSFT);
            register_code(KC_X);
        default: break;
    }
}

void dance_X_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_X]) {
        case TD_SINGLE_TAP: unregister_code16(KC_X); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_X);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_X);
            unregister_code(KC_LSFT);
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
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_Y);
        case TD_TRIPLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_Y);
            break;
        default: break;
    }
}

void dance_Y_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_Y]) {
        case TD_SINGLE_TAP: unregister_code16(KC_Y); break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_Y);
            unregister_code(KC_LCTL);
        case TD_TRIPLE_TAP:
            unregister_code(KC_Y);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            break;
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
        case TD_DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(KC_Z);
            break;
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
        case TD_DOUBLE_TAP:
            unregister_code(KC_Z);
            unregister_code(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_Z);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            break;
        default: break;
    }
    dance_state[DANCE_Z] = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_MINS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_MINS, dance_MINS_finished, dance_MINS_reset),
        [DANCE_EQL] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_EQL, dance_EQL_finished, dance_EQL_reset),
        [DANCE_LBRC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_LBRC, dance_LBRC_finished, dance_LBRC_reset),
        [DANCE_RBRC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_RBRC, dance_RBRC_finished, dance_RBRC_reset),
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_A] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_A, dance_A_finished, dance_A_reset),
        [DANCE_B] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_B, dance_B_finished, dance_B_reset),
        [DANCE_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_C, dance_C_finished, dance_C_reset),
        [DANCE_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_D, dance_D_finished, dance_D_reset),
        [DANCE_E] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_E, dance_E_finished, dance_E_reset),
        [DANCE_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_F, dance_F_finished, dance_F_reset),
        [DANCE_G] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_G, dance_G_finished, dance_G_reset),
        [DANCE_I] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_I, dance_I_finished, dance_I_reset),
        [DANCE_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_N, dance_N_finished, dance_N_reset),
        [DANCE_O] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_O, dance_O_finished, dance_O_reset),
        [DANCE_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Q, dance_Q_finished, dance_Q_reset),
        [DANCE_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_R, dance_R_finished, dance_R_reset),
        [DANCE_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_S, dance_S_finished, dance_S_reset),
        [DANCE_T] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_T, dance_T_finished, dance_T_reset),
        [DANCE_V] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_V, dance_V_finished, dance_V_reset),
        [DANCE_W] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_W, dance_W_finished, dance_W_reset),
        [DANCE_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_X, dance_X_finished, dance_X_reset),
        [DANCE_Y] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Y, dance_Y_finished, dance_Y_reset),
        [DANCE_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_Z, dance_Z_finished, dance_Z_reset),
};

// Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain Qwerty without layer switching
     *         ,---------------. ,---------------. ,---------------.
     *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
     * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
     * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
     * |-----------------------------------------------------------| |-----------| |---------------| |-------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
     * |-----------------------------------------------------------| `-----------' |---------------| |-------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
     * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
     * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
     * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
     * `-----------------------------------------------------------' `-----------' `---------------' `-------'
     */
    [BASE] = LAYOUT_all(
                KC_F13,         KC_F14,         KC_F15,         KC_F16,         KC_F17,         KC_F18, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
    KC_ESC,     KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,               KC_PSCR, KC_SCRL, KC_PAUS,    KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR,     KC_HELP,
    KC_GRV,     TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    KC_4,           TD(DANCE_5),    KC_6,   TD(DANCE_7),   TD(DANCE_8),    KC_9,    TD(DANCE_0),    KC_MINS, KC_EQL,  KC_INT3, KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,    KC_STOP, KC_AGIN,
    KC_TAB,     TD(DANCE_Q),    TD(DANCE_W),    TD(DANCE_E),    TD(DANCE_R),    TD(DANCE_T),    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,     KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,    KC_MENU, KC_UNDO,
    KC_CAPS,    TD(DANCE_A),    TD(DANCE_S),    TD(DANCE_D),    TD(DANCE_F),    TD(DANCE_G),    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_NUHS, KC_ENT,                                    KC_P4,   KC_P5,   KC_P6,   KC_PCMM,    KC_SLCT, KC_COPY,
    KC_LSFT,    KC_NUBS,        TD(DANCE_Z),    TD(DANCE_X),    TD(DANCE_C),    TD(DANCE_V),    KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_INT1, KC_RSFT,              KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PEQL,    KC_EXEC, KC_PSTE,
    KC_LCTL,    KC_LCTL,        KC_LALT,        KC_INT5,        KC_LNG2,        KC_SPC,         KC_LNG1, KC_INT4, KC_INT2, KC_LALT, KC_LCTL, KC_APP,  KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT, KC_PENT,    KC_FIND, KC_CUT
    ),
};

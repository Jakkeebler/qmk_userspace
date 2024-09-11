#pragma once

#include QMK_KEYBOARD_H

// Layer Declaration
enum sofle_layers {
    _QWERTY,
    _ILSTR,
    _SWITCH,
    _FUNCPAD,
};

// Custom Keycodes Declaration
enum custom_keycodes {
    KC_LAYER = SAFE_RANGE,
    KC_ARTBRD,
    KC_FUNC,
};

// Tap Dance Declaration
enum {
    DANCE_ESC,
    DANCE_ENT,
    DANCE_MINS,
    DANCE_EQL,
    DANCE_LBRC,
    DANCE_RBRC,
    DANCE_F1,
    DANCE_F2,
    DANCE_F3,
    DANCE_F4,
    DANCE_F5,
    DANCE_F6,
    DANCE_F7,
    DANCE_F8,
    DANCE_F9,
    DANCE_F10,
    DANCE_F11,
    DANCE_F12,
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
    DANCE_H,
    DANCE_I,
    DANCE_J,
    DANCE_K,
    DANCE_L,
    DANCE_N,
    DANCE_O,
    DANCE_P,
    DANCE_Q,
    DANCE_R,
    DANCE_S,
    DANCE_T,
    DANCE_V,
    DANCE_W,
    DANCE_X,
    DANCE_Y,
    DANCE_Z,
    DANCE_FUNCPAD,
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

td_state_t dance_state[TAP_DANCE_COUNT];

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

td_state_t dance_step(tap_dance_state_t *state);

// Dance Function Prototypes
void dance_ESC_finished(tap_dance_state_t *state, void *user_data);
void dance_ESC_reset(tap_dance_state_t *state, void *user_data);

void dance_ENT_finished(tap_dance_state_t *state, void *user_data);
void dance_ENT_reset(tap_dance_state_t *state, void *user_data);

void dance_MINS_finished(tap_dance_state_t *state, void *user_data);
void dance_MINS_reset(tap_dance_state_t *state, void *user_data);

void dance_EQL_finished(tap_dance_state_t *state, void *user_data);
void dance_EQL_reset(tap_dance_state_t *state, void *user_data);

void dance_LBRC_finished(tap_dance_state_t *state, void *user_data);
void dance_LBRC_reset(tap_dance_state_t *state, void *user_data);

void dance_RBRC_finished(tap_dance_state_t *state, void *user_data);
void dance_RBRC_reset(tap_dance_state_t *state, void *user_data);

void dance_FUNCPAD_finished(tap_dance_state_t *state, void *user_data);
void dance_FUNCPAD_reset(tap_dance_state_t *state, void *user_data);

// Function Key Dance
void dance_F1_finished(tap_dance_state_t *state, void *user_data);
void dance_F1_reset(tap_dance_state_t *state, void *user_data);

void dance_F2_finished(tap_dance_state_t *state, void *user_data);
void dance_F2_reset(tap_dance_state_t *state, void *user_data);

void dance_F3_finished(tap_dance_state_t *state, void *user_data);
void dance_F3_reset(tap_dance_state_t *state, void *user_data);

void dance_F4_finished(tap_dance_state_t *state, void *user_data);
void dance_F4_reset(tap_dance_state_t *state, void *user_data);

void dance_F5_finished(tap_dance_state_t *state, void *user_data);
void dance_F5_reset(tap_dance_state_t *state, void *user_data);

void dance_F6_finished(tap_dance_state_t *state, void *user_data);
void dance_F6_reset(tap_dance_state_t *state, void *user_data);

void dance_F7_finished(tap_dance_state_t *state, void *user_data);
void dance_F7_reset(tap_dance_state_t *state, void *user_data);

void dance_F8_finished(tap_dance_state_t *state, void *user_data);
void dance_F8_reset(tap_dance_state_t *state, void *user_data);

void dance_F9_finished(tap_dance_state_t *state, void *user_data);
void dance_F9_reset(tap_dance_state_t *state, void *user_data);

void dance_F10_finished(tap_dance_state_t *state, void *user_data);
void dance_F10_reset(tap_dance_state_t *state, void *user_data);

void dance_F11_finished(tap_dance_state_t *state, void *user_data);
void dance_F11_reset(tap_dance_state_t *state, void *user_data);

void dance_F12_finished(tap_dance_state_t *state, void *user_data);
void dance_F12_reset(tap_dance_state_t *state, void *user_data);

// Number Key Dance
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

// Letter Key Dance
void dance_A_finished(tap_dance_state_t *state, void *user_data);
void dance_A_reset(tap_dance_state_t *state, void *user_data);

void dance_B_finished(tap_dance_state_t *state, void *user_data);
void dance_B_reset(tap_dance_state_t *state, void *user_data);

void dance_C_finished(tap_dance_state_t *state, void *user_data);
void dance_C_reset(tap_dance_state_t *state, void *user_data);

void dance_D_finished(tap_dance_state_t *state, void *user_data);
void dance_D_reset(tap_dance_state_t *state, void *user_data);

void dance_E_finished(tap_dance_state_t *state, void *user_data);
void dance_E_reset(tap_dance_state_t *state, void *user_data);

void dance_F_finished(tap_dance_state_t *state, void *user_data);
void dance_F_reset(tap_dance_state_t *state, void *user_data);

void dance_G_finished(tap_dance_state_t *state, void *user_data);
void dance_G_reset(tap_dance_state_t *state, void *user_data);

void dance_H_finished(tap_dance_state_t *state, void *user_data);
void dance_H_reset(tap_dance_state_t *state, void *user_data);

void dance_I_finished(tap_dance_state_t *state, void *user_data);
void dance_I_reset(tap_dance_state_t *state, void *user_data);

void dance_J_finished(tap_dance_state_t *state, void *user_data);
void dance_J_reset(tap_dance_state_t *state, void *user_data);

void dance_K_finished(tap_dance_state_t *state, void *user_data);
void dance_K_reset(tap_dance_state_t *state, void *user_data);

void dance_L_finished(tap_dance_state_t *state, void *user_data);
void dance_L_reset(tap_dance_state_t *state, void *user_data);

void dance_N_finished(tap_dance_state_t *state, void *user_data);
void dance_N_reset(tap_dance_state_t *state, void *user_data);

void dance_O_finished(tap_dance_state_t *state, void *user_data);
void dance_O_reset(tap_dance_state_t *state, void *user_data);

void dance_P_finished(tap_dance_state_t *state, void *user_data);
void dance_P_reset(tap_dance_state_t *state, void *user_data);

void dance_Q_finished(tap_dance_state_t *state, void *user_data);
void dance_Q_reset(tap_dance_state_t *state, void *user_data);

void dance_R_finished(tap_dance_state_t *state, void *user_data);
void dance_R_reset(tap_dance_state_t *state, void *user_data);

void dance_S_finished(tap_dance_state_t *state, void *user_data);
void dance_S_reset(tap_dance_state_t *state, void *user_data);

void dance_T_finished(tap_dance_state_t *state, void *user_data);
void dance_T_reset(tap_dance_state_t *state, void *user_data);

void dance_V_finished(tap_dance_state_t *state, void *user_data);
void dance_V_reset(tap_dance_state_t *state, void *user_data);

void dance_W_finished(tap_dance_state_t *state, void *user_data);
void dance_W_reset(tap_dance_state_t *state, void *user_data);

void dance_X_finished(tap_dance_state_t *state, void *user_data);
void dance_X_reset(tap_dance_state_t *state, void *user_data);

void dance_Y_finished(tap_dance_state_t *state, void *user_data);
void dance_Y_reset(tap_dance_state_t *state, void *user_data);

void dance_Z_finished(tap_dance_state_t *state, void *user_data);
void dance_Z_reset(tap_dance_state_t *state, void *user_data);


bool process_record_user(uint16_t keycode, keyrecord_t *record);
bool encoder_update_user(uint8_t index, bool clockwise);


// OLED Function Protypes
void render_logo(void);
void render_qwerty(void);
void render_illstr(void);
void render_funct(void);
void render_lfthand(void);

void print_status_logo(void);
oled_rotation_t oled_init_user(oled_rotation_t rotation);
bool oled_task_user(void);

extern const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS];

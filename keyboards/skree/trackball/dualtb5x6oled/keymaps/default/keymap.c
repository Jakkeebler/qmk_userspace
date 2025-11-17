// Copyright 2022 QMK (@qmk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "dualtb5x6oled.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum custom_keycodes {
    AUTO_MS_TOG = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                   KC_LBRC, KC_RBRC,                               KC_PLUS, KC_EQL,
                                            KC_SPC,  KC_BSPC,             KC_ENT,  KC_LGUI,
                                                     LOWER,   RAISE,      RAISE,   LOWER
    ),

    [_LOWER] = LAYOUT_5x6(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, _______, _______, _______, _______, KC_LBRC,             KC_RBRC, KC_P7,   KC_P8,   KC_P9,   _______, KC_PLUS,
        _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LPRN,             KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_MINS, KC_PIPE,
        _______, _______, _______, _______, _______, _______,             _______, KC_P1,   KC_P2,   KC_P3,   KC_EQL,  KC_UNDS,
                                   _______, KC_PSCR,                               _______, KC_P0,
                                            _______, _______,             _______, _______,
                                                     _______, _______,    _______, _______
    ),

    [_RAISE] = LAYOUT_5x6(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,             RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______,
        _______, _______, _______, _______, _______, _______,             _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
                                   _______, _______,                               _______, _______,
                                            _______, _______,             _______, _______,
                                                     _______, _______,    _______, _______
    ),

    [_MOUSE] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,             _______, DPI_RMOD,DPI_MOD, S_D_RMOD,S_D_MOD, _______,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        _______, _______, KC_BTN2, KC_BTN3, KC_BTN1, _______,             _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
                                   DRGSCRL, SNIPING,                               SNIPING, DRGSCRL,
                                            AUTO_MS_TOG, _______,         _______, AUTO_MS_TOG,
                                                     _______, _______,    _______, _______
    )
};

#ifdef POINTING_DEVICE_COMBINED
static void check_drag(report_mouse_t* mouse_report) {
    static int16_t scroll_buffer_x = 0;
    static int16_t scroll_buffer_y = 0;

#ifdef CHARYBDIS_DRAGSCROLL_REVERSE_X
    scroll_buffer_x -= mouse_report->x;
#else
    scroll_buffer_x += mouse_report->x;
#endif

#ifdef CHARYBDIS_DRAGSCROLL_REVERSE_Y
    scroll_buffer_y -= mouse_report->y;
#else
    scroll_buffer_y += mouse_report->y;
#endif

    mouse_report->x = 0;
    mouse_report->y = 0;

    if (abs(scroll_buffer_x) > 6) {
        mouse_report->h = scroll_buffer_x > 0 ? 1 : -1;
        scroll_buffer_x = 0;
    }
    if (abs(scroll_buffer_y) > 6) {
        mouse_report->v = scroll_buffer_y > 0 ? 1 : -1;
        scroll_buffer_y = 0;
    }
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    check_drag(&left_report);
    return pointing_device_combine_reports(left_report, right_report);
}
#endif

void pointing_device_init_user(void) {
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_enable(true);
#endif
#ifdef POINTING_DEVICE_COMBINED
    pointing_device_set_cpi_on_side(true, CHARYBDIS_DRAGSCROLL_DPI);  // LEFT
    pointing_device_set_cpi_on_side(false, 2000);                      // RIGHT
#endif
}

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AUTO_MS_TOG:
            if (record->event.pressed) {
                set_auto_mouse_enable(!get_auto_mouse_enable());
            }
            return false;
        default:
            return true;
    }
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_0;
}

static const char PROGMEM logo[] = {
    // 'skree custom logo', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0x8c, 0x8c, 0x8c, 0x8c,
    0x3c, 0x3c, 0x0c, 0x00, 0xe0, 0xf0, 0x80, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x10, 0x00, 0xe0, 0xf0,
    0x30, 0x10, 0x10, 0xb0, 0xf0, 0xe0, 0x00, 0x00, 0xe0, 0xf0, 0x30, 0x30, 0x90, 0x90, 0x98, 0x18,
    0x00, 0xe0, 0xf0, 0x30, 0x30, 0x90, 0x90, 0x98, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0x60, 0x30, 0x38, 0x18, 0x0c, 0x0c, 0x0c, 0x1c, 0x3c, 0x0c, 0xe0, 0xf8, 0x10, 0x00, 0x00,
    0x80, 0xf0, 0x78, 0x00, 0x00, 0xe0, 0xf0, 0xb0, 0x30, 0x30, 0x70, 0x70, 0x00, 0x20, 0x30, 0x30,
    0xb0, 0xf0, 0x30, 0x30, 0x30, 0x10, 0x10, 0x80, 0xc0, 0x60, 0x30, 0x30, 0x38, 0xf0, 0xf0, 0x00,
    0x00, 0xe0, 0xf0, 0xf0, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1e, 0x38, 0x30, 0x30, 0x31, 0x31, 0x19, 0x1b,
    0x0f, 0x06, 0x00, 0x1e, 0x1f, 0x03, 0x07, 0x0e, 0x0c, 0x1c, 0x18, 0x00, 0x00, 0x1c, 0x1f, 0x07,
    0x07, 0x0f, 0x0f, 0x1d, 0x19, 0x18, 0x00, 0x3e, 0x3f, 0x13, 0x1b, 0x19, 0x19, 0x19, 0x19, 0x00,
    0x3e, 0x3f, 0x13, 0x1b, 0x19, 0x19, 0x19, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1f,
    0x39, 0x30, 0x30, 0x30, 0x30, 0x18, 0x18, 0x18, 0x08, 0x00, 0x00, 0x1f, 0x19, 0x18, 0x18, 0x18,
    0x1f, 0x0f, 0x00, 0x1e, 0x1e, 0x19, 0x19, 0x1b, 0x1b, 0x1b, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00,
    0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1f, 0x19, 0x18, 0x18, 0x0c, 0x07, 0x03, 0x00, 0x1c,
    0x0f, 0x03, 0x03, 0x1f, 0x1e, 0x07, 0x03, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static void render_logo(void) {
    oled_write_raw_P(logo, sizeof(logo));
}

bool oled_task_user(void) {
    oled_set_cursor(0, 3);
    if (is_keyboard_left()) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR(" BASE\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("LOWER\n"), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("RAISE\n"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("MOUSE\n"), false);
                break;
            default:
                oled_write_ln_P(PSTR("Undef"), false);
        }

        oled_set_cursor(2, 7);
        oled_write_P(PSTR("WPM "), false);
        oled_set_cursor(1, 8);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);

        oled_set_cursor(0, 9);
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock    ? PSTR("NUMLK \n") : PSTR("      \n"), false);
        oled_write_P(led_state.caps_lock   ? PSTR("CAPLK \n") : PSTR("      \n"), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCRLK \n") : PSTR("      \n"), false);
    } else {
        oled_set_cursor(0, 0);
        render_logo();
        oled_scroll_left();
    }
    return false;
}
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LOWER]  = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_RAISE]  = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_MOUSE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

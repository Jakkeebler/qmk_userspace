#include QMK_KEYBOARD_H
#include "travis.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum wyld_keycodes {
    WYLD_AUTO_MS_TOG = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_4x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                        _______,_______,
                                        _______,_______,_______,        _______,_______,_______
        ),

    [_LOWER] = LAYOUT_4x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                        _______,_______,
                                        _______,_______,_______,        _______,_______,_______
        ),

    [_RAISE] = LAYOUT_4x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                        _______,_______,
                                        _______,_______,_______,        _______,_______,_______
        ),
    [3] = LAYOUT_4x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                        _______,_______,
                                        _______,_______,_______,        _______,_______,_______
        ),
    [4] = LAYOUT_4x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                        _______,_______,
                                        _______,_______,_______,        _______,_______,_______
        )
};

// GENERAL

// DUAL TRACKBALL

#ifdef POINTING_DEVICE_COMBINED
report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    check_drag_scroll(&left_report); // updated in trackball.c
    return pointing_device_combine_reports(left_report, right_report);
}
#endif


// AUTOMOUSE LAYERS
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WYLD_AUTO_MS_TOG:
            if (record->event.pressed) {
                set_auto_mouse_enable(!get_auto_mouse_enable());
            }
            return false; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
}
#endif

// ENCODERS
#ifdef ENCODER_MAP_ENABLE
//#if NUM_ENCODERS == 1
//const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//    [_QWERTY] =  { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
//    [_LOWER] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//    [_RAISE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//    [3] =        { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//    [4] =        { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
//};
//#elif NUM_ENCODERS == 2
// TWO ENCODERS
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =  { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_LOWER] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_RAISE] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [3] =        { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [4] =        { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) }
};
//#endif
#endif

// OLED

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_0;
}

static const char PROGMEM wylderbuilds[] = {
    // 'dark wylderbuilds_oled_name', 128x32
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0x40,
    0x40, 0x60, 0x20, 0x20, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0x20, 0x60,
    0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x60, 0x60,
    0x40, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xf0,
    0x00, 0x00, 0xc1, 0xc1, 0x01, 0x01, 0xf1, 0x11, 0x01, 0x01, 0x01, 0x31, 0x60, 0xc0, 0x80, 0xc0,
    0xf0, 0x10, 0x00, 0x00, 0x00, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xc0,
    0x00, 0x01, 0x03, 0x9e, 0xf8, 0x00, 0x00, 0x20, 0xe0, 0xf0, 0x10, 0x30, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x20, 0xf0, 0x30, 0xa0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x98, 0xf0, 0x70,
    0x00, 0x00, 0x00, 0x00, 0xf0, 0x80, 0x00, 0x70, 0xfe, 0x03, 0x00, 0x00, 0xe0, 0xf0, 0x00, 0x00,
    0x00, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x11, 0xf1, 0x11, 0x33, 0x63, 0xc3,
    0x83, 0x01, 0x01, 0xc1, 0xe1, 0x31, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x1f, 0x7c, 0xff, 0x07, 0x7c, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x80, 0xc0, 0x40, 0x40, 0x00, 0x00, 0x00, 0x7f, 0xff,
    0x60, 0x30, 0x18, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x01, 0x7f, 0xf2, 0x82, 0x02, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x7f, 0x0e, 0x1b, 0x70, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0x81, 0xc1, 0x63,
    0x3e, 0x00, 0x00, 0x00, 0x1f, 0x7f, 0x40, 0x40, 0x7f, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00,
    0x00, 0x1f, 0xff, 0x80, 0xc0, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0x60, 0x30, 0x1f,
    0x07, 0x00, 0x00, 0x01, 0x43, 0x44, 0x7c, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static void render_wylderbuilds(void) {
    oled_write_raw_P(wylderbuilds, sizeof(wylderbuilds));
}

bool oled_task_user(void) {
    oled_set_cursor(0, 3);
    if (is_keyboard_left()) {
        //        oled_write_P(PSTR("Layer\n"), false);

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
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }
        oled_set_cursor(2, 7);
        oled_write_P(PSTR("WPM "), false);
        oled_set_cursor(1, 8);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
        // Host Keyboard LED Status

        oled_set_cursor(0, 9);
        led_t led_state = host_keyboard_led_state();

        oled_write_P(led_state.num_lock ? PSTR("NUMLK \n") : PSTR("    \n"), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAPLK \n") : PSTR("    \n"), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCRLK \n") : PSTR("    \n"), false);
    } else {
        // write WPM to right OLED
        oled_set_cursor(0, 0);
        render_wylderbuilds();
        oled_scroll_left();
    }

    return false;
}
#endif

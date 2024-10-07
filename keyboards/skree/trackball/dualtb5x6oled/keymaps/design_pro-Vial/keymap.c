////////////////////////////////////////////////////////////////////
//Need to use Skree Vial Repositorie to compile as he is calling for Wylder Build files
//https://github.com/WainingForests/vial-qmk
///////////////////////////////////////////////////////////////////

#include QMK_KEYBOARD_H
#include "dualtb5x6oled.h"

#define _BASE 0
#define _QWERTY 1
#define _DVORAK 2
#define _COLEMAK 3
#define _ILLUSTRATOR 4
#define _PHOTOSHOP 5
#define _SWITCH 6
#define _FUNCPAD 7
#define _BRACKETS 8
#define _SELECTOR 9
#define _RGB 10
#define _MEDIA 11
#define _MOUSE 12

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum wyld_keycodes {
    WYLD_AUTO_MS_TOG = SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_5x6(
        KC_ESC,     KC_1,   KC_2,   KC_3,       KC_4,       KC_5,           KC_6,               KC_7,   KC_8,       KC_9,   KC_0,       QK_BOOT,
        KC_TAB,     KC_Q,   KC_W,   KC_E,       KC_R,       KC_T,           KC_Y,               KC_U,   KC_I,       KC_O,   KC_P,       KC_NO,
        KC_F15,     KC_A,   KC_S,   KC_D,       KC_F,       KC_G,           KC_H,               KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,   KC_X,   KC_C,       KC_V,       KC_B,           KC_N,               KC_M,   KC_COMM,    KC_DOT, KC_SLSH,    KC_RSFT,
                                    KC_BSPC,    KC_SPC,     KC_ENT,         KC_ENT,             KC_SPC, KC_BSPC,
                                                KC_BTN2,    KC_BTN1,        OSL(_SELECTOR),     KC_NO
    ),

    [_QWERTY] = LAYOUT_5x6(
        KC_ESC,     KC_1,   KC_2,   KC_3,       KC_4,       KC_5,           KC_6,               KC_7,   KC_8,       KC_9,   KC_0,       KC_NO,
        KC_TAB,     KC_Q,   KC_W,   KC_E,       KC_R,       KC_T,           KC_Y,               KC_U,   KC_I,       KC_O,   KC_P,       KC_NO,
        KC_F15,     KC_A,   KC_S,   KC_D,       KC_F,       KC_G,           KC_H,               KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,   KC_X,   KC_C,       KC_V,       KC_B,           KC_N,               KC_M,   KC_COMM,    KC_DOT, KC_SLSH,    KC_RSFT,
                                    KC_BSPC,    KC_SPC,     KC_ENT,         KC_ENT,             KC_SPC, KC_BSPC,
                                                KC_BTN2,    KC_BTN1,        OSL(_SELECTOR),     KC_NO
    ),

    [_DVORAK] = LAYOUT_5x6(
        KC_LBRC,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,            KC_6,              KC_7,   KC_8,   KC_9,   KC_0,       KC_RBRC,
        KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,       KC_F,            KC_G,              KC_C,   KC_R,   KC_L,   KC_SLSH,    KC_EQL,
        KC_A,       KC_O,       KC_E,       KC_U,       KC_I,       KC_D,            KC_H,              KC_T,   KC_N,   KC_S,   KC_MINS,     KC_NO,
        KC_LSFT,    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,            KC_B,              KC_M,   KC_W,   KC_V,   KC_Z,       KC_RSFT,
                                            KC_BSPC,    KC_SPC,     KC_ENT,          KC_ENT,            KC_SPC, KC_BSPC,
                                                        KC_BTN2,    KC_BTN1,         OSL(_SELECTOR),    KC_NO
    ),

    [_COLEMAK] = LAYOUT_5x6(
        KC_ESC,     KC_1,   KC_2,   KC_3,       KC_4,       KC_5,           KC_6,               KC_7,       KC_8,       KC_9,       KC_0,       KC_NO,
        KC_TAB,     KC_Q,   KC_W,   KC_F,       KC_P,       KC_G,           KC_J,               KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_NO,
        KC_F15,     KC_A,   KC_R,   KC_S,       KC_T,       KC_D,           KC_H,               KC_N,       KC_E,       KC_I,       KC_O,       KC_NO,
        KC_LSFT,    KC_Z,   KC_X,   KC_V,       KC_B,       KC_K,           KC_M,               KC_COMM,    KC_DOT,     KC_SLSH,    KC_NO,      KC_RSFT,
                                    KC_BSPC,    KC_SPC,     KC_ENT,         KC_ENT,             KC_SPC,     KC_BSPC,
                                                KC_BTN2,    KC_BTN1,        OSL(_SELECTOR),     KC_NO
    ),

    [_ILLUSTRATOR] = LAYOUT_5x6(
        KC_ESC,     KC_1,   KC_2,   KC_3,       KC_4,       KC_5,           KC_6,               KC_7,   KC_8,       KC_9,   KC_0,       KC_NO,
        KC_TAB,     KC_Q,   KC_W,   KC_E,       KC_R,       KC_T,           KC_Y,               KC_U,   KC_I,       KC_O,   KC_P,       KC_NO,
        KC_F15,     KC_A,   KC_S,   KC_D,       KC_F,       KC_G,           KC_H,               KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,   KC_X,   KC_C,       KC_V,       KC_B,           KC_N,               KC_M,   KC_COMM,    KC_DOT, KC_SLSH,    KC_RSFT,
                                    KC_BSPC,    KC_SPC,     KC_ENT,         KC_ENT,             KC_SPC, KC_BSPC,
                                                KC_BTN2,    KC_BTN1,        OSL(_SELECTOR),     KC_NO
    ),

    [_PHOTOSHOP] = LAYOUT_5x6(
        KC_ESC,     KC_1,   KC_2,   KC_3,       KC_4,       KC_5,           KC_6,               KC_7,   KC_8,       KC_9,   KC_0,       KC_NO,
        KC_TAB,     KC_Q,   KC_W,   KC_E,       KC_R,       KC_T,           KC_Y,               KC_U,   KC_I,       KC_O,   KC_P,       KC_NO,
        KC_F15,     KC_A,   KC_S,   KC_D,       KC_F,       KC_G,           KC_H,               KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,   KC_X,   KC_C,       KC_V,       KC_B,           KC_N,               KC_M,   KC_COMM,    KC_DOT, KC_SLSH,    KC_RSFT,
                                    KC_BSPC,    KC_SPC,     KC_ENT,         KC_ENT,             KC_SPC, KC_BSPC,
                                                KC_BTN2,    KC_BTN1,        OSL(_SELECTOR),     KC_NO
    ),

    [_SWITCH] = LAYOUT_5x6(
        KC_ESC,     KC_6,   KC_7,   KC_8,       KC_9,       KC_0,           KC_1,               KC_2,   KC_3,       KC_4,   KC_5,   KC_NO,
        KC_TAB,     KC_Y,   KC_U,   KC_I,       KC_O,       KC_P,           KC_Q,               KC_W,   KC_E,       KC_R,   KC_T,   KC_NO,
        KC_F15,     KC_H,   KC_J,   KC_K,       KC_L,       KC_SCLN,        KC_A,               KC_S,   KC_D,       KC_F,   KC_G,   KC_QUOT,
        KC_LSFT,    KC_Z,   KC_M,   KC_COMM,    KC_DOT,     KC_SLSH,        KC_Z,               KC_X,   KC_C,       KC_V,   KC_B,   KC_RSFT,
                                    KC_BSPC,    KC_SPC,     KC_ENT,         KC_ENT,             KC_SPC, KC_BSPC,
                                                KC_BTN2,    KC_BTN1,        OSL(_SELECTOR),     KC_NO
    ),

    [_FUNCPAD] = LAYOUT_5x6(
        KC_ESC,     KC_F1,  KC_F2,      KC_F3,      KC_F4,      KC_F5,          KC_NO,              KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_TAB,     KC_F6,  KC_F7,      KC_F8,      KC_F9,      KC_F10,         KC_NO,              KC_7,   KC_8,   KC_9,   KC_NO,  KC_NO,
        KC_F15,     KC_F11, KC_NO,      KC_UP,      KC_NO,      KC_F12,         KC_NO,              KC_4,   KC_5,   KC_6,   KC_NO,  KC_NO,
        KC_LSFT,    KC_NO,  KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_NO,          KC_NO,              KC_1,   KC_2,   KC_3,   KC_NO,  KC_NO,
                                        KC_BSPC,    KC_SPC,     KC_ENT,         KC_ENT,             KC_0,   KC_DOT,
                                                    KC_NO,      KC_NO,          OSL(_SELECTOR),     KC_NO
    ),

    [_BRACKETS] = LAYOUT_5x6(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,            KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,            KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,            KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,            KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                                KC_NO,  KC_NO,  KC_NO,            KC_NO,    KC_NO,  KC_NO,
                                        KC_NO,  KC_NO,            KC_NO,    KC_NO
    ),

    [_SELECTOR] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,            _______,_______,            _______,            _______,        _______,_______,
        _______,_______,_______,_______,_______,_______,            _______,TO(_RGB),           TO(_MEDIA),         TO(_MOUSE),     _______,_______,
        _______,_______,_______,_______,_______,_______,            _______,TO(_ILLUSTRATOR),   TO(_PHOTOSHOP),     TO(_SWITCH),    _______,_______,
        _______,_______,_______,_______,_______,_______,            _______,TO(_QWERTY),        TO(_DVORAK),        TO(_COLEMAK),   _______,_______,
                                _______,_______,_______,            _______,TO(_BASE),          _______,
                                        _______,_______,            _______,_______
    ),

    [_RGB] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,            _______,_______,_______,
                                        _______,_______,            _______,_______
    ),

    [_MEDIA] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,            _______,_______,_______,
                                        _______,_______,            _______,_______
    ),

    [_MOUSE] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,            _______,    _______,    _______,    _______,    _______,_______,
        _______,_______,_______,_______,_______,_______,            _______,    _______,    _______,    _______,    _______,_______,
        _______,_______,_______,_______,_______,_______,            _______,    KC_BTN1,    KC_BTN2,    KC_BTN3,    _______,_______,
        _______,_______,_______,_______,_______,_______,            _______,    _______,    _______,    _______,    _______,_______,
                                _______,_______,_______,            _______,    _______,    _______,
                                        _______,_______,            _______,    _______
        )
};

#ifdef POINTING_DEVICE_COMBINED
static void check_drag(report_mouse_t* mouse_report) {
    static int16_t scroll_buffer_x = 0;
    static int16_t scroll_buffer_y = 0;

#    ifdef CHARYBDIS_DRAGSCROLL_REVERSE_X
    scroll_buffer_x -= mouse_report->x;
#    else
    scroll_buffer_x += mouse_report->x;
#    endif  // CHARYBDIS_DRAGSCROLL_REVERSE_X
#    ifdef CHARYBDIS_DRAGSCROLL_REVERSE_Y
    scroll_buffer_y -= mouse_report->y;
#    else
    scroll_buffer_y += mouse_report->y;
#    endif  // CHARYBDIS_DRAGSCROLL_REVERSE_Y
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
    check_drag(&left_report); // updated in trackball.c
    return pointing_device_combine_reports(left_report, right_report);
}
#endif


void pointing_device_init_user(void) {
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
#endif
#ifdef POINTING_DEVICE_COMBINED
    pointing_device_set_cpi_on_side(true, CHARYBDIS_DRAGSCROLL_DPI); // LEFT
    pointing_device_set_cpi_on_side(false, 2000);  // RIGHT
#endif// always required before the auto mouse feature will work
}

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
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


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_0;
}

static const char PROGMEM wylderbuilds[] = {
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

static void render_wylderbuilds(void) {
    oled_write_raw_P(wylderbuilds, sizeof(wylderbuilds));
}

bool oled_task_user(void) {
    oled_set_cursor(0, 3);
    if (is_keyboard_left()) {
//        oled_write_P(PSTR("Layer\n"), false);

        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_P(PSTR("BASE\n"), false);
                break;
            case _QWERTY:
                oled_write_P(PSTR("QWERT\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("DVORK\n"), false);
                break;
            case _COLEMAK:
                oled_write_P(PSTR("COLMK\n"), false);
                break;
            case _ILLUSTRATOR:
                oled_write_P(PSTR("ILSTR\n"), false);
                break;
            case _PHOTOSHOP:
                oled_write_P(PSTR("PHTSP\n"), false);
                break;
            case _SWITCH:
                oled_write_P(PSTR("SWTCH\n"), false);
                break;
            case _FUNCPAD:
                oled_write_P(PSTR("FUNC\n"), false);
                break;
            case _BRACKETS:
                oled_write_P(PSTR("BRCKT\n"), false);
                break;
            case _SELECTOR:
                oled_write_P(PSTR("SLECT\n"), false);
                break;
            case _RGB:
                oled_write_P(PSTR("RGB\n"), false);
                break;
            case _MEDIA:
                oled_write_P(PSTR("MEDIA\n"), false);
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





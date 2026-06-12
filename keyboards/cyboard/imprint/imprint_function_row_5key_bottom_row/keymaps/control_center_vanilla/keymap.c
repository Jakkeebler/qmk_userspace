/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H

enum layer_names {
	_BASE,
	_FUNC,
	_UTIL,
	_TAP,
	_SWAP,
	_POINTER,
	_WACOM,
	_ONEHAND,
	_L8,
	_L9,
};

enum custom_keycodes {
	CK_F3_L = SAFE_RANGE,
	CK_F3_C,
	CK_F3_R,
	CK_F3_1,
	CK_F3_2,
	CK_F3_3,
};

#ifdef TAP_DANCE_ENABLE
enum td_keys {
	TDK_F1, TDK_F2, TDK_F3, TDK_F4,  TDK_F5,
	TDK_F6, TDK_F7, TDK_F8, TDK_F9,  TDK_F10,
	TDK_1,  TDK_2,  TDK_3,  TDK_4,   TDK_5,
	TDK_6,  TDK_7,  TDK_8,  TDK_9,   TDK_0,
	TDK_A,  TDK_B,  TDK_C,  TDK_D,   TDK_E,
	TDK_F,  TDK_G,  TDK_H,  TDK_I,   TDK_J,
	TDK_K,  TDK_L,  TDK_M,  TDK_N,   TDK_O,
	TDK_P,  TDK_Q,  TDK_R,  TDK_S,   TDK_T,
	TDK_U,  TDK_V,  TDK_W,  TDK_X,   TDK_Y,
	TDK_Z,
	TDK_SCLN, TDK_QUOT, TDK_COMM, TDK_DOT, TDK_SLSH,
	TDK_MINS, TDK_PLUS,
	TDK_ESC_BASE,
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Base layer — standard QWERTY. Left thumb: Tap/Util/Func + MB3/MB2/MB1. Right thumb: Ent/Spc/Bspc + RCtl/RAlt/MEH. */
	[_BASE] = LAYOUT_fun_full_bottom_row(
		TD(TDK_ESC_BASE),	KC_F1,			KC_F2,			KC_F3,			KC_F4,			KC_F5,																					KC_F6,	KC_F7,			KC_F8,			KC_F9,			KC_F10,		    KC_MINS,
		_______,			KC_1,			KC_2,			KC_3,			KC_4,			KC_5,																					KC_6,	KC_7,			KC_8,			KC_9,			KC_0,		    KC_EQL,
		KC_TAB,				KC_Q,			KC_W,			KC_E,			KC_R,			KC_T,																					KC_Y,	KC_U,			KC_I,			KC_O,			KC_P,		    _______,
		KC_DEL,			    LGUI_T(KC_A),	LSFT_T(KC_S),	LALT_T(KC_D),	LCTL_T(KC_F),	KC_G,																					KC_H,	RCTL_T(KC_J),	RALT_T(KC_K),	RSFT_T(KC_L),	KC_SCLN,	    KC_QUOT,
		KC_LSFT,			KC_Z,			KC_X,			KC_C,			KC_V,			KC_B,																					KC_N, 	KC_M,			KC_COMM,		KC_DOT,			KC_SLSH,	    KC_RSFT,
		_______,			KC_END,	        KC_HOME,	    KC_PGDN,	KC_PGUP,			    MS_BTN1,	MS_BTN2,	MS_BTN3,		MO(_UTIL),		KC_ENT,		KC_SPC,   			C(S(KC_TAB)),	C(KC_TAB),	    C(KC_W),		TG(_ONEHAND),   TG(_POINTER),
																									KC_SPC,		MO(_TAP),	MO(_FUNC),      MO(_FUNC),      MO(_TAP),	KC_BSPC
	),

	/* Func layer — F-keys + arrows (left), numpad (right), QK_BOOT on Esc/Mins. */
	[_FUNC] = LAYOUT_fun_full_bottom_row(
		_______,   KC_F1,     KC_F2,          KC_F3,     KC_F4,          KC_F5,                                                                     _______,    _______,   _______,   _______,   _______,		QK_BOOT,
		QK_BOOT,   KC_F6,     KC_F7,          KC_F8,     KC_F9,          KC_F10,                                                                    _______,    _______,   _______,   _______,   _______,		_______,
		_______,   KC_F11,    C(KC_MINS),     _______,   C(KC_EQL),      KC_F12,                                                                    S(KC_9),    KC_7,      KC_8,      KC_9,      S(KC_0),		_______,
		_______,   _______,   _______,        KC_UP,     _______,        _______,                                                                   KC_LBRC,    KC_4,      KC_5,      KC_6,      KC_RBRC,		_______,
		KC_LSFT,   _______,   KC_LEFT,        KC_DOWN,   KC_RIGHT,       _______,                                                                   S(KC_LBRC), KC_1,      KC_2,      KC_3,      S(KC_RBRC),	KC_RSFT,
		_______,   _______,   _______,        _______,   _______,                   _______,   _______,   _______,   KC_MEH,   KC_DOT,    KC_0,                 KC_0,      KC_0,      KC_DOT,	 _______,		_______,
																					_______,   _______,   _______,   KC_RCTL,   KC_RALT,  _______
	),

	/* Layer 2: Util — combos and bracket shortcuts. */
	[_UTIL] = LAYOUT_fun_full_bottom_row(
		TD(TDK_ESC_BASE), TG(_POINTER), _______,    _______,    _______,    _______,                                  _______, _______,    _______, _______,    TG(_POINTER), TG(_SWAP),
		_______, _______, _______,    _______,    _______,    _______,                                           _______, _______,    _______, _______,    _______, _______,
		_______, _______, CK_F3_1,    _______,    CK_F3_2,    CK_F3_3,                                           _______, S(KC_9),    _______, S(KC_0),    _______, _______,
		_______, _______, CK_F3_L,    CK_F3_C,    CK_F3_R,    _______,                                           _______, KC_LBRC,    _______, KC_RBRC,    _______, _______,
		_______, _______, _______,    _______,    _______,    _______,                                           KC_BSLS, S(KC_LBRC), _______, S(KC_RBRC), _______, _______,
		_______, _______, _______,    _______,    _______,      _______, _______, _______,   _______, _______, _______,   _______,    _______, _______,    _______, _______,
																_______, _______, _______,   _______, _______, _______
	),

	/*
	 * Tap layer — alpha/number/function keys mapped to 5-behavior tap dance.
	 * Single tap: Ctrl+KC   | Double tap: Ctrl+Shift+KC
	 * Tap+hold:   Ctrl+Alt+KC | Double tap+hold: Alt+Shift+KC | Triple tap: MEH+KC
	 */
	[_TAP] = LAYOUT_fun_full_bottom_row(
		TD(TDK_ESC_BASE),       TD(TDK_F1),   TD(TDK_F2),   TD(TDK_F3),   TD(TDK_F4),   TD(TDK_F5),                                              TD(TDK_F6),   TD(TDK_F7),   TD(TDK_F8),   TD(TDK_F9),   TD(TDK_F10),  TD(TDK_MINS),
		_______,      TD(TDK_1),    TD(TDK_2),    TD(TDK_3),    TD(TDK_4),    TD(TDK_5),                                                         TD(TDK_6),    TD(TDK_7),    TD(TDK_8),    TD(TDK_9),    TD(TDK_0),   TD(TDK_PLUS),
		KC_TAB,       TD(TDK_Q),    TD(TDK_W),    TD(TDK_E),    TD(TDK_R),    TD(TDK_T),                                                         TD(TDK_Y),    TD(TDK_U),    TD(TDK_I),    TD(TDK_O),    TD(TDK_P),    _______,
		_______,      TD(TDK_A),    TD(TDK_S),    TD(TDK_D),    TD(TDK_F),    TD(TDK_G),                                                         TD(TDK_H),    TD(TDK_J),    TD(TDK_K),    TD(TDK_L),    TD(TDK_SCLN), TD(TDK_QUOT),
		KC_LSFT,      TD(TDK_Z),    TD(TDK_X),    TD(TDK_C),    TD(TDK_V),    TD(TDK_B),                                                         TD(TDK_N),    TD(TDK_M),    TD(TDK_COMM), TD(TDK_DOT),  TD(TDK_SLSH), _______,
		_______,      _______,      _______,      _______,      _______,         _______,   _______,   _______,   _______,   _______,   _______,   _______,      _______,      _______,      _______,      _______,
																				 _______,   _______,   _______,   _______,   _______,   _______
	),

	/* Layer 4: Swap — logical left/right halves swapped from the base layer. */
	[_SWAP] = LAYOUT_fun_full_bottom_row(
		KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_MINS,                                          TD(TDK_ESC_BASE),    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,
		KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_EQL,                                           _______,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,
		KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      _______,                                           KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,
		KC_H,      RCTL_T(KC_J), RALT_T(KC_K), RSFT_T(KC_L), KC_SCLN, KC_QUOT,                                   KC_DEL,    LGUI_T(KC_A), LSFT_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), KC_G,
		KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,                                          KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,
		C(S(KC_TAB)), C(KC_TAB), C(KC_W),   TG(_ONEHAND), MO(_FUNC),    MO(_UTIL), KC_ENT,    KC_SPC,    MS_BTN1,   MS_BTN2,   MS_BTN3,   TG(_SWAP), TG(_POINTER), C(KC_W),   C(S(KC_TAB)), C(KC_TAB),
																			MO(_FUNC), MO(_TAP),  KC_BSPC,   KC_SPC,    MO(_TAP),     MO(_FUNC)
	),

	/* Layer 5: Pointer settings â€” left controls on the left, right controls on the right. */
	[_POINTER] = LAYOUT_fun_full_bottom_row(
		TD(TDK_ESC_BASE), LEFT_DRAGSCROLL_MODE_TOGGLE, LEFT_SNIPING_MODE_TOGGLE, LEFT_POINTER_DEFAULT_DPI_REVERSE, LEFT_POINTER_DEFAULT_DPI_FORWARD, _______,   _______, RIGHT_POINTER_DEFAULT_DPI_REVERSE, RIGHT_POINTER_DEFAULT_DPI_FORWARD, RIGHT_SNIPING_MODE_TOGGLE, RIGHT_DRAGSCROLL_MODE_TOGGLE, TG(_POINTER),
		_______,      LEFT_DRAGSCROLL_MODE,        LEFT_SNIPING_MODE,        LEFT_POINTER_SNIPING_DPI_REVERSE, LEFT_POINTER_SNIPING_DPI_FORWARD, _______,   _______, RIGHT_POINTER_SNIPING_DPI_REVERSE, RIGHT_POINTER_SNIPING_DPI_FORWARD, RIGHT_SNIPING_MODE, RIGHT_DRAGSCROLL_MODE, _______,
		_______,      _______,                      _______,                  _______,                           _______,                           _______,   _______, _______,                           _______,                           _______,            _______,              _______,
		_______,      _______,                      _______,                  _______,                           _______,                           _______,   _______, _______,                           _______,                           _______,            _______,              _______,
		_______,      _______,                      _______,                  _______,                           _______,                           _______,   _______, _______,                           _______,                           _______,            _______,              _______,
		_______,      _______,                      _______,                  _______,                           _______,                           _______,   _______,   _______,   _______,   _______,   _______,   _______,      _______,      _______,      _______,      _______,
																											   _______,   _______,   _______,   _______,   _______,   _______
	),

	/* Wacom layer — copy of _BASE; customize per-key as needed for Wacom workflow. */
	[_WACOM] = LAYOUT_fun_full_bottom_row(
		TD(TDK_ESC_BASE),	KC_F1,			KC_F2,			KC_F3,			KC_F4,			KC_F5,																					KC_F6,	KC_F7,			KC_F8,			KC_F9,			KC_F10,		KC_MINS,
		_______,			KC_1,			KC_2,			KC_3,			KC_4,			KC_5,																					KC_6,	KC_7,			KC_8,			KC_9,			KC_0,		KC_EQL,
		KC_TAB,				KC_Q,			KC_W,			KC_E,			KC_R,			KC_T,																					KC_Y,	KC_U,			KC_I,			KC_O,			KC_P,		_______,
		KC_DEL,				LGUI_T(KC_A),	LSFT_T(KC_S),	LALT_T(KC_D),	LCTL_T(KC_F),	KC_G,																					KC_H,	RCTL_T(KC_J),	RALT_T(KC_K),	RSFT_T(KC_L),	KC_SCLN,	KC_QUOT,
		KC_LSFT,			KC_Z,			KC_X,			KC_C,			KC_V,			KC_B,																					KC_N, 	KC_M,			KC_COMM,		KC_DOT,			KC_SLSH,	KC_RSFT,
		MO(_UTIL),			_______,		_______,		TG(_SWAP),		TG(_POINTER),			MS_BTN1,	MS_BTN2,	MS_BTN3,		KC_RCTL,		KC_ENT,		KC_SPC,   			MO(_UTIL),		_______,		MO(_TAP),		MO(_UTIL),	MO(_FUNC),
																									KC_SPC,		MO(_TAP),	MO(_FUNC),    	C(S(KC_TAB)),	C(KC_TAB),	KC_BSPC
	),

	/* One-hand layer — alphas/numbers blanked; J/K/L become MS_BTN1/2/3; base thumb cluster preserved. */
	[_ONEHAND] = LAYOUT_fun_full_bottom_row(
		TD(TDK_ESC_BASE), KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                                   				KC_NO,   	KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
		KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                                   				KC_NO,   	KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
		KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                                   				KC_NO,   	KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
		KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                                   				KC_NO,   	MS_BTN1,  MS_BTN2,  MS_BTN3,  KC_NO,   KC_NO,
		KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                                   				KC_NO,   	KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
		TG(_ONEHAND), KC_NO,  C(KC_W),   C(S(KC_TAB)), C(KC_TAB),  	MS_BTN1, MS_BTN2, MS_BTN3,   	MO(_UTIL), 		KC_ENT, 	KC_SPC,   			C(S(KC_TAB)), C(KC_TAB), C(KC_W),  KC_NO,     KC_NO,
																	KC_SPC, MO(_TAP), MO(_FUNC), 	MO(_FUNC), 	MO(_TAP), 	KC_BSPC
	),

	/* Layer 8: fully transparent placeholder. */
	[_L8] = LAYOUT_fun_full_bottom_row(
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
													   _______, _______, _______,   _______, _______, _______
	),

	/* Layer 9: fully transparent placeholder. */
	[_L9] = LAYOUT_fun_full_bottom_row(
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
													   _______, _______, _______,   _______, _______, _______
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case CK_F3_L:
			if (record->event.pressed) { register_code(KC_F3); register_code(KC_L); }
			else                       { unregister_code(KC_L); unregister_code(KC_F3); }
			return false;
		case CK_F3_C:
			if (record->event.pressed) { register_code(KC_F3); register_code(KC_C); }
			else                       { unregister_code(KC_C); unregister_code(KC_F3); }
			return false;
		case CK_F3_R:
			if (record->event.pressed) { register_code(KC_F3); register_code(KC_R); }
			else                       { unregister_code(KC_R); unregister_code(KC_F3); }
			return false;
		case CK_F3_1:
			if (record->event.pressed) { register_code(KC_F3); register_code(KC_1); }
			else                       { unregister_code(KC_1); unregister_code(KC_F3); }
			return false;
		case CK_F3_2:
			if (record->event.pressed) { register_code(KC_F3); register_code(KC_2); }
			else                       { unregister_code(KC_2); unregister_code(KC_F3); }
			return false;
		case CK_F3_3:
			if (record->event.pressed) { register_code(KC_F3); register_code(KC_3); }
			else                       { unregister_code(KC_3); unregister_code(KC_F3); }
			return false;
	}
	return true;
}

#if defined(POINTING_DEVICE_ENABLE) && defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
#    ifndef TRACKBALL_JITTER_HOLD_FRAMES
#        define TRACKBALL_JITTER_HOLD_FRAMES 1
#    endif

typedef struct {
	int8_t  armed_direction;
	uint8_t quiet_frames;
} trackball_axis_filter_t;

typedef struct {
	trackball_axis_filter_t x;
	trackball_axis_filter_t y;
} trackball_filter_t;

static void reset_trackball_axis_filter(trackball_axis_filter_t *filter) {
	filter->armed_direction = 0;
	filter->quiet_frames    = 0;
}

// Suppress isolated +/-1 twitches while preserving sustained low-speed motion.
static int8_t filter_trackball_axis(int8_t delta, trackball_axis_filter_t *filter) {
	if (delta == 0) {
		if (filter->quiet_frames < TRACKBALL_JITTER_HOLD_FRAMES) {
			filter->quiet_frames++;
		} else {
			reset_trackball_axis_filter(filter);
		}
		return 0;
	}

	filter->quiet_frames = 0;

	if (delta > 1 || delta < -1) {
		filter->armed_direction = delta > 0 ? 1 : -1;
		return delta;
	}

	if (filter->armed_direction == delta) {
		return delta;
	}

	filter->armed_direction = delta;
	return 0;
}

static void filter_trackball_report(report_mouse_t *report, trackball_filter_t *filter, bool is_left) {
	if (charybdis_get_pointer_dragscroll_enabled(is_left)) {
		reset_trackball_axis_filter(&filter->x);
		reset_trackball_axis_filter(&filter->y);
		return;
	}

	report->x = filter_trackball_axis(report->x, &filter->x);
	report->y = filter_trackball_axis(report->y, &filter->y);
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
	static trackball_filter_t left_filter  = {0};
	static trackball_filter_t right_filter = {0};

	filter_trackball_report(&left_report, &left_filter, true);
	filter_trackball_report(&right_report, &right_filter, false);

	return pointing_device_combine_reports(left_report, right_report);
}
#endif

#ifdef TAP_DANCE_ENABLE

typedef enum {
	TDS_NONE,
	TDS_SINGLE_TAP,
	TDS_DOUBLE_TAP,
	TDS_TRIPLE_TAP,
	TDS_SINGLE_HOLD,
	TDS_DOUBLE_HOLD,
} td_state_t;

typedef struct {
	uint16_t   kc;
	td_state_t state;
} td_kc_data_t;

static td_state_t td_state_for(tap_dance_state_t *state) {
	if (state->count == 1) return (state->interrupted || !state->pressed) ? TDS_SINGLE_TAP : TDS_SINGLE_HOLD;
	if (state->count == 2) return (state->interrupted || !state->pressed) ? TDS_DOUBLE_TAP : TDS_DOUBLE_HOLD;
	return TDS_TRIPLE_TAP;
}

static void td_kc_finished(tap_dance_state_t *state, void *user_data) {
	td_kc_data_t *d = (td_kc_data_t *)user_data;
	d->state = td_state_for(state);
	switch (d->state) {
		case TDS_SINGLE_TAP:  register_code16(LCTL(d->kc));           break;
		case TDS_DOUBLE_TAP:  register_code16(LCTL(LSFT(d->kc)));     break;
		case TDS_TRIPLE_TAP:  register_code16(MEH(d->kc));            break;
		case TDS_SINGLE_HOLD: register_code16(LCTL(LALT(d->kc)));     break;
		case TDS_DOUBLE_HOLD: register_code16(LALT(LSFT(d->kc)));     break;
		default: break;
	}
}

static void td_kc_reset(tap_dance_state_t *state, void *user_data) {
	td_kc_data_t *d = (td_kc_data_t *)user_data;
	switch (d->state) {
		case TDS_SINGLE_TAP:  unregister_code16(LCTL(d->kc));         break;
		case TDS_DOUBLE_TAP:  unregister_code16(LCTL(LSFT(d->kc)));   break;
		case TDS_TRIPLE_TAP:  unregister_code16(MEH(d->kc));          break;
		case TDS_SINGLE_HOLD: unregister_code16(LCTL(LALT(d->kc)));   break;
		case TDS_DOUBLE_HOLD: unregister_code16(LALT(LSFT(d->kc)));   break;
		default: break;
	}
	d->state = TDS_NONE;
}

#define TD_KD(name, kc_val) static td_kc_data_t td_data_##name = {.kc = (kc_val), .state = TDS_NONE}
#define TD_ACT(name)        { .fn = {NULL, td_kc_finished, td_kc_reset}, .user_data = (void *)&td_data_##name }

TD_KD(F1,  KC_F1);  TD_KD(F2,  KC_F2);  TD_KD(F3,  KC_F3);  TD_KD(F4,  KC_F4);  TD_KD(F5,  KC_F5);
TD_KD(F6,  KC_F6);  TD_KD(F7,  KC_F7);  TD_KD(F8,  KC_F8);  TD_KD(F9,  KC_F9);  TD_KD(F10, KC_F10);
TD_KD(1,   KC_1);   TD_KD(2,   KC_2);   TD_KD(3,   KC_3);   TD_KD(4,   KC_4);   TD_KD(5,   KC_5);
TD_KD(6,   KC_6);   TD_KD(7,   KC_7);   TD_KD(8,   KC_8);   TD_KD(9,   KC_9);   TD_KD(0,   KC_0);
TD_KD(A,   KC_A);   TD_KD(B,   KC_B);   TD_KD(C,   KC_C);   TD_KD(D,   KC_D);   TD_KD(E,   KC_E);
TD_KD(F,   KC_F);   TD_KD(G,   KC_G);   TD_KD(H,   KC_H);   TD_KD(I,   KC_I);   TD_KD(J,   KC_J);
TD_KD(K,   KC_K);   TD_KD(L,   KC_L);   TD_KD(M,   KC_M);   TD_KD(N,   KC_N);   TD_KD(O,   KC_O);
TD_KD(P,   KC_P);   TD_KD(Q,   KC_Q);   TD_KD(R,   KC_R);   TD_KD(S,   KC_S);   TD_KD(T,   KC_T);
TD_KD(U,   KC_U);   TD_KD(V,   KC_V);   TD_KD(W,   KC_W);   TD_KD(X,   KC_X);   TD_KD(Y,   KC_Y);
TD_KD(Z,    KC_Z);
TD_KD(SCLN, KC_SCLN); TD_KD(QUOT, KC_QUOT); TD_KD(COMM, KC_COMM); TD_KD(DOT, KC_DOT); TD_KD(SLSH, KC_SLSH);
TD_KD(MINS, KC_MINS); TD_KD(PLUS, KC_PLUS);

// Single tap: Esc. Double tap: jump back to _BASE (clears any active layer).
static void td_esc_base_finished(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		layer_move(_BASE);
	} else {
		tap_code(KC_ESC);
	}
}

tap_dance_action_t tap_dance_actions[] = {
	[TDK_F1]  = TD_ACT(F1),  [TDK_F2]  = TD_ACT(F2),  [TDK_F3]  = TD_ACT(F3),  [TDK_F4]  = TD_ACT(F4),  [TDK_F5]  = TD_ACT(F5),
	[TDK_F6]  = TD_ACT(F6),  [TDK_F7]  = TD_ACT(F7),  [TDK_F8]  = TD_ACT(F8),  [TDK_F9]  = TD_ACT(F9),  [TDK_F10] = TD_ACT(F10),
	[TDK_1]   = TD_ACT(1),   [TDK_2]   = TD_ACT(2),   [TDK_3]   = TD_ACT(3),   [TDK_4]   = TD_ACT(4),   [TDK_5]   = TD_ACT(5),
	[TDK_6]   = TD_ACT(6),   [TDK_7]   = TD_ACT(7),   [TDK_8]   = TD_ACT(8),   [TDK_9]   = TD_ACT(9),   [TDK_0]   = TD_ACT(0),
	[TDK_A]   = TD_ACT(A),   [TDK_B]   = TD_ACT(B),   [TDK_C]   = TD_ACT(C),   [TDK_D]   = TD_ACT(D),   [TDK_E]   = TD_ACT(E),
	[TDK_F]   = TD_ACT(F),   [TDK_G]   = TD_ACT(G),   [TDK_H]   = TD_ACT(H),   [TDK_I]   = TD_ACT(I),   [TDK_J]   = TD_ACT(J),
	[TDK_K]   = TD_ACT(K),   [TDK_L]   = TD_ACT(L),   [TDK_M]   = TD_ACT(M),   [TDK_N]   = TD_ACT(N),   [TDK_O]   = TD_ACT(O),
	[TDK_P]   = TD_ACT(P),   [TDK_Q]   = TD_ACT(Q),   [TDK_R]   = TD_ACT(R),   [TDK_S]   = TD_ACT(S),   [TDK_T]   = TD_ACT(T),
	[TDK_U]   = TD_ACT(U),   [TDK_V]   = TD_ACT(V),   [TDK_W]   = TD_ACT(W),   [TDK_X]   = TD_ACT(X),   [TDK_Y]   = TD_ACT(Y),
	[TDK_Z]    = TD_ACT(Z),
	[TDK_SCLN] = TD_ACT(SCLN), [TDK_QUOT] = TD_ACT(QUOT), [TDK_COMM] = TD_ACT(COMM), [TDK_DOT] = TD_ACT(DOT), [TDK_SLSH] = TD_ACT(SLSH),
	[TDK_MINS] = TD_ACT(MINS), [TDK_PLUS] = TD_ACT(PLUS),
	[TDK_ESC_BASE] = ACTION_TAP_DANCE_FN(td_esc_base_finished),
};

#endif

#ifdef RGB_MATRIX_ENABLE
#define AMBER_R 96
#define AMBER_G 48
#define AMBER_B 0

#define HOME_ROW_R 120
#define HOME_ROW_G 0
#define HOME_ROW_B 98

#define FUNC_KEY_R 60
#define FUNC_KEY_G 0
#define FUNC_KEY_B 180

#define ARROW_R 220
#define ARROW_G 0
#define ARROW_B 180

#define BRACKET_R 220
#define BRACKET_G 180
#define BRACKET_B 0

#define TAP_ACCENT_R 104
#define TAP_ACCENT_G 203
#define TAP_ACCENT_B 227

static bool is_layer_indicator_keycode(uint16_t keycode) {
	return IS_QK_TO(keycode) || IS_QK_MOMENTARY(keycode) || IS_QK_DEF_LAYER(keycode) || IS_QK_TOGGLE_LAYER(keycode) || IS_QK_ONE_SHOT_LAYER(keycode) || IS_QK_LAYER_TAP_TOGGLE(keycode) || IS_QK_LAYER_MOD(keycode) || IS_QK_LAYER_TAP(keycode);
}

static bool is_modifier_indicator_keycode(uint16_t keycode) {
	if (IS_MODIFIER_KEYCODE(keycode) || keycode == KC_MEH || keycode == KC_HYPR) {
		return true;
	}

	if (IS_QK_MOD_TAP(keycode)) {
		return QK_MOD_TAP_GET_MODS(keycode) != 0;
	}

	if (IS_QK_MODS(keycode)) {
		return QK_MODS_GET_MODS(keycode) != 0;
	}

	return false;
}

// Ctrl-based action shortcuts that should read as blue, not amber (they carry a
// Ctrl mod so they'd otherwise trip the modifier-indicator fallback).
static bool is_ctrl_shortcut_keycode(uint16_t keycode) {
	switch (keycode) {
		case C(KC_W):
		case C(KC_TAB):
		case C(S(KC_TAB)):
		case C(KC_MINS):
		case C(KC_EQL):
			return true;
		default:
			return false;
	}
}

static bool is_home_row_mod_keycode(uint16_t keycode) {
	switch (keycode) {
		case LGUI_T(KC_A):
		case LSFT_T(KC_S):
		case LALT_T(KC_D):
		case LCTL_T(KC_F):
		case RCTL_T(KC_J):
		case RALT_T(KC_K):
		case RSFT_T(KC_L):
			return true;
		default:
			return false;
	}
}

// Physical positions to highlight cyan on _TAP. Positional (not keycode-driven)
// because the alpha row uses TD() wrappers that don't pattern-match home-row mods.
static const uint8_t tap_accent_positions[][2] = {
	{6, 5},                                  // Esc
	{3, 4}, {3, 3}, {3, 2}, {3, 1},          // A S D F (left home row)
	{10, 1}, {10, 2}, {10, 3},               // J K L (right home row)
	{2, 5}, {9, 5},                          // Left/Right Shift homes
};

static bool is_tap_accent_position(uint8_t row, uint8_t col) {
	for (uint8_t i = 0; i < ARRAY_SIZE(tap_accent_positions); i++) {
		if (tap_accent_positions[i][0] == row && tap_accent_positions[i][1] == col) return true;
	}
	return false;
}

// Layer-specific keycode coloring. Returns true if the key was colored.
static bool layer_keycode_color(uint8_t layer, uint16_t keycode, uint8_t led) {
	if (layer == _BASE || layer == _SWAP || layer == _WACOM) {
		switch (keycode) {
			case KC_ESC:
#ifdef TAP_DANCE_ENABLE
			case TD(TDK_ESC_BASE):
#endif
						  rgb_matrix_set_color(led, 120, 0, 98);  return true;
			case MS_BTN2: rgb_matrix_set_color(led, 60, 0, 120);  return true;
			case MS_BTN3: rgb_matrix_set_color(led, 120, 47, 94); return true;
			case KC_ENT:  rgb_matrix_set_color(led, 30, 0, 60);   return true;
			case KC_SPC:  rgb_matrix_set_color(led, 0, 28, 60);   return true;
			case KC_BSPC: rgb_matrix_set_color(led, 60, 24, 47);  return true;
			case KC_F1: case KC_F2: case KC_F3: case KC_F4: case KC_F5:
			case KC_F6: case KC_F7: case KC_F8: case KC_F9: case KC_F10:
				rgb_matrix_set_color(led, FUNC_KEY_R, FUNC_KEY_G, FUNC_KEY_B);
				return true;
		}
	} else if (layer == _FUNC) {
		switch (keycode) {
			case QK_BOOT:
				rgb_matrix_set_color(led, RGB_RED);
				return true;
			case KC_F1:  case KC_F2:  case KC_F3:  case KC_F4:  case KC_F5:
			case KC_F6:  case KC_F7:  case KC_F8:  case KC_F9:  case KC_F10:
			case KC_F11: case KC_F12:
				rgb_matrix_set_color(led, FUNC_KEY_R, FUNC_KEY_G, FUNC_KEY_B);
				return true;
			case KC_UP: case KC_DOWN: case KC_LEFT: case KC_RIGHT:
				rgb_matrix_set_color(led, ARROW_R, ARROW_G, ARROW_B);
				return true;
			case S(KC_9): case S(KC_0):
			case KC_LBRC: case KC_RBRC:
			case S(KC_LBRC): case S(KC_RBRC):
				rgb_matrix_set_color(led, BRACKET_R, BRACKET_G, BRACKET_B);
				return true;
		}
#ifdef TAP_DANCE_ENABLE
	} else if (layer == _TAP) {
		switch (keycode) {
			case TD(TDK_F1): case TD(TDK_F2): case TD(TDK_F3): case TD(TDK_F4): case TD(TDK_F5):
			case TD(TDK_F6): case TD(TDK_F7): case TD(TDK_F8): case TD(TDK_F9): case TD(TDK_F10):
				rgb_matrix_set_color(led, FUNC_KEY_R, FUNC_KEY_G, FUNC_KEY_B);
				return true;
		}
#endif
	}
	return false;
}

void keyboard_post_init_user(void) {
	rgb_matrix_enable_noeeprom();
	rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
	rgb_matrix_sethsv_noeeprom(136, 240, 160);
}

layer_state_t layer_state_set_user(layer_state_t state) {
	if (get_highest_layer(state) == _TAP) {
		rgb_matrix_sethsv_noeeprom(220, 255, 220);  // pink base for TAP layer
	} else {
		rgb_matrix_sethsv_noeeprom(136, 240, 160);  // teal-blue for all other layers
	}
	return state;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	uint8_t layer = get_highest_layer(layer_state);

	// Blank underglow / non-key LEDs so only per-key matrix illumination shows.
	for (uint8_t index = led_min; index < led_max; index++) {
		if (!HAS_FLAGS(g_led_config.flags[index], LED_FLAG_KEYLIGHT)) {
			rgb_matrix_set_color(index, RGB_OFF);
		}
	}

	for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
		for (uint8_t col = 0; col < MATRIX_COLS; col++) {
			uint8_t index = g_led_config.matrix_co[row][col];
			if (index == NO_LED || index < led_min || index >= led_max) continue;

			uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){.row = row, .col = col});

			// 0. KC_NO: completely blank, no overlay (skip all subsequent coloring).
			if (keycode == KC_NO) {
				rgb_matrix_set_color(index, RGB_OFF);
				continue;
			}

			// 1. Transparent positions: blank so the underlying solid color doesn't bleed through.
			if (keycode == KC_TRNS) {
				rgb_matrix_set_color(index, RGB_OFF);
			}

			// 2. _TAP positional cyan accents — applied even at KC_TRNS positions for visual
			//    consistency, then overridden by the modifier-amber fallback below for KC_LSFT/KC_RSFT.
			if (layer == _TAP && is_tap_accent_position(row, col)) {
				rgb_matrix_set_color(index, TAP_ACCENT_R, TAP_ACCENT_G, TAP_ACCENT_B);
			}

			if (keycode == KC_TRNS) continue;

			// 3. Layer-specific keycode coloring (BASE/SWAP/WACOM thumb keys, FUNC arrows/F-keys/BOOT, TAP F-keys).
			if (layer_keycode_color(layer, keycode, index)) continue;

			// 4. Generic fallback: home-row mods + Ctrl shortcuts pink, layer/modifier keys amber.
			if (is_home_row_mod_keycode(keycode) || is_ctrl_shortcut_keycode(keycode)) {
				rgb_matrix_set_color(index, HOME_ROW_R, HOME_ROW_G, HOME_ROW_B);
			} else if (is_layer_indicator_keycode(keycode) || is_modifier_indicator_keycode(keycode)) {
				rgb_matrix_set_color(index, AMBER_R, AMBER_G, AMBER_B);
			}
		}
	}

	return false;
}
#endif

/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H

enum layer_names {
	_BASE,
	_FUNC,
	_UTIL,
	_TAP,
	_L4,
	_L5,
	_L6,
	_L7,
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
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Base layer — standard QWERTY. Left thumb: Tap/Util/Func + MB3/MB2/MB1. Right thumb: Ent/Spc/Bspc + RCtl/RAlt/MEH. */
	[_BASE] = LAYOUT_fun_full_bottom_row(
		KC_ESC,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,          																	KC_F6,		KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_MINS,
		_______,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,           																	KC_6, 		KC_7,      KC_8,      KC_9,      KC_0,      KC_EQL,
		KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,           																	KC_Y, 		KC_U,      KC_I,      KC_O,      KC_P,      _______,
		_______,   LGUI_T(KC_A), LSFT_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), KC_G,    																KC_H,		RCTL_T(KC_J), RALT_T(KC_K), RSFT_T(KC_L), KC_SCLN,   KC_QUOT,
		KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,           																	KC_N, 		KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
		_______,   _______,   _______,   _______,   _______,   			MS_BTN1,  MS_BTN2,   MS_BTN3,  	    KC_MEH,   KC_ENT,  KC_SPC,   				    _______,   _______,   _______,   _______,   MO(_FUNC),
		                                                       			MO(_TAP), MO(_FUNC), MO(_UTIL),    	KC_RCTL,   KC_RALT, KC_BSPC
	),

	/* Func layer — F-keys + arrows (left), numpad (right), QK_BOOT on Esc/Mins. */
	[_FUNC] = LAYOUT_fun_full_bottom_row(
		QK_BOOT,   KC_F1,     KC_F2,          KC_F3,     KC_F4,          KC_F5,                                                                   _______,   _______,   _______,   _______,   _______,   QK_BOOT,
		_______,   KC_F6,     KC_F7,          KC_F8,     KC_F9,          KC_F10,                                                                  _______,   _______,   _______,   KC_PSLS,   KC_PAST,   _______,
		_______,   KC_F11,    TD(TDK_MINS),   _______,   TD(TDK_PLUS),   KC_F12,                                                                  _______,   KC_7,      KC_8,      KC_9,      KC_PPLS,   _______,
		_______,   _______,   _______,        KC_UP,     _______,        _______,                                                                 _______,   KC_4,      KC_5,      KC_6,      KC_PMNS,   _______,
		_______,   _______,   KC_LEFT,        KC_DOWN,   KC_RIGHT,       _______,                                                                 _______,   KC_1,      KC_2,      KC_3,      KC_PENT,   KC_RSFT,
		KC_LSFT,   _______,   _______,        _______,   _______,                   _______,   _______,   _______,   KC_MEH,   KC_0,      KC_PDOT,          _______,   KC_0,      KC_PDOT,   KC_PENT,   _______,
		                                                                            _______,   _______,   _______,   KC_RCTL,   KC_RALT,  _______
	),

	/* Layer 2: Util — combos and bracket shortcuts. */
	[_UTIL] = LAYOUT_fun_full_bottom_row(
		_______, _______, _______,    _______,    _______,    _______,                                           _______, _______,    _______, _______,    _______, _______,
		_______, _______, _______,    _______,    _______,    _______,                                           _______, _______,    _______, _______,    _______, _______,
		_______, _______, CK_F3_1,    _______,    CK_F3_2,    CK_F3_3,                                           _______, S(KC_9),    _______, S(KC_0),    _______, _______,
		_______, _______, CK_F3_L,    CK_F3_C,    CK_F3_R,    _______,                                           _______, KC_LBRC,    _______, KC_RBRC,    _______, _______,
		_______, _______, _______,    _______,    _______,    _______,                                           _______, S(KC_LBRC), _______, S(KC_RBRC), _______, _______,
		_______, _______, _______,    _______,    _______,      _______, _______, _______,   _______, _______, _______,   _______,    _______, _______,    _______, _______,
		                                                        _______, _______, _______,   _______, _______, _______
	),

	/*
	 * Tap layer — alpha/number/function keys mapped to 5-behavior tap dance.
	 * Single tap: Ctrl+KC   | Double tap: Ctrl+Shift+KC
	 * Tap+hold:   Ctrl+Alt+KC | Double tap+hold: Alt+Shift+KC | Triple tap: MEH+KC
	 */
	[_TAP] = LAYOUT_fun_full_bottom_row(
		KC_ESC,       TD(TDK_F1),   TD(TDK_F2),   TD(TDK_F3),   TD(TDK_F4),   TD(TDK_F5),                                                        TD(TDK_F6),   TD(TDK_F7),   TD(TDK_F8),   TD(TDK_F9),   TD(TDK_F10),  TD(TDK_MINS),
		_______,      TD(TDK_1),    TD(TDK_2),    TD(TDK_3),    TD(TDK_4),    TD(TDK_5),                                                         TD(TDK_6),    TD(TDK_7),    TD(TDK_8),    TD(TDK_9),    TD(TDK_0),   TD(TDK_PLUS),
		KC_TAB,       TD(TDK_Q),    TD(TDK_W),    TD(TDK_E),    TD(TDK_R),    TD(TDK_T),                                                         TD(TDK_Y),    TD(TDK_U),    TD(TDK_I),    TD(TDK_O),    TD(TDK_P),    _______,
		_______,      TD(TDK_A),    TD(TDK_S),    TD(TDK_D),    TD(TDK_F),    TD(TDK_G),                                                         TD(TDK_H),    TD(TDK_J),    TD(TDK_K),    TD(TDK_L),    TD(TDK_SCLN), TD(TDK_QUOT),
		KC_LSFT,      TD(TDK_Z),    TD(TDK_X),    TD(TDK_C),    TD(TDK_V),    TD(TDK_B),                                                         TD(TDK_N),    TD(TDK_M),    TD(TDK_COMM), TD(TDK_DOT),  TD(TDK_SLSH), _______,
		_______,      _______,      _______,      _______,      _______,         _______,   _______,   _______,   _______,   _______,   _______,   _______,      _______,      _______,      _______,      _______,
		                                                                         _______,   _______,   _______,   _______,   _______,   _______
	),

	/* Layer 4: fully transparent placeholder. */
	[_L4] = LAYOUT_fun_full_bottom_row(
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
		                                               _______, _______, _______,   _______, _______, _______
	),

	/* Layer 5: fully transparent placeholder. */
	[_L5] = LAYOUT_fun_full_bottom_row(
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
		                                               _______, _______, _______,   _______, _______, _______
	),

	/* Layer 6: fully transparent placeholder. */
	[_L6] = LAYOUT_fun_full_bottom_row(
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
		                                               _______, _______, _______,   _______, _______, _______
	),

	/* Layer 7: fully transparent placeholder. */
	[_L7] = LAYOUT_fun_full_bottom_row(
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
		                                               _______, _______, _______,   _______, _______, _______
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
};

#endif

#ifdef RGB_MATRIX_ENABLE
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

	for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
		for (uint8_t col = 0; col < MATRIX_COLS; col++) {
			uint8_t index = g_led_config.matrix_co[row][col];
			if (index != NO_LED && index >= led_min && index < led_max) {
				if (keymap_key_to_keycode(layer, (keypos_t){.row = row, .col = col}) == KC_TRNS) {
					rgb_matrix_set_color(index, RGB_OFF);
				}
			}
		}
	}

	if (layer == _TAP) {
		uint8_t tap_accent_leds[] = {
			g_led_config.matrix_co[6][5],   // Esc
			g_led_config.matrix_co[3][4],   // A  (GUI)
			g_led_config.matrix_co[3][3],   // S  (Shift)
			g_led_config.matrix_co[3][2],   // D  (Alt)
			g_led_config.matrix_co[3][1],   // F  (Ctrl)
			g_led_config.matrix_co[10][1],  // J  (Ctrl)
			g_led_config.matrix_co[10][2],  // K  (Alt)
			g_led_config.matrix_co[10][3],  // L  (Shift)
			g_led_config.matrix_co[2][5],   // Left Shift
			g_led_config.matrix_co[9][5],   // Right Shift
		};
		for (uint8_t i = 0; i < 10; i++) {
			if (tap_accent_leds[i] != NO_LED && tap_accent_leds[i] >= led_min && tap_accent_leds[i] < led_max) {
				rgb_matrix_set_color(tap_accent_leds[i], 104, 203, 227);
			}
		}
	}
	if (layer == _BASE) {
		uint8_t accent_leds[] = {
			g_led_config.matrix_co[6][5],   // Esc
			g_led_config.matrix_co[3][4],   // A  (GUI)
			g_led_config.matrix_co[3][3],   // S  (Shift)
			g_led_config.matrix_co[3][2],   // D  (Alt)
			g_led_config.matrix_co[3][1],   // F  (Ctrl)
			g_led_config.matrix_co[10][1],  // J  (Ctrl)
			g_led_config.matrix_co[10][2],  // K  (Alt)
			g_led_config.matrix_co[10][3],  // L  (Shift)
			g_led_config.matrix_co[2][5],   // Left Shift
			g_led_config.matrix_co[9][5],   // Right Shift
		};
		for (uint8_t i = 0; i < 10; i++) {
			if (accent_leds[i] != NO_LED && accent_leds[i] >= led_min && accent_leds[i] < led_max) {
				rgb_matrix_set_color(accent_leds[i], 120, 0, 98);
			}
		}
		uint8_t btn2_led = g_led_config.matrix_co[0][2];  // MS_BTN2 - purple
		if (btn2_led != NO_LED && btn2_led >= led_min && btn2_led < led_max) {
			rgb_matrix_set_color(btn2_led, 60, 0, 120);
		}
		uint8_t btn3_led = g_led_config.matrix_co[0][1];  // MS_BTN3 - pink
		if (btn3_led != NO_LED && btn3_led >= led_min && btn3_led < led_max) {
			rgb_matrix_set_color(btn3_led, 120, 47, 94);
		}
uint8_t ent_led = g_led_config.matrix_co[7][2];  // KC_ENT - purple
		if (ent_led != NO_LED && ent_led >= led_min && ent_led < led_max) {
			rgb_matrix_set_color(ent_led, 30, 0, 60);
		}
		uint8_t spc_led = g_led_config.matrix_co[7][3];  // KC_SPC - blue
		if (spc_led != NO_LED && spc_led >= led_min && spc_led < led_max) {
			rgb_matrix_set_color(spc_led, 0, 28, 60);
		}
		uint8_t bspc_led = g_led_config.matrix_co[7][7];  // KC_BSPC - pink
		if (bspc_led != NO_LED && bspc_led >= led_min && bspc_led < led_max) {
			rgb_matrix_set_color(bspc_led, 60, 24, 47);
		}
	}
	if (layer == _BASE || layer == _TAP) {
		uint8_t fn_leds[] = {
			g_led_config.matrix_co[6][4],   // F1
			g_led_config.matrix_co[6][3],   // F2
			g_led_config.matrix_co[6][2],   // F3
			g_led_config.matrix_co[6][1],   // F4
			g_led_config.matrix_co[6][0],   // F5
			g_led_config.matrix_co[13][0],  // F6
			g_led_config.matrix_co[13][1],  // F7
			g_led_config.matrix_co[13][2],  // F8
			g_led_config.matrix_co[13][3],  // F9
			g_led_config.matrix_co[13][4],  // F10
		};
		for (uint8_t i = 0; i < 10; i++) {
			if (fn_leds[i] != NO_LED && fn_leds[i] >= led_min && fn_leds[i] < led_max) {
				rgb_matrix_set_color(fn_leds[i], 60, 0, 180);
			}
		}
	}
	if (layer == _FUNC) {
		uint8_t boot_leds[] = {
			g_led_config.matrix_co[6][5],   // left:  FUNC + Esc  = QK_BOOT
			g_led_config.matrix_co[13][5],  // right: FUNC + Mins = QK_BOOT
		};
		for (uint8_t i = 0; i < 2; i++) {
			if (boot_leds[i] != NO_LED && boot_leds[i] >= led_min && boot_leds[i] < led_max) {
				rgb_matrix_set_color(boot_leds[i], RGB_RED);
			}
		}
		uint8_t fkey_leds[] = {
			g_led_config.matrix_co[6][4],   // F1
			g_led_config.matrix_co[6][3],   // F2
			g_led_config.matrix_co[6][2],   // F3
			g_led_config.matrix_co[6][1],   // F4
			g_led_config.matrix_co[6][0],   // F5
			g_led_config.matrix_co[5][4],   // F6
			g_led_config.matrix_co[5][3],   // F7
			g_led_config.matrix_co[5][2],   // F8
			g_led_config.matrix_co[5][1],   // F9
			g_led_config.matrix_co[5][0],   // F10
			g_led_config.matrix_co[4][4],   // F11
			g_led_config.matrix_co[4][0],   // F12
		};
		for (uint8_t i = 0; i < 12; i++) {
			if (fkey_leds[i] != NO_LED && fkey_leds[i] >= led_min && fkey_leds[i] < led_max) {
				rgb_matrix_set_color(fkey_leds[i], 60, 0, 180);
			}
		}
		uint8_t arrow_leds[] = {
			g_led_config.matrix_co[3][2],   // Up
			g_led_config.matrix_co[2][3],   // Left
			g_led_config.matrix_co[2][2],   // Down
			g_led_config.matrix_co[2][1],   // Right
		};
		for (uint8_t i = 0; i < 4; i++) {
			if (arrow_leds[i] != NO_LED && arrow_leds[i] >= led_min && arrow_leds[i] < led_max) {
				rgb_matrix_set_color(arrow_leds[i], 220, 0, 180);
			}
		}
	}
	return false;
}
#endif

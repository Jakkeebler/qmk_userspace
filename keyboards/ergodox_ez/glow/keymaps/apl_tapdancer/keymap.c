#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

uint8_t lastLayer = 0;

enum layers {
  BASE,
  SYMBL,
  VIM,
  LAYERS,
  ILSTR,
  PHTSHP,
  // ... any other layers
};

enum tap_dance_codes {
    DANCE_FUNC,
    DANCE_ESC,
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

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  | 6    |           |  XX  |  XX  |  XX  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  | TD-W |   E  |   R  |   T  |  L2  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  F15   | TD-A | TD-S |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|  Del |           | Meh  |------+------+------+------+------+--------|
 * | LShift | TD-Z | TD-X | TD-C | TD-V |   B  |      |           |      |  TD-N |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LALT |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | F16  | LGui |       | Alt  | 7    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Enter |Space |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox_pretty(
    TD(DANCE_ESC),  KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,         KC_Q,           TD(DANCE_W),    KC_E,           TD(DANCE_R),    TD(DANCE_T),    TO(LAYERS),                                     TG(SYMBL),      KC_Y,           KC_U,           KC_I,           TD(DANCE_O),    KC_P,           KC_BSLASH,
    TD(DANCE_FUNC), TD(DANCE_A),    TD(DANCE_S),    KC_D,           TD(DANCE_F),    KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_LSHIFT,      TD(DANCE_Z),    TD(DANCE_X),    TD(DANCE_C),    TD(DANCE_V),    KC_B,           KC_DELETE,                                      KC_TRANSPARENT, TD(DANCE_N),    KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
    KC_LGUI,       KC_LALT,         KC_MS_BTN2,     KC_LEFT,        KC_RIGHT,                                                                                                       KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    MO(1),
                                                                                                    KC_PGUP,        KC_PGDOWN,      KC_LGUI,        KC_7,
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_END,         KC_PGDOWN,      KC_ENTER,         KC_SPACE
  ),

  /* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [SYMBL] = LAYOUT_ergodox_pretty(
    TD(DANCE_ESC),  KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        TO(LAYERS),                                     KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                                                                       KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F7,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

/* Keymap 3: VIM
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | L-IL |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |L-BAS |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [VIM] = LAYOUT_ergodox_pretty(
    TD(DANCE_ESC),  KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TO(LAYERS),                                     TG(SYMBL),      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    TD(DANCE_FUNC), KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_DELETE,                                      KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
    KC_LGUI,       KC_LALT,         KC_MS_BTN2,     KC_LEFT,        KC_RIGHT,                                                                                                       KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    MO(1),
                                                                                                    KC_PGUP,        KC_PGDOWN,      KC_LGUI,        KC_7,
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_END,         KC_PGDOWN,      KC_ENTER,         KC_SPACE
  ),

/* Keymap 4: Layer Picker
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | L-IL |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |L-BAS |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [LAYERS] = LAYOUT_ergodox_pretty(
    TD(DANCE_ESC),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(BASE),                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(ILSTR),      KC_TRANSPARENT, TO(PHTSHP), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(VIM),        TO(BASE),      KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

/* Keymap 5: Illustrator layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  | TD-2 | TD-3 |   4  |   5  | 6    |           |  XX  |  XX  |  XX  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  | TD-Q | TD-W |   E  |   R  |   T  |  L2  |           |  L1  | TD-Y |   U  |   I  | TD-O |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  F16   | TD-A | TD-S | TD-D | TD-F | TD-G |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|  Del |           | Meh  |------+------+------+------+------+--------|
 * | LShift | TD-Z | TD-X | TD-C | TD-V | TD-B |      |           |      | TD-N |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LALT |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  | TD-7 |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Enter |Space |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [ILSTR] = LAYOUT_ergodox_pretty(
    TD(DANCE_ESC),  TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    KC_TRANSPARENT, TD(DANCE_5),    KC_TRANSPARENT,                                 KC_TRANSPARENT,  KC_TRANSPARENT,     KC_TRANSPARENT,     TD(DANCE_8),    KC_TRANSPARENT, TD(DANCE_0),    KC_TRANSPARENT,
    KC_TAB,         TD(DANCE_Q),    TD(DANCE_W),    TD(DANCE_E),    KC_R,           TD(DANCE_T),    TO(LAYERS),                                     KC_TRANSPARENT,  TD(DANCE_Y),        KC_U,               TD(DANCE_I),    TD(DANCE_O),    KC_P,           KC_TRANSPARENT,
    TD(DANCE_FUNC), TD(DANCE_A),    TD(DANCE_S),    TD(DANCE_D),    TD(DANCE_F),    TD(DANCE_G),                                                                     KC_H,               KC_J,               KC_K,           KC_L,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_SHIFT,       TD(DANCE_Z),    TD(DANCE_X),    TD(DANCE_C),    TD(DANCE_V),    TD(DANCE_B),   KC_TRANSPARENT,                                  KC_TRANSPARENT,  TD(DANCE_N),        KC_M,               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LGUI,        KC_LALT,        KC_MS_BTN2,     KC_LEFT,        KC_RIGHT,                                                                                                      KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    TD(DANCE_MINS), TD(DANCE_EQL),  KC_TRANSPARENT, TD(DANCE_7),
                                                                                                                    TD(DANCE_RBRC), KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_LBRC), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

/* Keymap 6: Photoshop layer - Currently same as Illustrator
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  | TD-2 | TD-3 |   4  |   5  | 6    |           |  XX  |  XX  |  XX  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  | TD-Q | TD-W |   E  |   R  |   T  |  L2  |           |  L1  | TD-Y |   U  |   I  | TD-O |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  F16   | TD-A | TD-S | TD-D | TD-F | TD-G |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|  Del |           | Meh  |------+------+------+------+------+--------|
 * | LShift | TD-Z | TD-X | TD-C | TD-V | TD-B |      |           |      | TD-N |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LALT |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  | TD-7 |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Enter |Space |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [PHTSHP] = LAYOUT_ergodox_pretty(
    TD(DANCE_ESC),  KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TO(LAYERS),                                     TG(SYMBL),      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    TD(DANCE_FUNC), KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_DELETE,                                      KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
    KC_LGUI,        KC_LALT,        KC_MS_BTN2,     KC_LEFT,        KC_RIGHT,                                                                                                       KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    MO(1),
                                                                                                    KC_F16,         KC_LGUI,        KC_LALT,        KC_7,
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_END,         KC_PGDOWN,      KC_ENTER,         KC_SPACE
  ),
};

/* Key Location
*     {29},    {28},   {27},   {26},   {25},         {1},     {2},    {3},    {4},    {5}, 
*     {34},    {33},   {32},   {31},   {30},         {6},     {7},    {8},    {9},    {10}, 
*     {39},    {38},   {37},   {36},   {35},         {11},    {12},   {13},   {14},   {15}, 
*     {44},    {43},   {42},   {41},   {40},         {16},    {17},   {18},   {19},   {20}, 
*     {48},    {47},   {46},   {45},                          {21},   {22},   {23},   {24} 
*
* LED Code Location
*     {1},     {2},    {3},    {4},    {5},          {6},    {7},    {8},    {9},    {10}, 
*     {11},    {12},   {13},   {14},   {15},         {16},   {17},   {18},   {19},   {20}, 
*     {21},    {22},   {23},   {24},   {25},         {26},   {27},   {28},   {29},   {30}, 
*     {31},    {32},   {33},   {34},   {35},         {36},   {37},   {38},   {39},   {40}, 
*     {41},    {42},   {43},   {44},                         {45},   {46},   {47},   {48}
*/

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [BASE] = { 
        {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255},          {234,255,255}, {234,255,255}, {234,255,255}, {140,255,255}, {234,255,255}, 
        {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255},          {140,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, 
        {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255},          {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {140,255,255}, 
        {140,255,255}, {234,255,255}, {140,255,255}, {234,255,255}, {234,255,255},          {140,255,255}, {234,255,255}, {140,255,255}, {140,255,255}, {234,255,255}, 
        {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255},                                        {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255} },

    [SYMBL] = { 
        {190,255,255}, {190,255,255}, {190,255,255}, {190,255,255}, {190,255,255},          {215,255,255}, {137,255,255}, {137,255,255}, {137,255,255}, {252,255,255}, 
        {215,255,255}, {137,255,255}, {137,255,255}, {137,255,255}, {252,255,255},          {215,255,255}, {137,255,255}, {137,255,255}, {137,255,255}, {252,255,255}, 
        {215,255,255}, {252,255,255}, {137,255,255}, {252,255,255}, {190,255,255},          {190,255,255}, {190,255,255}, {190,255,255}, {190,255,255}, {215,255,255}, 
        {215,255,255}, {215,255,255}, {215,255,255}, {215,255,255}, {215,255,255},          {215,255,255}, {215,255,255}, {215,255,255}, {215,255,255}, {215,255,255}, 
        {215,255,255}, {215,255,255}, {215,255,255}, {215,255,255},                                        {215,255,255}, {215,255,255}, {215,255,255}, {215,255,255} },

    [VIM] = { 
        {85,255,255},  {85,255,255},  {85,255,255},  {85,255,255}, {85,255,255},            {85,255,255}, {85,255,255}, {140,255,255},  {140,255,255},  {85,255,255}, 
        {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {85,255,255},           {85,255,255}, {85,255,255}, {85,255,255},   {85,255,255},   {85,255,255}, 
        {85,255,255},  {85,255,255},  {85,255,255},  {85,255,255}, {85,255,255},            {85,255,255}, {85,255,255}, {85,255,255},   {85,255,255},   {85,255,255},
        {85,255,255},  {140,255,255}, {140,255,255}, {85,255,255}, {85,255,255},            {85,255,255}, {85,255,255}, {85,255,255},   {140,255,255},  {140,255,255}, 
        {85,255,255},  {85,255,255},  {85,255,255},  {85,255,255},                                        {85,255,255}, {85,255,255},   {85,255,255},   {85,255,255} },

    [LAYERS] = { 
        {0,0,0},      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},            {0,0,0}, {0,0,0}, {21,255,255},     {0,0,0}, {120,255,255}, 
        {0,0,0},      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},            {0,0,0}, {0,0,0}, {0,0,0},          {0,0,0}, {0,0,0}, 
        {0,0,0},      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},            {0,0,0}, {0,0,0}, {0,0,0},          {0,0,0}, {0,0,0},
        {0,0,0},      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},            {0,0,0}, {0,0,0}, {0,0,0},          {0,0,0}, {140,255,255}, 
        {78,255,255}, {0,0,0}, {0,0,0}, {0,0,0},                              {0,0,0}, {0,0,0},          {0,0,0}, {0,0,0} },

    [ILSTR] = { 
        {21,255,255},   {21,255,255},   {120,255,255},  {21,255,255},   {120,255,255},           {120,255,255},  {21,255,255},   {120,255,255},  {120,255,255},  {21,255,255}, 
        {21,255,255},   {21,255,255},   {21,255,255},   {21,255,255},   {21,255,255},            {120,255,255},  {21,255,255},   {21,255,255},   {21,255,255},   {21,255,255}, 
        {21,255,255},   {21,255,255},   {21,255,255},   {21,255,255},   {120,255,255},           {21,255,255},   {120,255,255},  {120,255,255},  {120,255,255},  {21,255,255}, 
        {21,255,255},   {120,255,255},  {120,255,255},  {120,255,255},  {120,255,255},           {120,255,255},  {120,255,255},  {120,255,255},  {120,255,255},  {120,255,255}, 
        {120,255,255},  {120,255,255},  {120,255,255},  {120,255,255},                                           {21,255,255},   {21,255,255},   {21,255,255},   {21,255,255} },

    [PHTSHP] = { 
        {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255},           {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, 
        {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255},           {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, 
        {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255},           {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, 
        {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255},           {120,255,255}, {120,255,255}, {200,255,255}, {200,255,255}, {120,255,255}, 
        {200,255,255}, {200,255,255}, {200,255,255}, {200,255,255},                                         {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
      case 0:
          set_layer_color(0);
          break;
      case 1:
          set_layer_color(1);
          break;
      case 2:
          set_layer_color(2);
          break;
      case 3:
          set_layer_color(3);
          break;
      case 4:
          set_layer_color(4);
          break;
      case 5:
          set_layer_color(5);
          break;
      case 6:
          set_layer_color(6);
          break;
      default:
          if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
          break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

uint8_t layer_state_set_user(uint8_t state) {
    uint8_t layer = biton(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD,
    MORE_TAPS
};

static tap dance_state[TAP_DANCE_COUNT];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->pressed) return TRIPLE_HOLD;
        else return TRIPLE_TAP;
    }
    return MORE_TAPS;
}

// Dance Steps
// Dance Function Keys
void on_dance_FUNC(qk_tap_dance_state_t *state, void *user_data);
void dance_FUNC_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_FUNC_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_FUNC(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_FUNC_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_FUNC].step = dance_step(state);
    switch (dance_state[DANCE_FUNC].step) {
        case SINGLE_TAP:
            register_code(KC_F15);
            break;
        case SINGLE_HOLD:
            register_code(KC_F15);
            break;
        case DOUBLE_HOLD:
            register_code(KC_F16);
            break;
        case TRIPLE_HOLD:
            register_code(KC_F17);
            break;
        default: break;
    }
}

void dance_FUNC_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_FUNC].step) {
        case SINGLE_TAP:
            unregister_code(KC_F15);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_F15);
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_F16);
            break;
        case TRIPLE_HOLD:
            unregister_code(KC_F17);
            break;
        default: break;
    }
    dance_state[DANCE_FUNC].step = 0;
}

// Dance Minus
void on_dance_MINS(qk_tap_dance_state_t *state, void *user_data);
void dance_MINS_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_MINS_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_MINS(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_MINS_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_MINS].step = dance_step(state);
    switch (dance_state[DANCE_MINS].step) {
        case SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_MINUS);
            break;
        default: break;
    }
}

void dance_MINS_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_MINS].step) {
        case SINGLE_TAP:
            unregister_code(KC_MINUS);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_MINS].step = 0;
}

// Dance Equals
void on_dance_EQL(qk_tap_dance_state_t *state, void *user_data);
void dance_EQL_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_EQL_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_EQL(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_EQL_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_EQL].step = dance_step(state);
    switch (dance_state[DANCE_EQL].step) {
        case SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_EQL);
            break;
        default: break;
    }
}

void dance_EQL_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_EQL].step) {
        case SINGLE_TAP:
            unregister_code(KC_EQL);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_EQL].step = 0;
}

// Dance Left Bracket
void on_dance_LBRC(qk_tap_dance_state_t *state, void *user_data);
void dance_LBRC_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_LBRC_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_LBRC(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_LBRC_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_LBRC].step = dance_step(state);
    switch (dance_state[DANCE_LBRC].step) {
        case SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_LBRC);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_LBRC);
            break;
        default: break;
    }
}

void dance_LBRC_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_LBRC].step) {
        case SINGLE_TAP:
            unregister_code(KC_LBRC);
            unregister_code(KC_LGUI);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_LBRC);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_LBRC].step = 0;
}

// Dance Right Bracket
void on_dance_RBRC(qk_tap_dance_state_t *state, void *user_data);
void dance_RBRC_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_RBRC_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_RBRC(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_RBRC_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_RBRC].step = dance_step(state);
    switch (dance_state[DANCE_RBRC].step) {
        case SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_RBRC);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_RBRC);
            break;
        default: break;
    }
}

void dance_RBRC_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_RBRC].step) {
        case SINGLE_TAP:
            unregister_code(KC_RBRC);
            unregister_code(KC_LGUI);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_RBRC);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_RBRC].step = 0;
}

// Dance 0
void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_0].step = dance_step(state);
    switch (dance_state[DANCE_0].step) {
        case SINGLE_TAP:
            register_code(KC_0);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_0);
            break;
        case TRIPLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_0);
            break;
        default: break;
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_0].step) {
        case SINGLE_TAP:
            unregister_code(KC_0);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_0);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP:
            unregister_code(KC_0);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_0].step = 0;
}

// Dance 1
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_1].step = dance_step(state);
    switch (dance_state[DANCE_1].step) {
        case SINGLE_TAP: 
            register_code(KC_1);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_1);
            break;
        default: break;
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_1].step) {
        case SINGLE_TAP:
            unregister_code(KC_1);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_1);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_1].step = 0;
}

// Dance 2
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_2].step = dance_step(state);
    switch (dance_state[DANCE_2].step) {
        case SINGLE_TAP:
            register_code(KC_2);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_2);
            break;
        case TRIPLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_2);
            break;
        default: break;
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_2].step) {
        case SINGLE_TAP: 
            unregister_code(KC_2);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_2);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP:
            unregister_code(KC_2);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_2].step = 0;
}

// Dance 3
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {

    dance_state[DANCE_3].step = dance_step(state);
    switch (dance_state[DANCE_3].step) {
        case SINGLE_TAP:
            register_code(KC_3);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_3);
            break;
        case TRIPLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_3);
            break;
        default: break;
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_3].step) {
        case SINGLE_TAP: 
            unregister_code(KC_3);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_3);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP:
            unregister_code(KC_3);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_3].step = 0;
}

// Dance 5
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {

    dance_state[DANCE_5].step = dance_step(state);
    switch (dance_state[DANCE_5].step) {
        case SINGLE_TAP: 
            register_code(KC_5);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_5);
            break;
        default: break;
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_5].step) {
        case SINGLE_TAP: 
            unregister_code(KC_5);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_5);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_5].step = 0;
}

// Dance 7
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_7].step = dance_step(state);
    switch (dance_state[DANCE_7].step) {
        case SINGLE_TAP: 
            register_code(KC_7);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_7);
            break;
        case TRIPLE_TAP: 
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_7);
            break;
        default: break;
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_7].step) {
        case SINGLE_TAP: 
            unregister_code(KC_7);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_7);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP: 
            unregister_code(KC_7);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_7].step = 0;
}

// Dance 8
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_8].step = dance_step(state);
    switch (dance_state[DANCE_8].step) {
        case SINGLE_TAP: 
            register_code(KC_8);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_8);
            break;
        case TRIPLE_TAP: 
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_8);
            break;
        default: break;
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_8].step) {
        case SINGLE_TAP: 
            unregister_code(KC_8);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_8);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP: 
            unregister_code(KC_8);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_8].step = 0;
}

// Dance A
void on_dance_A(qk_tap_dance_state_t *state, void *user_data);
void dance_A_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_A_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_A(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_A_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_A].step = dance_step(state);
    switch (dance_state[DANCE_A].step) {
        case SINGLE_TAP: 
            register_code(KC_A);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_A);
            break;
        default: break;
    }
}

void dance_A_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_A].step) {
        case SINGLE_TAP: 
            unregister_code(KC_A);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_A);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_A].step = 0;
}

// Dance B
void on_dance_B(qk_tap_dance_state_t *state, void *user_data);
void dance_B_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_B_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_B(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_B_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_B].step = dance_step(state);
    switch (dance_state[DANCE_B].step) {
        case SINGLE_TAP: 
            register_code(KC_B);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_B);
            break;
        default: break;
    }
}

void dance_B_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_B].step) {
        case SINGLE_TAP: 
            unregister_code(KC_B);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_B);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_B].step = 0;
}

// Dance C
void on_dance_C(qk_tap_dance_state_t *state, void *user_data);
void dance_C_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_C_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_C(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_C_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_C].step = dance_step(state);
    switch (dance_state[DANCE_C].step) {
        case SINGLE_TAP: 
            register_code(KC_C);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_C);
            break;
        default: break;
    }
}

void dance_C_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_C].step) {
        case SINGLE_TAP: 
            unregister_code(KC_C);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_C);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_C].step = 0;
}

// Dance F
void on_dance_F(qk_tap_dance_state_t *state, void *user_data);
void dance_F_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_F_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_F(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_F_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_F].step = dance_step(state);
    switch (dance_state[DANCE_F].step) {
        case SINGLE_TAP: 
            register_code(KC_F);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_F);
            break;
        default: break;
    }
}

void dance_F_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_F].step) {
        case SINGLE_TAP: 
            unregister_code(KC_F);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_F);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_F].step = 0;
}

// Dance G
void on_dance_G(qk_tap_dance_state_t *state, void *user_data);
void dance_G_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_G_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_G(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_G_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_G].step = dance_step(state);
    switch (dance_state[DANCE_G].step) {
        case SINGLE_TAP:
            register_code(KC_G);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_G);
            break;
        case TRIPLE_TAP: 
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_G);
            break;
        default: break;
    }
}

void dance_G_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_G].step) {
        case SINGLE_TAP:
            unregister_code(KC_G);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_G);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP: 
            unregister_code(KC_G);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_G].step = 0;
}

// Dance I
void on_dance_I(qk_tap_dance_state_t *state, void *user_data);
void dance_I_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_I_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_I(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_I_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_I].step = dance_step(state);
    switch (dance_state[DANCE_I].step) {
        case SINGLE_TAP:
            register_code(KC_I);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_I);
            break;
        case TRIPLE_TAP: 
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_I);
            break;
        default: break;
    }
}

void dance_I_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_I].step) {
        case SINGLE_TAP:
            unregister_code(KC_I);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_I);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP: 
            unregister_code(KC_I);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_I].step = 0;
}

// Dance N
void on_dance_N(qk_tap_dance_state_t *state, void *user_data);
void dance_N_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_N_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_N(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_N_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_N].step = dance_step(state);
    switch (dance_state[DANCE_N].step) {
        case SINGLE_TAP:
            register_code(KC_N);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_N);
            break;
        case TRIPLE_TAP: 
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_N);
            break;
        default: break;
    }
}

void dance_N_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_N].step) {
        case SINGLE_TAP:
            unregister_code(KC_N);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_N);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP: 
            unregister_code(KC_N);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_N].step = 0;
}

// Dance O
void on_dance_O(qk_tap_dance_state_t *state, void *user_data);
void dance_O_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_O_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_O(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_O_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_O].step = dance_step(state);
    switch (dance_state[DANCE_O].step) {
        case SINGLE_TAP: 
            register_code(KC_O);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_O);
            break;
        case DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_O);
            break;
        case TRIPLE_TAP: 
            register_code(KC_LSFT);
            register_code(KC_O);
            break;
        default: break;
    }
}

void dance_O_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_O].step) {
        case SINGLE_TAP: 
            unregister_code(KC_O);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_O);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_O);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP: 
            unregister_code(KC_O);
            unregister_code(KC_LSFT);
            break;
        default: break;
    }
    dance_state[DANCE_O].step = 0;
}

// Dance Q
void on_dance_Q(qk_tap_dance_state_t *state, void *user_data);
void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_Q(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_Q].step = dance_step(state);
    switch (dance_state[DANCE_Q].step) {
        case SINGLE_TAP:
            register_code(KC_Q);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_Q);
            break;
        default: break;
    }
}

void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_Q].step) {
        case SINGLE_TAP:
            unregister_code(KC_Q);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_Q);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_Q].step = 0;
}

// Dance R
void on_dance_R(qk_tap_dance_state_t *state, void *user_data);
void dance_R_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_R_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_R(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_R_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_R].step = dance_step(state);
    switch (dance_state[DANCE_R].step) {
        case SINGLE_TAP:
            register_code(KC_R);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_R);
            break;
        default: break;
    }
}

void dance_R_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_R].step) {
        case SINGLE_TAP:
            unregister_code(KC_R);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_R);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_R].step = 0;
}

// Dance S
void on_dance_S(qk_tap_dance_state_t *state, void *user_data);
void dance_S_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_S_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_S(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_S_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_S].step = dance_step(state);
    switch (dance_state[DANCE_S].step) {
        case SINGLE_TAP:
            register_code16(KC_S);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_S);
            break;
        case DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_S);
            break;
        case TRIPLE_TAP: 
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_S);
            break;
        default: break;
    }
}

void dance_S_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_S].step) {
        case SINGLE_TAP:
            unregister_code16(KC_S);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_S);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP: 
            unregister_code(KC_S);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_S].step = 0;
}

// Dance T
void on_dance_T(qk_tap_dance_state_t *state, void *user_data);
void dance_T_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_T_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_T(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_T_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_T].step = dance_step(state);
    switch (dance_state[DANCE_T].step) {
        case SINGLE_TAP:
            register_code(KC_T);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_T);
            break;
        default: break;
    }
}

void dance_T_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_T].step) {
        case SINGLE_TAP:
            unregister_code(KC_T);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_T);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_T].step = 0;
}

// Dance V
void on_dance_V(qk_tap_dance_state_t *state, void *user_data);
void dance_V_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_V_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_V(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_V_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_V].step = dance_step(state);
    switch (dance_state[DANCE_V].step) {
        case SINGLE_TAP:
            register_code(KC_V);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_V);
            break;
        case DOUBLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_V);
            break;
        case TRIPLE_TAP: 
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_V);
            break;
        default: break;
    }
}

void dance_V_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_V].step) {
        case SINGLE_TAP:
            unregister_code(KC_V);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_V);
            unregister_code(KC_LGUI);
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_V);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP: 
            unregister_code(KC_V);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_V].step = 0;
}

// Dance W
void on_dance_W(qk_tap_dance_state_t *state, void *user_data);
void dance_W_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_W_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_W(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_W_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_W].step = dance_step(state);
    switch (dance_state[DANCE_W].step) {
        case SINGLE_TAP:
            register_code(KC_W);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_W);
            break;
        default: break;
    }
}

void dance_W_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_W].step) {
         case SINGLE_TAP:
            unregister_code(KC_W);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_W);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_W].step = 0;
}

// Dance X
void on_dance_X(qk_tap_dance_state_t *state, void *user_data);
void dance_X_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_X_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_X(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_X_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_X].step = dance_step(state);
    switch (dance_state[DANCE_X].step) {
        case SINGLE_TAP:
            register_code(KC_X);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_X);
            break;
        case TRIPLE_TAP:
            register_code(KC_LSFT);
            register_code(KC_X);
            break;
        default: break;
    }
}

void dance_X_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_X].step) {
        case SINGLE_TAP:
            unregister_code(KC_X);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_X);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP:
            unregister_code(KC_LSFT);
            unregister_code(KC_X);
            break;
        default: break;
    }
    dance_state[DANCE_X].step = 0;
}

// Dance Y
void on_dance_Y(qk_tap_dance_state_t *state, void *user_data);
void dance_Y_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_Y_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_Y(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_Y_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_Y].step = dance_step(state);
    switch (dance_state[DANCE_Y].step) {
        case SINGLE_TAP:
            register_code(KC_Y);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_Y);
            break;
        default: break;
    }
}

void dance_Y_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_Y].step) {
        case SINGLE_TAP:
            unregister_code(KC_Y);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_Y);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_Y].step = 0;
}

// Dance Z
void on_dance_Z(qk_tap_dance_state_t *state, void *user_data);
void dance_Z_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_Z_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_Z(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_Z_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_Z].step = dance_step(state);
    switch (dance_state[DANCE_Z].step) {
        case SINGLE_TAP: 
            register_code(KC_Z);
            break;
        case DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_Z);
            break;
        case TRIPLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_Z);
            break;
        default: break;
    }
}

void dance_Z_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_Z].step) {
        case SINGLE_TAP: 
            unregister_code(KC_Z);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_Z);
            unregister_code(KC_LGUI);
            break;
        case TRIPLE_TAP:
            unregister_code(KC_Z);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            break;
        default: break;
    }
    dance_state[DANCE_Z].step = 0;
}


// Dance ESC
void on_dance_ESC(qk_tap_dance_state_t *state, void *user_data);
void dance_ESC_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_ESC_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_ESC(qk_tap_dance_state_t *state, void *user_data) {
    // Used for Immediate Actions
}

void dance_ESC_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // Single tap sends Escape
    register_code(KC_ESC);
    unregister_code(KC_ESC);
  } else if (state->count == 2) {
    // Double tap switches layer
    if (layer_state_is(VIM)) {
      // Switch back to the last layer
      layer_move(lastLayer);
    } else {
      // Remember the current layer and switch to SPECIFIC_LAYER
      lastLayer = biton32(layer_state);
      layer_move(VIM);
    }
  }
}

void dance_ESC_reset(qk_tap_dance_state_t *state, void *user_data) {
    // Reset function if needed
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_ESC, dance_ESC_finished, dance_ESC_reset),
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

#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// JIS keycode
// https://docs.qmk.fm/#/keycodes_basic?id=international

#define JP_UNDS KC_INTERNATIONAL_1
#define JP_YEN KC_INTERNATIONAL_3

enum layer_number {
    _MAC = 0,
    _LOWER_M,
    _RAISE_M,
    _WIN,
    _LOWER_W,
    _RAISE_W,
    _LOCK,
};

// [_LOWER] = LAYOUT(
// //,-----------------------------------------------------|               |--------------------------------------------------------------------------------|
//     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, _______,
// //,--------+--------+--------+--------+--------+--------|---            |--------+--------+--------+--------+--------+--------+--------+--------+--------|
//       _______,   XXXXXXX,  XXXXXXX,  XXXXXXX, JP_YEN, KC_CIRC,                  KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
// //,------------+--------+--------+--------+--------+--------|--              |--------+--------+--------+--------+--------+--------+--------+------------|
//          _______,   XXXXXXX, XXXXXXX, XXXXXXX,  KC_AT,  KC_UNDS,                  KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, XXXXXXX, XXXXXXX,    _______,
// //   ,------------+--------+--------+--------+--------+--------|---             |--------+--------+--------+--------+--------+--------+----------------|
//            _______,     XXXXXXX, XXXXXXX, XXXXXXX, KC_AMPR, KC_MINS,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_UNDS,   _______,   _______,
// //   ,----------------+--------+--------+--------+--------+--------|               --|-------+--------+--------+--------+--------+------------+--------|
//                    _______,   _______,     _______,     KC_TAB,                     _______,     _______,       _______,   _______
// //`              ,--------|------------|------------|------------|                |--------+----------------+------------+--------|
// ),
#define _7SKB_LOWER_LAYOUT                                                                                                          \
    LAYOUT(                                                                                                                         \
                                                                                                                                    \
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,             KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, _______,           \
                                                                                                                                    \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, JP_YEN, KC_CIRC,    KC_HOME, KC_END, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
                                                                                                                                    \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_AT, KC_UNDS,     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, _______,            \
                                                                                                                                    \
        _______, KC_F21, KC_F22, KC_F23, KC_AMPR, KC_MINS,      KC_F23, KC_F22, KC_F21, XXXXXXX, JP_UNDS, _______, _______,        \
                                                                                                                                    \
        _______, _______, _______, KC_TAB,                      KC_HYPR, _______, _______, _______)

// [_RAISE] = LAYOUT(
// //,-----------------------------------------------------|               |--------------------------------------------------------------------------------|
//     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, _______,
// //,--------+--------+--------+--------+--------+--------|---            |--------+--------+--------+--------+--------+--------+--------+--------+--------|
//       _______,   XXXXXXX,  KC_UP,  XXXXXXX, XXXXXXX, XXXXXXX,                  KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
// //,------------+--------+--------+--------+--------+--------|--              |--------+--------+--------+--------+--------+--------+--------+------------|
//          _______,   KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,                  KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, XXXXXXX, XXXXXXX,    _______,
// //   ,------------+--------+--------+--------+--------+--------|---             |--------+--------+--------+--------+--------+--------+----------------|
//            _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_UNDS,   _______,   _______,
// //   ,----------------+--------+--------+--------+--------+--------|               --|-------+--------+--------+--------+--------+------------+--------|
//                    _______,   _______,     _______,     KC_ENT,                     KC_ENT,      _______,       _______,   _______
// //`              ,--------|------------|------------|------------|                |--------+----------------+------------+--------|
// ),
#define _7SKB_RAISE_LAYOUT                                                                                                         \
    LAYOUT(                                                                                                                        \
                                                                                                                                   \
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,             KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, _______,          \
                                                                                                                                   \
        _______, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,     KC_HOME, KC_END, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
                                                                                                                                   \
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, _______,         \
                                                                                                                                   \
        _______, KC_F21, KC_F22, KC_F23, XXXXXXX, XXXXXXX,      KC_F23, KC_F22, KC_F21, XXXXXXX, JP_UNDS, _______, _______,       \
                                                                                                                                   \
        _______, _______, _______, KC_HYPR,                     KC_ENT, _______, _______, _______                                                       \
                                                                                                                                   \
    )

#define TO_MAC TO(_MAC)
#define TO_WIN TO(_WIN)
#define TO_LOCK TO(_LOCK)
#define LT_RAISE_M LT(_RAISE_M, KC_F19)
#define LT_LOWER_M LT(_LOWER_M, KC_F20)
#define LT_RAISE_W LT(_RAISE_W, KC_F19)
#define LT_LOWER_W LT(_LOWER_W, KC_F20)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC] = LAYOUT(
        //                           <<<-----LEFT |    | RIGHT----->>>
        KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,      KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,  JP_YEN,  KC_DEL,
        KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,      KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,   KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,     KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_QUOT,  KC_ENT,
        KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,     KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,  TO_WIN,
           KC_LALT,  KC_LGUI,  LT_RAISE_M,  KC_SPC,     KC_BSPC,  LT_LOWER_M,  KC_RALT,  KC_RGUI
        ),
    [_LOWER_M] = _7SKB_LOWER_LAYOUT,
    [_RAISE_M] = _7SKB_RAISE_LAYOUT,
    [_WIN]     = LAYOUT(
        //                          <<<-----LEFT |     | RIGHT----->>>
        KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,      KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,  JP_YEN,  KC_DEL,
        KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,      KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,     KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_QUOT,  KC_ENT,
        KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,     KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,  TO_LOCK,
           KC_LGUI,  KC_LALT,  LT_RAISE_W,  KC_SPC,     KC_BSPC,  LT_LOWER_W,  KC_RALT,  KC_RCTL
        ),
    [_LOWER_W] = _7SKB_LOWER_LAYOUT,
    [_RAISE_W] = _7SKB_RAISE_LAYOUT,
    [_LOCK]    = LAYOUT(
        //                                     <<<-----LEFT |    | RIGHT----->>>
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12, XXXXXXX, _______,
        _______, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,     KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_UNDS, _______, TO_MAC,
                          _______, _______,  KC_SPC,  KC_ENT,     KC_ENT,  KC_SPC,  _______, _______
        ),

};

// この書き方でLEDを制御できない
// const rgblight_segment_t PROGMEM mac_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, HSV_WHITE}
// );
// const rgblight_segment_t PROGMEM win_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, HSV_BLUE}
// );
// const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     mac_layer,
//     win_layer
// );
// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = rgb_layers;
// }
// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(0, layer_state_cmp(state, _MAC));
//     return state;
// }
// layer_state_t layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(0, layer_state_cmp(state, _MAC));
//     rgblight_set_layer_state(1, layer_state_cmp(state, _WIN));
//     return state;
// }

// A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
        case _MAC:
            rgblight_sethsv_at(HSV_WHITE, 0);
            break;
        case _WIN:
            rgblight_sethsv_at(HSV_BLUE, 0);
            break;
        case _LOCK:
            rgblight_sethsv_at(HSV_RED, 0);
            break;
        default: //  for any other layers, or the default layer
            rgblight_sethsv_at(HSV_YELLOW, 0);
            break;
    }
    rgblight_set_effect_range(1, 11);
#endif
    return state;
}

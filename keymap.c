#include QMK_KEYBOARD_H

#define xxx KC_NO

enum custom_keycodes {
  KBD_TOGGLE = SAFE_RANGE,
};

#define NUM_WORD_IDLE_TIMEOUT 5000


// One of the goals of this keymap is to share keyboard shortcuts for symbols between English and Russian layouts.
// Default layouts have issues:
// 1) English layout misses № (do not use it---so not a problem)
// 2) Russian layout misses #$&'<>@[]^`{|}~
// 3) Same shortcuts may map to different symbols (e.g. shift+2 is @ on English layout and " on Russian)
// 4) Different shortcuts may be needed for same symbols (e.g. to type " use shift+' on English layout and shift+2 on Russian layout )
// 
// To address that, the separate layer for symbols is used (see SYM for English layout).
// To have the same shortcuts when Russian layout is active, I need a custom Russian layout that defines missed symbols.
#define RU_HASH ALGR(KC_Q)
#define RU_DLR ALGR(KC_W)
#define RU_AMPR ALGR(KC_E)
#define RU_QUOT ALGR(KC_R)
#define RU_LABK ALGR(KC_T)
#define RU_RABK ALGR(KC_Y)
#define RU_AT ALGR(KC_U)
#define RU_LBRC ALGR(KC_I)
#define RU_RBRC ALGR(KC_O)
#define RU_CIRC ALGR(KC_P)
#define RU_GRV ALGR(KC_A)
#define RU_LCBR ALGR(KC_S)
#define RU_PIPE ALGR(KC_D)
#define RU_RCBR ALGR(KC_F)
#define RU_TILD ALGR(KC_G)


#define LAYOUT_LR(\
    L11,L12,L13,L14,L15,L16,\
    L21,L22,L23,L24,L25,L26,\
    L31,L32,L33,L34,L35,\
    R11,R12,R13,R14,R15,R16,\
    R21,R22,R23,R24,R25,R26,\
    R31,R32,R33,R34,R35,\
    TL1,TL2,TR1,TR2,\
    MU,M2,WU,M1,ML,MD,MR,WD)\
LAYOUT_ansi_84(\
L11,L12,L13,L14,L15,L16,xxx,xxx,R11,R12,R13,R14,R15,R16,xxx,xxx,\
L21,L22,L23,L24,L25,L26,xxx,xxx,R21,R22,R23,R24,R25,R26,xxx,\
L31,L32,L33,L34,L35,xxx,xxx,xxx,R31,R32,R33,R34,R35,xxx,KC_PGUP,\
KC_CAPS,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,KC_PGDN,\
xxx,xxx,xxx,TL1,TL2,xxx,xxx,TR1,TR2,xxx,xxx,MU,M2,WU,\
xxx,KC_LGUI,KC_LALT,LT(FN,KC_SPC),KC_LALT,M1,ML,MD,MR,WD)

enum layers{
    WIN_BASE,
    WIN_FN,
    BASE,
    BASER,
    NUM_WORD,
    SYM,
    SYMR,
    NAV,
    FN,   
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[WIN_BASE] = LAYOUT_ansi_84(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   RGB_MOD,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_LSFT,  KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_ansi_84(
    KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  RGB_TOG,
    KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
    KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),


[BASE] = LAYOUT_LR(
    KC_ESC,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
    KC_TAB,         LCTL_T(KC_A),   LSFT_T(KC_S),   KC_D,           LT(SYM,KC_F),   KC_G,
                    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,
    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           TG(NUM_WORD),
    KC_H,           LT(SYM,KC_J),   KC_K,           LSFT_T(KC_L),   KC_LCTL,        KC_ENT,
    KC_N,           KC_M,           xxx,            LCTL(KC_L),     xxx,
    MO(NAV),        KC_DEL,         KC_BSPC,        TG(NAV),
    KC_MS_U,KC_BTN2,KC_WH_U, KC_BTN1,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D),


[BASER] = LAYOUT_LR(
    _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        LT(SYMR,KC_F),  _______,
                    _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        KC_LBRC,
    _______,        LT(SYMR,KC_J),  _______,        _______,        LCTL_T(KC_SCLN),_______,
    _______,        _______,        KC_COMM,        KC_DOT,         KC_QUOT,
    _______,        _______,        _______,        _______,
    _______,_______,_______, _______,_______,_______,_______,_______),


[NUM_WORD] = LAYOUT_LR(
    _______,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,
    _______,        _______,        _______,        _______,        _______,        _______,
                    _______,        _______,        _______,        _______,        _______,
    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           _______,
    _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,
    _______,_______,_______, _______,_______,_______,_______,_______),


[SYM] = LAYOUT_LR(
    KC_TILD,        KC_PIPE,        KC_LABK,        KC_RABK,        KC_DLR,         xxx,
    KC_GRV,         KC_EXLM,        KC_MINS,        KC_PLUS,        KC_EQL,         KC_UNDS,
                    KC_COLN,        KC_SLSH,        KC_ASTR,        KC_BSLS,        KC_SCLN,
    KC_CIRC,        KC_HASH,        KC_LPRN,        KC_RPRN,        KC_AMPR,        KC_PERC,
    KC_LCBR,        KC_DQUO,        KC_COMM,        KC_DOT,         KC_QUES,        KC_QUOT,
    KC_RCBR,        xxx,            KC_LBRC,        KC_RBRC,        KC_AT,
    _______,        _______,        _______,        _______,
    _______,_______,_______, _______,_______,_______,_______,_______),


[SYMR] = LAYOUT_LR(
    RU_TILD,        RU_PIPE,        RU_LABK,        RU_RABK,        RU_DLR,         KC_GRV,
    RU_GRV,         KC_EXLM,        KC_MINS,        KC_PLUS,        KC_EQL,         KC_UNDS,
                    LSFT(KC_6),     LSFT(KC_BSLS),  KC_ASTR,        KC_BSLS,        LSFT(KC_4),
    RU_CIRC,        RU_HASH,        KC_LPRN,        KC_RPRN,        RU_AMPR,        KC_PERC,
    RU_LCBR,        LSFT(KC_2),     LSFT(KC_SLSH),  KC_SLSH,        LSFT(KC_7),       RU_QUOT,
    RU_RCBR,        KC_RBRC,        RU_LBRC,        RU_RBRC,        RU_AT,
    _______,        _______,        _______,        _______,
    _______,_______,_______, _______,_______,_______,_______,_______),


[NAV] = LAYOUT_LR(
    _______,        xxx,            xxx,            xxx,            xxx,            xxx,
    _______,        KC_LCTL,        KC_LSFT,        xxx,            xxx,            xxx,
                    xxx,            xxx,            xxx,            xxx,            xxx,
    KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         xxx,            xxx,
    KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RGHT,        xxx,            _______,
    xxx,            LCTL(KC_LEFT),  xxx,            LCTL(KC_RGHT),  xxx,
    _______,        _______,        _______,        _______,
    _______,_______,_______, _______,_______,_______,_______,_______),


[FN] = LAYOUT_LR(
    xxx,            LGUI(KC_5),     LGUI(KC_6),     LGUI(KC_7),     LGUI(KC_8),     xxx,
    KC_F12,         LGUI(KC_1),     LGUI(KC_2),     LGUI(KC_3),     LGUI(KC_4),     xxx,
                    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,
    xxx,            xxx,            xxx,            xxx,            xxx,            xxx,
    LCTL(KC_5),     LCTL(KC_1),     LCTL(KC_2),     LCTL(KC_3),     LCTL(KC_4),     KC_F11,
    KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,
    _______,        _______,        KBD_TOGGLE,     _______,
    KC_VOLU,KC_MUTE,_______, KC_PSCR,KC_INS,KC_VOLD,_______,_______),
    
};


#if NUM_WORD_IDLE_TIMEOUT > 0
static uint16_t idle_timer = 0;
void num_word_task(void) {
    if (IS_LAYER_ON(NUM_WORD) && timer_expired(timer_read(), idle_timer)) {
        layer_off(NUM_WORD);
    }
}
#endif  // NUM_WORD_IDLE_TIMEOUT > 0

void housekeeping_task_user(void) {
#if NUM_WORD_IDLE_TIMEOUT > 0
    num_word_task();
#endif  // NUM_WORD_IDLE_TIMEOUT > 0
}


static bool turn_num_word_off(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed || IS_LAYER_OFF(NUM_WORD))
        return false;

    // based on getreuer/qmk-keymap/main/features/caps_word.c
    switch (keycode) {
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:
        case QK_TO ... QK_TO_MAX:
        case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
        case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
        case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
        case KC_LCTL ... KC_RGUI:
        case OSM(MOD_RALT):
            return false;
#ifndef NO_ACTION_TAPPING
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if (record->tap.count == 0)
                return false;
            keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
            break;
#endif  // NO_ACTION_TAPPING
#ifndef NO_ACTION_LAYER
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (record->tap.count == 0)
              return false;
            keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
            break;
#endif  // NO_ACTION_LAYER
    }

    if (keycode == KC_DOT || (keycode >= KC_1 && keycode <= KC_0))
        return false;
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#if NUM_WORD_IDLE_TIMEOUT > 0
    if (record->event.pressed && IS_QK_TOGGLE_LAYER(keycode) && QK_TOGGLE_LAYER_GET_LAYER(keycode) == (NUM_WORD))
        idle_timer = record->event.time + NUM_WORD_IDLE_TIMEOUT;
    if (record->event.pressed && IS_LAYER_ON(NUM_WORD) && (keycode) >= KC_1 && (keycode) <= KC_9)
        idle_timer = record->event.time + NUM_WORD_IDLE_TIMEOUT;
#endif  // NUM_WORD_IDLE_TIMEOUT > 0

    if (turn_num_word_off(keycode, record))
        layer_off(NUM_WORD);

    switch (keycode) {
    case KBD_TOGGLE:
        if (record->event.pressed) {
            if (IS_LAYER_ON(BASER)) {
                layer_off(BASER);
            } else {
                layer_on(BASER);
            }
            SEND_STRING(SS_LGUI(SS_TAP(X_SPC)));
        }
        return false;
    }
    return true;
}


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (IS_LAYER_ON(NUM_WORD)) {
        for (uint8_t i = 1; i < 16; i++)
            rgb_matrix_set_color(i, RGB_WHITE);
    }

    if (IS_LAYER_ON(NAV)) {
        rgb_matrix_set_color(54, RGB_CYAN);
        rgb_matrix_set_color(55, RGB_CYAN);
        rgb_matrix_set_color(69, RGB_CYAN);
    }

    return false;
}

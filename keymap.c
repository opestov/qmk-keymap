#include QMK_KEYBOARD_H
#include "print.h"

#define ___ KC_NO
#define LAYOUT_LR(\
     L00, L01, L02, L03, L04,\
L1X, L10, L11, L12, L13, L14,\
L2X, L20, L21, L22, L23, L24,\
L3X, L30, L31, L32, L33, L34,\
     LT0, LT1, LT2,\
     R00, R01, R02, R03, R04,\
     R10, R11, R12, R13, R14, R1X,\
     R20, R21, R22, R23, R24, R2X,\
     R30, R31, R32, R33, R34, R3X,\
     RT0, RT1, RT2)\
LAYOUT_ansi_84(\
___, L00, L01, L02, L03, L04, ___, ___, R00, R01, R02, R03, R04, ___, ___, QK_BOOT,\
L1X, L10, L11, L12, L13, L14, ___, R10, R11, R12, R13, R14, R1X, ___, ___,\
L2X, L20, L21, L22, L23, L24, ___, R20, R21, R22, R23, R24, R2X, ___, ___,\
L3X, L30, L31, L32, L33, L34, ___, R30, R31, R32, R33, R34, R3X, ___,\
___, ___, LT0, LT1, LT2, ___, ___, RT0, RT1, RT2, ___, ___, ___, ___,\
DT_PRNT, DT_UP, DT_DOWN, ___, ___, ___, ___, ___, ___, ___)


// clang-format off
enum layers{
    BASE,
    QWERTY,
    WIN_BASE,
    WIN_FN,
    SYM,
    NAV,
    MOUSE,
    FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_LR(
               KC_1,           KC_2,           KC_3,           KC_4,           KC_5,
KC_TAB,        KC_QUOT,        KC_COMM,        KC_DOT,         KC_P,           KC_Y,
KC_ESC,        LCTL_T(KC_A),   LSFT_T(KC_O),   LALT_T(KC_E),   LT(SYM,KC_U),   KC_I,
DF(BASE),      KC_COLN,        ALGR_T(KC_Q),   KC_J,           KC_K,           KC_X,
               KC_LGUI,        MO(NAV),        LT(NAV,KC_SPC),

               KC_6,           KC_7,           KC_8,           KC_9,           KC_0,
               KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           ___,
               KC_D,           LT(SYM,KC_H),   LALT_T(KC_T),   LSFT_T(KC_N),   LCTL_T(KC_S),   KC_ENT,
               KC_B,           KC_M,           KC_W,           ALGR_T(KC_V),   KC_Z,           DF(QWERTY),
               LT(MOUSE,KC_BSPC),MO(FN),       LGUI_T(KC_DEL)),


[QWERTY] = LAYOUT_LR(
               KC_1,           KC_2,           KC_3,           KC_4,           KC_5,
KC_TAB,        KC_Q,        KC_W,        KC_E,         KC_R,           KC_T,
KC_ESC,        LCTL_T(KC_A),   LSFT_T(KC_S),   LALT_T(KC_D),   LT(SYM,KC_F),   KC_G,
DF(BASE),      KC_Z,        ALGR_T(KC_X),   KC_C,           KC_V,           KC_B,
               KC_LGUI,        MO(NAV),        LT(NAV,KC_SPC),

               KC_6,           KC_7,           KC_8,           KC_9,           KC_0,
               KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,
               KC_H,           LT(SYM,KC_J),   LALT_T(KC_K),   LSFT_T(KC_L),   LCTL_T(KC_SCLN),   KC_ENT,
               KC_N,           KC_M,           KC_COMM,           ALGR_T(KC_DOT),   KC_QUOT,           DF(QWERTY),
               LT(MOUSE,KC_BSPC),MO(FN),       LGUI_T(KC_DEL)),


[WIN_BASE] = LAYOUT_ansi_84(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   RGB_MOD,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_ansi_84(
     KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),


[SYM] = LAYOUT_LR(
               KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,
KC_TAB,        KC_QUOT,        KC_COMM,        KC_DOT,         KC_DQUO,        ___,       
KC_ESC,        KC_COLN,        KC_LABK,        KC_RABK,        KC_PLUS,        KC_UNDS,
___,           KC_SCLN,        ___,            ___,            ___,            ___,
               ___,            ___,            KC_SPC,

               KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_PIPE,        KC_BSLS,
               ___,            ___,            KC_LPRN,        KC_RPRN,        KC_SLSH,        KC_EQL,
               KC_GRV,         ___,            KC_LBRC,        KC_RBRC,        KC_MINS,        KC_ENT,
               KC_TILD,        ___,            KC_LCBR,        KC_RCBR,        KC_QUES,        ___,
               KC_BSPC,        ___,            KC_DEL),


[NAV] = LAYOUT_LR(
               ___,            ___,            ___,            ___,            ___,
KC_ESC,        ___,            ___,            ___,            ___,            ___,
KC_TAB,        KC_LCTL,        KC_LSFT,        KC_LALT,        ___,            ___,
___,           ___,            KC_ALGR,        ___,            ___,            ___,
               KC_LGUI,        ___,            KC_SPC,

               ___,            ___,            ___,            ___,            ___,
               ___,            KC_HOME,        KC_UP,          KC_END,         KC_PGUP,        ___,
               CW_TOGG,        KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_PGDN,        KC_ENT,
               ___,            ___,            ___,            ___,            ___,            ___,
               KC_BSPC,        ___,            KC_DEL),

[MOUSE] = LAYOUT_LR(
               KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_MUTE,        KC_VOLU,
___,           KC_WH_U,        KC_WH_L,        KC_MS_U,        KC_WH_R,        KC_VOLD,
___,           KC_WH_D,        KC_MS_L,        KC_MS_D,        KC_MS_R,        ___,
___,           ___,            ___,            ___,            ___,            ___,
               KC_LGUI,        KC_BTN2,        KC_BTN1,

               ___,            ___,            ___,            ___,            ___,
               ___,            ___,            ___,            ___,            ___,            ___,
               ___,            KC_LALT,        KC_LSFT,        KC_LCTL,        ___,            ___,
               ___,            ___,            ___,            KC_ALGR,        ___,            ___,
               ___,            ___,            KC_LGUI),

[FN] = LAYOUT_LR(
               ___,            KC_F10,         KC_F11,         KC_F12,         ___,
___,           ___,            KC_F7,          KC_F8,          KC_F9,          ___,
___,           KC_INS,         KC_F4,          KC_F5,          KC_F6,          KC_PSCR,
___,           ___,            KC_F1,          KC_F2,          KC_F3,          ___,
               ___,            ___,            ___,

               ___,            ___,            ___,            ___,            QK_BOOT,
               ___,            ___,            ___,            ___,            ___,            ___,
               ___,            KC_LALT,        KC_LSFT,        KC_LCTL,        ___,            ___,
               ___,            ___,            ___,            KC_ALGR,        ___,            ___,
               ___,            ___,            KC_LGUI),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {


    if (IS_LAYER_ON(QWERTY)) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
        if (keycode == KC_Q) return false;


        if (keycode == KC_Q && record->tap.count > 0) {
            if (record->event.pressed) {
                add_mods(MOD_BIT(KC_ALGR));
            }
            else {
                del_mods(MOD_BIT(KC_ALGR));
            }
        }
    }
    else {
#ifdef CONSOLE_ENABLE
    uprintf("XX: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 

    }
    return true;
}

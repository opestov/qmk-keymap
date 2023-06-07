#include QMK_KEYBOARD_H
#include "print.h"

#define xxx KC_NO
#define LAYOUT_LR(\
    L11,L12,L13,L14,L15,L16,\
    L21,L22,L23,L24,L25,L26,\
    L31,L32,L33,L34,L35,L36,\
    L41,L42,L43,L44,L45,L46,\
    \
    R11,R12,R13,R14,R15,R16,\
    R21,R22,R23,R24,R25,R26,\
    R31,R32,R33,R34,R35,R36,\
    R41,R42,R43,R44,R45,R46,\
    \
    LT1,LT2,LT3,RT1,RT2,RT3)\
LAYOUT_ansi_84(\
L11,L12,L13,L14,L15,L16,xxx,R11,R12,R13,R14,R15,R16,xxx,xxx,QK_BOOT,\
L21,L22,L23,L24,L25,L26,xxx,R21,R22,R23,R24,R25,R26,xxx,xxx,\
L31,L32,L33,L34,L35,L36,xxx,R31,R32,R33,R34,R35,R36,xxx,xxx,\
L41,L42,L43,L44,L45,L46,xxx,R41,R42,R43,R44,R45,R46,xxx,\
xxx,xxx,LT1,LT2,LT3,xxx,xxx,RT1,RT2,RT3,xxx,xxx,xxx,xxx,\
xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx)


enum layers{
    WIN_BASE,
    WIN_FN,
    BASE,
    SYM,
    NAV,
    FN
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
KC_ESC,       KC_1,         KC_2,         KC_3,         KC_4,         KC_5,
KC_TAB,       KC_QUOT,      KC_COMM,      KC_DOT,       KC_P,         KC_Y,
KC_DEL,       LCTL_T(KC_A), LSFT_T(KC_O), LALT_T(KC_E), LT(SYM,KC_U), KC_I,
KC_LSFT,      KC_COLN,      ALGR_T(KC_Q), KC_J,         KC_K,         KC_X,
        KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_LGUI,
        KC_F,         KC_G,         KC_C,         KC_R,         KC_L,         CW_TOGG,
        KC_D,         LT(SYM,KC_H), LALT_T(KC_T), LSFT_T(KC_N), LCTL_T(KC_S), KC_BSPC,
        KC_B,         KC_M,         KC_W,         ALGR_T(KC_V), KC_Z,         KC_LSFT,
xxx, xxx, LT(NAV,KC_SPC), LT(FN,KC_ENT), xxx, xxx),


[SYM] = LAYOUT_LR(
xxx,      KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,
xxx,      KC_QUOT,  KC_COMM,  KC_DOT,   KC_DQUO,  xxx,
xxx,      KC_COLN,  KC_LABK,  KC_RABK,  KC_PLUS,  KC_UNDS,
xxx,      KC_SCLN,  xxx,      xxx,      xxx,      xxx,
        KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_PIPE,  KC_BSLS,  xxx,
        xxx,      xxx,      KC_LPRN,  KC_RPRN,  KC_SLSH,  KC_EQL,
        KC_GRV,   xxx,      KC_LBRC,  KC_RBRC,  KC_MINS,  xxx,
        KC_TILD,  xxx,      KC_LCBR,  KC_RCBR,  KC_QUES,  xxx,
xxx, xxx, KC_SPC, KC_ENT, xxx, xxx),


[NAV] = LAYOUT_LR(
TG(NAV),  xxx,      xxx,      xxx,      xxx,      xxx,
xxx,      KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   xxx,
xxx,      KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  xxx,
xxx,      xxx,      xxx,      xxx,      xxx,      xxx,
        xxx,      xxx,      xxx,      xxx,      xxx,      xxx,
        xxx,      xxx,      xxx,      xxx,      xxx,      xxx,
        xxx,      xxx,      KC_LALT,  KC_LSFT,  KC_LCTL,  xxx,
        xxx,      xxx,      xxx,      KC_ALGR,  xxx,      KC_LSFT,
xxx, xxx, xxx, xxx, xxx, xxx),


[FN] = LAYOUT_LR(
xxx,      xxx,      xxx,      xxx,      xxx,      xxx,
xxx,      xxx,      xxx,      xxx,      xxx,      xxx,
xxx,      KC_LCTL,  KC_LSFT,  KC_LALT,  xxx,      xxx,
KC_LSFT,  xxx,      KC_ALGR,  xxx,      xxx,      xxx,
        xxx,      KC_F10,   KC_F11,   KC_F12,   xxx,      xxx,
        xxx,      KC_F7,    KC_F8,    KC_F9,    xxx,      xxx,
        KC_INS,   KC_F4,    KC_F5,    KC_F6,    KC_PSCR,  xxx,
        xxx,      KC_F1,    KC_F2,    KC_F3,    xxx,      xxx,
xxx, xxx, xxx, xxx, xxx, xxx),

};

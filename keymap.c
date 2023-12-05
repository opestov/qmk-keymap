#include QMK_KEYBOARD_H
#include "print.h"

#define xxx KC_NO

#define RU_GRV ALGR(KC_GRV)
#define RU_Q ALGR(KC_Q)
#define RU_W ALGR(KC_W)
#define RU_E ALGR(KC_E)
#define RU_R ALGR(KC_R)
#define RU_T ALGR(KC_T)
#define RU_G ALGR(KC_G)
#define RU_Z ALGR(KC_Z)
#define RU_X ALGR(KC_X)
#define RU_C ALGR(KC_C)
#define RU_V ALGR(KC_V)
#define RU_B ALGR(KC_B)
#define RU_Y ALGR(KC_Y)
#define RU_U ALGR(KC_U)
#define RU_I ALGR(KC_I)
#define RU_O ALGR(KC_O)
#define RU_P ALGR(KC_P)
#define RU_LBRC ALGR(KC_LBRC)
#define RU_RBRC ALGR(KC_RBRC)
#define RU_H ALGR(KC_H)
#define RU_QUOT ALGR(KC_QUOT)
#define RU_N ALGR(KC_N)
#define RU_M ALGR(KC_M)
#define RU_COMM ALGR(KC_COMM)
#define RU_DOT ALGR(KC_DOT)

enum my_keycodes {
    RU_XA = SAFE_RANGE,
    RU_XS,
    RU_XD,
    RU_XF,
    RU_XJ,
    RU_XK,
    RU_XL,
    RU_XSCLN,
};

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
    LT1,LT2,LT3,RT1,RT2,RT3,\
    TTT)\
LAYOUT_ansi_84(\
L11,L12,L13,L14,L15,L16,xxx,R11,R12,R13,R14,R15,R16,xxx,xxx,QK_BOOT,\
L21,L22,L23,L24,L25,L26,xxx,R21,R22,R23,R24,R25,R26,xxx,xxx,\
L31,L32,L33,L34,L35,L36,xxx,R31,R32,R33,R34,R35,R36,xxx,xxx,\
L41,L42,L43,L44,L45,L46,xxx,R41,R42,R43,R44,R45,R46,xxx,\
xxx,xxx,LT1,LT2,LT3,xxx,xxx,RT1,RT2,RT3,xxx,xxx,xxx,xxx,\
xxx,xxx,xxx,TTT,xxx,xxx,xxx,xxx,xxx,xxx)

enum layers{
    WIN_BASE,
    WIN_FN,
    BASE,
    BASERU,
    SYM,
    NAV,
    FN,
    MOUSE,
    MOUSE1
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
KC_ESC,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,
KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
KC_DEL,         LCTL_T(KC_A),   LSFT_T(KC_S),   LALT_T(KC_D),   LT(SYM,KC_F),   KC_G,
xxx,            KC_Z,           ALGR_T(KC_X),   KC_C,           KC_V,           KC_B,
    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_CAPS,
    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,
    KC_H,           LT(SYM,KC_J),   LALT_T(KC_K),   LSFT_T(KC_L),   LCTL_T(KC_SCLN),KC_ENT,
    KC_N,           KC_M,           KC_COMM,        ALGR_T(KC_DOT), KC_QUOT,        TG(BASERU),
xxx, KC_LGUI, LT(NAV, KC_SPC), LT(FN, KC_BSPC), KC_LGUI, xxx,
TG(MOUSE1)),

[BASERU] = LAYOUT_LR(
_______,        _______,        _______,        _______,        _______,        _______,
_______,        RU_Q,           RU_W,           RU_E,           RU_R,           RU_T,
_______,        LCTL_T(RU_XA),  LSFT_T(RU_XS),  LALT_T(RU_XD),  LT(SYM,RU_XF),  RU_G,
TG(BASERU),     RU_Z,           RU_X,           RU_C,           RU_V,           RU_B,
    _______,        _______,        _______,        _______,        _______,        _______,
    RU_Y,           RU_U,           RU_I,           RU_O,           RU_P,           RU_LBRC,
    RU_H,           LT(SYM,RU_XJ),  LALT_T(RU_XK),  LSFT_T(RU_XL),  LCTL_T(RU_XSCLN),_______,
    RU_N,           RU_M,           RU_COMM,        RU_DOT,         RU_QUOT,        xxx,
_______, _______, _______, _______, _______, _______,
_______),

[SYM] = LAYOUT_LR(
xxx,            KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,
xxx,            KC_QUOT,        KC_COMM,        KC_DOT,         KC_DQUO,        RU_GRV,
xxx,            KC_PLUS,        KC_MINS,        KC_ASTR,        KC_SLSH,        KC_EQL,
xxx,            KC_SCLN,        xxx,            xxx,            xxx,            xxx,
    KC_CIRC,        KC_AMPR,        KC_LPRN,        KC_RPRN,        KC_PIPE,        xxx,
    xxx,            xxx,            KC_LCBR,        KC_RCBR,        KC_BSLS,        xxx,
    KC_TILD,        KC_UNDS,        KC_LBRC,        KC_RBRC,        KC_COLN,        xxx,
    KC_GRV,         RU_RBRC,        KC_LABK,        KC_RABK,        KC_QUES,        xxx,
xxx, xxx, xxx, xxx, xxx, xxx,
xxx),

[NAV] = LAYOUT_LR(
xxx,            KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         xxx,
xxx,            KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RGHT,        xxx,
xxx,            xxx,            xxx,            xxx,            xxx,            xxx,
xxx,            xxx,            xxx,            xxx,            xxx,            xxx,
    xxx,            xxx,            xxx,            xxx,            xxx,            xxx,
    xxx,            xxx,            xxx,            xxx,            xxx,            xxx,
    xxx,            xxx,            KC_LALT,        KC_LSFT,        KC_LCTL,        xxx,
    xxx,            xxx,            xxx,            KC_ALGR,        xxx,            KC_LSFT,
xxx, xxx, xxx, xxx, xxx, xxx,
xxx),

[FN] = LAYOUT_LR(
xxx,            xxx,            xxx,            xxx,            xxx,            xxx,
xxx,            xxx,            xxx,            xxx,            xxx,            xxx,
xxx,            KC_LCTL,        KC_LSFT,        KC_LALT,        xxx,            xxx,
xxx,            xxx,            xxx,            xxx,            xxx,            xxx,
    xxx,            KC_F9,          KC_F10,         KC_F11,         KC_F12,         xxx,
    xxx,            KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_INS,
    KC_VOLU,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_PSCR,
    KC_VOLD,        KC_MUTE,        xxx,            xxx,            xxx,            xxx,
xxx, xxx, xxx, xxx, xxx, xxx,
xxx),

[MOUSE] = LAYOUT_LR(
xxx,            xxx,            xxx,            xxx,            xxx,            xxx,
xxx,            xxx,            xxx,            xxx,            xxx,            xxx,
xxx,            KC_LCTL,        KC_LSFT,        KC_LALT,        xxx,            xxx,
TO(BASE),       xxx,            xxx,            xxx,            xxx,            xxx,
    xxx,            xxx,           xxx,             xxx,            xxx,            xxx,
    xxx,            KC_WH_U,       KC_MS_U,         xxx,            xxx,            xxx,
    KC_WH_D,        KC_MS_L,       KC_MS_D,         KC_MS_R,        KC_BTN2,        xxx,
    xxx,            xxx,           xxx,             xxx,            xxx,            TO(BASERU),
xxx, xxx, xxx, KC_BTN1, xxx, xxx,
xxx),

[MOUSE1] = LAYOUT_LR(
xxx,            KC_WH_U,        KC_WH_L,        KC_MS_U,        KC_WH_R,        xxx,
xxx,            KC_WH_D,        KC_MS_L,        KC_MS_D,        KC_MS_R,        xxx,
KC_BTN2,        xxx,            xxx,            xxx,            xxx,            xxx,
TO(BASE),       xxx,            xxx,            xxx,            xxx,            xxx,
    xxx,            xxx,           xxx,             xxx,            xxx,            xxx,
    xxx,            xxx,           xxx,             xxx,            xxx,            xxx,
    xxx,            xxx,           KC_LALT,         KC_LSFT,        KC_LCTL,        xxx,
    xxx,            xxx,           xxx,             xxx,            xxx,            TO(BASERU),
xxx, xxx, KC_BTN1, xxx, xxx, xxx,
xxx),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(RU_XA):
            if (record->tap.count && record->event.pressed) {
                tap_code16(ALGR(KC_A));
                return false;
            }
            break;
        case LSFT_T(RU_XS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(ALGR(KC_S));
                return false;
            }
            break;
        case LALT_T(RU_XD):
            if (record->tap.count && record->event.pressed) {
                tap_code16(ALGR(KC_D));
                return false;
            }
            break;
        case LT(SYM,RU_XF):
            if (record->tap.count && record->event.pressed) {
                tap_code16(ALGR(KC_F));
                return false;
            }
            break;
        case LT(SYM,RU_XJ):
            if (record->tap.count && record->event.pressed) {
                tap_code16(ALGR(KC_J));
                return false;
            }
            break;
        case LALT_T(RU_XK):
            if (record->tap.count && record->event.pressed) {
                tap_code16(ALGR(KC_K));
                return false;
            }
            break;
        case LSFT_T(RU_XL):
            if (record->tap.count && record->event.pressed) {
                tap_code16(ALGR(KC_L));
                return false;
            }
            break;
        case LCTL_T(RU_XSCLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(ALGR(KC_SCLN));
                return false;
            }
            break;
    }
    return true;
}

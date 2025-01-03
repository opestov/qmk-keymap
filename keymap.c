#include QMK_KEYBOARD_H

#define xxx KC_NO

enum custom_keycodes {
  KBD_TOGGLE = SAFE_RANGE,
};

// OS is expected to have a custom Russian layout where:
// - Shift+digit is the same as on the English layout;
// - following symbols are defined on the ALGR layer
#define RU_QUOT ALGR(KC_Q)
#define RU_COMM ALGR(KC_W)
#define RU_DOT ALGR(KC_E)
#define RU_DQUO ALGR(KC_R)
#define RU_LCBR ALGR(KC_I)
#define RU_RCBR ALGR(KC_O)
#define RU_PIPE ALGR(KC_BSLS)
#define RU_SLSH ALGR(KC_F)
#define RU_TILD ALGR(KC_H)
#define RU_LBRC ALGR(KC_K)
#define RU_RBRC ALGR(KC_L)
#define RU_COLN ALGR(KC_SCLN)
#define RU_SCLN ALGR(KC_Z)
#define RU_GRV ALGR(KC_N)
#define RU_LABK ALGR(KC_COMM)
#define RU_RABK ALGR(KC_DOT)
#define RU_QUES ALGR(KC_SLSH)

#define LAYOUT_LR(\
    L11,L12,L13,L14,L15,L16,\
    L21,L22,L23,L24,L25,L26,\
    L31,L32,L33,L34,L35,\
    R11,R12,R13,R14,R15,R16,\
    R21,R22,R23,R24,R25,R26,\
    R31,R32,R33,R34,R35)\
LAYOUT_ansi_84(\
L11,L12,L13,L14,L15,L16,xxx,xxx,R11,R12,R13,R14,R15,R16,KBD_TOGGLE,xxx,\
L21,L22,L23,L24,L25,L26,xxx,xxx,R21,R22,R23,R24,R25,R26,xxx,\
L31,L32,L33,L34,L35,KC_TAB,xxx,KC_DEL,R31,R32,R33,R34,R35,xxx,KC_PGUP,\
xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,xxx,KC_PGDN,\
xxx,xxx,xxx,LGUI_T(KC_HOME),KC_LEFT,KC_UP,KC_DOWN,KC_RGHT,LGUI_T(KC_END),xxx,xxx,KC_MS_U,KC_BTN2,KC_WH_U,\
xxx,xxx,xxx,LT(DIG,KC_SPC),xxx,KC_BTN1,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D)

enum layers{
    WIN_BASE,
    WIN_FN,
    BASE,
    BASER,
    SYM,
    SYMR,
    DIG,
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
    KC_BSPC,        LCTL_T(KC_A),   LSFT_T(KC_S),   KC_D,           LT(SYM,KC_F),   KC_G,
                    LALT_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,
    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,
    KC_H,           LT(SYM,KC_J),   KC_K,           LSFT_T(KC_L),   LCTL_T(KC_SCLN),KC_ENT,
    KC_N,           KC_M,           KC_COMM,        KC_DOT,         LALT_T(KC_QUOT)),

[BASER] = LAYOUT_LR(
    _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        LT(SYMR,KC_F),  _______,
                    _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,
    _______,        LT(SYMR,KC_J),  _______,        _______,        LCTL_T(KC_SCLN),_______,
    _______,        _______,        KC_COMM,        KC_DOT,         _______),

[SYM] = LAYOUT_LR(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,
    KC_GRV,         KC_QUOT,        KC_COMM,        KC_DOT,         KC_DQUO,        xxx,
                    KC_SCLN,        KC_PIPE,        KC_BSLS,        KC_SLSH,        KC_UNDS,
    KC_CIRC,        KC_AMPR,        KC_LPRN,        KC_RPRN,        KC_MINS,        KC_EQL,
    KC_LCBR,        KC_ASTR,        KC_LBRC,        KC_RBRC,        KC_COLN,        KC_PLUS,
    KC_RCBR,        xxx,            KC_LABK,        KC_RABK,        KC_QUES),

[SYMR] = LAYOUT_LR(
    RU_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,
    RU_GRV,         RU_QUOT,        RU_COMM,        RU_DOT,         RU_DQUO,        KC_GRV,
                    RU_SCLN,        RU_PIPE,        KC_BSLS,        RU_SLSH,        KC_UNDS,
    KC_CIRC,        KC_AMPR,        KC_LPRN,        KC_RPRN,        KC_MINS,        KC_EQL,
    RU_LCBR,        KC_ASTR,        RU_LBRC,        RU_RBRC,        RU_COLN,        KC_PLUS,
    RU_RCBR,        KC_RBRC,        RU_LABK,        RU_RABK,        RU_QUES),

[DIG] = LAYOUT_LR(
    KC_F12,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,
    KC_CAPS,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,
                    KC_MUTE,        KC_VOLD,        KC_VOLU,        KC_PSCR,        KC_INS,
    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           xxx,
    KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    HYPR(KC_1),     HYPR(KC_2),     HYPR(KC_3),     HYPR(KC_4),     HYPR(KC_5)),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
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

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    MACRO_ANDERS,
    MACRO_ASTROM,
    MACRO_DOMAIN,
    MACRO_EMAIL,
    MACRO_HTTP,
    MACRO_KVM_1,
    MACRO_KVM_2,
    MACRO_KVM_3,
    MACRO_KVM_4,
    MACRO_NL_COL,
    MACRO_NL_BR_C,
    MACRO_NL_BR_O,
    MACRO_RETURN,
    MACRO_ADVANCED,
    MACRO_QU,
    MACRO_QUOTE,
};

// ....

uint8_t mod_state;
bool    process_record_user(uint16_t keycode, keyrecord_t *record) {
       mod_state = get_mods();

       switch (keycode) {
               // MACRO_ANDERS
        case MACRO_ANDERS:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed
                    SEND_STRING("Anders");
                } else {
                       // Shift is not pressed
                    SEND_STRING("anders");
                }
            }
            break;
        // MACRO_ASTROM
        case MACRO_ASTROM:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed
                    send_unicode_string("Åström");
                } else {
                       // Shift is not pressed
                    SEND_STRING("astrom");
                }
            }
            break;

        // MACRO_DOMAIN
        case MACRO_DOMAIN:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed
                    SEND_STRING("lyngon.com");
                } else {
                       // Shift is not pressed
                    SEND_STRING("astrom.sg");
                }
            }
            break;

        // MACRO_EMAIL
        case MACRO_EMAIL:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed
                    SEND_STRING("anders@lyngon.com");
                } else {
                       // Shift is not pressed
                    SEND_STRING("anders@astrom.sg");
                }
            }
            break;

        // MACRO_HTTP
        case MACRO_HTTP:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed
                    SEND_STRING("https://");
                } else {
                       // Shift is not pressed
                    SEND_STRING("http://");
                }
            }
            break;

        // MACRO_KVM_1
        case MACRO_KVM_1:
            if (record->event.pressed) {
                   SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) SS_TAP(X_1));
            }
            break;

        // MACRO_KVM_2
        case MACRO_KVM_2:
            if (record->event.pressed) {
                   SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) SS_TAP(X_2));
            }
            break;

        // MACRO_KVM_3
        case MACRO_KVM_3:
            if (record->event.pressed) {
                   SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) SS_TAP(X_3));
            }
            break;

        // MACRO_KVM_4
        case MACRO_KVM_4:
            if (record->event.pressed) {
                   SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) SS_TAP(X_4));
            }
            break;

        // MACRO_NL_COL
        case MACRO_NL_COL:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed
                    SEND_STRING(":\n");
                } else {
                       // Shift is not pressed
                    SEND_STRING(";\n");
                }
            }
            break;

        // MACRO_NL_BR_C
        case MACRO_NL_BR_C:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed
                    // Do nothinig (for some reason)
                } else {
                       // Shift is not pressed
                    SEND_STRING("}\n");
                }
            }
            break;

        // MACRO_NL_BR_O
        case MACRO_NL_BR_O:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed
                    // Do nothinig (for some reason)
                } else {
                       // Shift is not pressed
                    SEND_STRING("{\n");
                }
            }
            break;

        // MACRO_RETURN
        case MACRO_RETURN:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed
                    // Do nothinig (for some reason)
                } else {
                       SEND_STRING("return");
                }
            }
            break;

        // MACRO_ADVANCED
        case MACRO_ADVANCED:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed

                    // Temporarily unregister the Shift, during the macro.
                    if (mod_state & MOD_BIT(KC_LSHIFT)) unregister_code(KC_LSHIFT);
                    if (mod_state & MOD_BIT(KC_RSHIFT)) unregister_code(KC_RSHIFT);

                    if (mod_state & MOD_MASK_CTRL) {
                           // Ctrl is pressed

                        // Temporarily unregister the Ctrl, during the macro.
                        if (mod_state & MOD_BIT(KC_LCTRL)) unregister_code(KC_LCTRL);
                        if (mod_state & MOD_BIT(KC_RCTRL)) unregister_code(KC_RCTRL);

                        SEND_STRING("This is sent if SHIFT and CTRL is pressed");

                        // Re-register the Ctrl, after the macro.
                        if (mod_state & MOD_BIT(KC_LCTRL)) register_code(KC_LCTRL);
                        if (mod_state & MOD_BIT(KC_RCTRL)) register_code(KC_RCTRL);
                    } else {
                           SEND_STRING("This is sent if only SHIFT is pressed");
                    }

                       // Re-register the Shift, after the macro.
                    if (mod_state & MOD_BIT(KC_LSHIFT)) register_code(KC_LSHIFT);
                    if (mod_state & MOD_BIT(KC_RSHIFT)) register_code(KC_RSHIFT);

                } else {
                       // Shift is not pressed
                    SEND_STRING("This is sent if neither SHIFT nor CTRL is pressed.");
                }
            }
               break;

        // MACRO_QU
        case MACRO_QU:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed
                    SEND_STRING("Qu");
                } else {
                       // Shift is not pressed
                    SEND_STRING("qu");
                }
            }
            break;

        // MACRO_QUOTE
        case MACRO_QUOTE:
            if (record->event.pressed) {
                   if (mod_state & MOD_MASK_SHIFT) {
                       // Shift is pressed
                    SEND_STRING("\"\"\"\"\"\"" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
                } else {
                       // Shift is not pressed
                    SEND_STRING("f\"\"" SS_TAP(X_LEFT));
                }
            }
            break;

        case RGB_SLD:
            if (record->event.pressed) {
                   rgblight_mode(1);
            }
            return false;
    }
       return true;
}

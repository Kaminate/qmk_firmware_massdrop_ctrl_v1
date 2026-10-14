#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

RGB_MATRIX_EFFECT(ICE_TYPING)

#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern uint8_t ice_target_hue[RGB_MATRIX_LED_COUNT];

bool ICE_TYPING(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t speed = qadd8(rgb_matrix_config.speed, 1);
    uint16_t max_tick = 65535 / speed;

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        uint16_t tick = max_tick;

        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i &&
                g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                break;
            }
        }

        uint16_t offset = scale16by8(tick, speed);
        uint8_t age = offset > 255 ? 255 : (uint8_t)offset;
        uint8_t blend = qadd8(age, age);

        uint8_t target = ice_target_hue[i];
        if (target < 128 || target > 180) {
            target = 160;
        }

        HSV hsv = rgb_matrix_config.hsv;
        hsv.h = 128 + scale8(blend, target - 128);
        hsv.s = 40 + scale8(blend, 215);
        hsv.v = scale8(255 - age, hsv.v);

        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#    endif
#endif

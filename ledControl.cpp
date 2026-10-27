#include "ledControl.h"
#include "buttonControl.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "pwmController.h"
#include <cstdint>
#include <iostream>
#include <pico/stdio.h>
#include <pico/time.h>
#include <sys/_types.h>

void setLedToPwm(const unsigned LED_PIN, long pwm_value) {
  pwm_set_gpio_level(LED_PIN, pwm_value);
}

void blinkFrequency(const unsigned LED_PIN, long pwm_value,
                    uint32_t &lastToggle) {
  uint32_t now = to_ms_since_boot(get_absolute_time());
  static bool ledOn = false;
  uint32_t interval = map(pwm_value, 0, 255, 1000, 50);
  if (now - lastToggle >= interval) {
    ledOn = !ledOn;
    pwm_set_gpio_level(LED_PIN, 256 * ledOn);
    lastToggle = now;
  }
}

void ledBreathe(const unsigned LED_PIN, long pwm_value) {
  static bool direction = true;
  static int brightness{255};
  uint32_t interval = map(pwm_value, 0, 255, 20, 2);
  pwm_set_gpio_level(LED_PIN, brightness);

  if (direction) {
    brightness--;
  } else {
    brightness++;
  }

  if (brightness == 0 || brightness == 255) {
    direction = !direction;
  }
  sleep_ms(interval);
}

#include "buttonControl.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "ledControl.h"
#include "pico/stdlib.h"
#include "pwmController.h"
#include <iostream>
#include <pico/stdio.h>
#include <pico/time.h>

void setLedToPwm(const unsigned LED_PIN, long pwm_value) {
  pwm_set_gpio_level(LED_PIN, pwm_value);
  sleep_ms(50);
}

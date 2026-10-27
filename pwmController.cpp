#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <iostream>
#include <pico/stdio.h>

void initializeAll(const unsigned &POT_PIN) {
  adc_init();
  adc_gpio_init(POT_PIN);
  adc_select_input(POT_PIN - 26);
}
void setUpPWM(const unsigned &LED_PIN) {
  gpio_set_function(LED_PIN, GPIO_FUNC_PWM); // Pin controlled by HW func
  unsigned int slice_num{
      pwm_gpio_to_slice_num(LED_PIN)}; // What counter controls the pin
  pwm_set_wrap(slice_num, 255);        // Wrap range
  pwm_set_enabled(slice_num, true);
}
long map(long value, long in_min, long in_max, long out_min, long out_max) {
  return ((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
};
long pwmValue() {
  long result = adc_read();
  std::cout << result << '\n';
  return map(result, 0, 4095, 0, 255);
};

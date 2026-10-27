#include "buttonControl.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "ledControl.h"
#include "pico/stdlib.h"
#include "pwmController.h"
#include <cstdint>
#include <iostream>
#include <pico/stdio.h>
#include <pico/time.h>
#include <pico/types.h>

constexpr unsigned BUTTON_PIN = 15;
constexpr unsigned POT_PIN = 26;
constexpr unsigned LED_PIN = 16;

int main() {
  stdio_init_all();
  sleep_ms(2000);
  std::cout << "Init %l";
  buttonInit(BUTTON_PIN);
  initializeAll(POT_PIN);
  setUpPWM(LED_PIN);
  long currentPwm{};
  int counter{};
  while (true) {
    counter = buttonControl(BUTTON_PIN);
    currentPwm = pwmValue();
    if (counter == 0) {
      setLedToPwm(LED_PIN, 0);
    } else if (counter == 1) {
      setLedToPwm(LED_PIN, currentPwm);
    } else if (counter == 2) {
      static uint32_t lastToggle = to_ms_since_boot(get_absolute_time()) / 1000;
      blinkFrequency(LED_PIN, currentPwm, lastToggle);
    } else if (counter == 3) {
      ledBreathe(LED_PIN, currentPwm);
    }
  }
  return 0;
}

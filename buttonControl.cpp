#include "buttonControl.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <cstdint>
#include <hardware/gpio.h>
#include <iostream>
#include <pico/stdio.h>
#include <pico/time.h>
#include <vector>

void buttonCount(int &count) {
  if (count >= 3 || count < 0) {
    count = 0;
  } else {
    count++;
  }
}

int buttonControl(const unsigned &BUTTON_PIN) {
  static int count{0};
  static bool buttonUp = true;
  static uint32_t lastTimeChange{0};
  static int lastRead = 1;
  uint32_t now{to_ms_since_boot(get_absolute_time())};
  int read = gpio_get(BUTTON_PIN);
  if (read != lastRead) {
    lastTimeChange = now;
    lastRead = read;
  }
  if (now - lastTimeChange > DEBOUNCE_TIME) {
    if (read == 0 && buttonUp) {

      buttonUp = !buttonUp;
      buttonCount(count);
      std::cout << count << '\n';
    }
    if (read == 1) {
      buttonUp = true;
    }
  }
  return count;
}

void buttonInit(const unsigned &BUTTON_PIN) {
  gpio_init(BUTTON_PIN);
  gpio_set_dir(BUTTON_PIN, GPIO_IN);
  gpio_pull_up(BUTTON_PIN);
}

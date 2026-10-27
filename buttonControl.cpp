#include "buttonControl.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
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
  static bool lastStatus = true;

  int read = gpio_get(BUTTON_PIN);
  if (read == 0 && lastStatus == true) {
    lastStatus = !lastStatus;
    buttonCount(count);
    sleep_ms(250);
    std::cout << count << '\n';
  }
  if (read == 1) {
    lastStatus = true;
  }

  return count;
}

void buttonInit(const unsigned &BUTTON_PIN) {
  gpio_init(BUTTON_PIN);
  gpio_set_dir(BUTTON_PIN, GPIO_IN);
  gpio_pull_up(BUTTON_PIN);
}

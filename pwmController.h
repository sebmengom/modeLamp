#ifndef PWMCONTROLLER_H
#define PWMCONTROLLER_H
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <iostream>
#include <pico/stdio.h>

void initializeAll(const unsigned &POT_PIN);
void setUpPWM(const unsigned &LED_PIN);
long map(long value, long in_min, long in_max, long out_min, long out_max);
long pwmValue();

#endif

#ifndef LEDCONTROLL_H
#define LEDCONTROLL_H
#include "buttonControl.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "pwmController.h"
#include <iostream>
#include <pico/stdio.h>
#include <pico/time.h>

void setLedToPwm(const unsigned LED_PIN, long pwm_value);
void blinkFrequency(const unsigned LED_PIN, long pwm_value,
                    uint32_t &lastToggle);
void ledBreathe(const unsigned LED_PIN, long pwm_value);
#endif // !LEDCONTROLL_H

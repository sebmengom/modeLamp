#ifndef BUTTONCONTROL_H
#define BUTTONCONTROL_H

#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <cstdint>
#include <iostream>
#include <pico/stdio.h>
#include <sys/_types.h>

constexpr uint32_t DEBOUNCE_TIME = 50;

void buttonCount(int &count);
int buttonControl(const unsigned &BUTTON_PIN);
void buttonInit(const unsigned &BUTTON_PIN);

#endif // !BUTTONCONTROL_H

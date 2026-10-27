#ifndef BUTTONCONTROL_H
#define BUTTONCONTROL_H

#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <iostream>
#include <pico/stdio.h>

void buttonCount(int &count);
int buttonControl(const unsigned &BUTTON_PIN);
void buttonInit(const unsigned &BUTTON_PIN);

#endif // !BUTTONCONTROL_H

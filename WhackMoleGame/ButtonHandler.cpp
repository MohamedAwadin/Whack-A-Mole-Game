/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                           *********************/
/*******************  FILE NAME      : ButtonHandler.cpp                                          *********************/
/*******************  Layer          : HAL(ANALOG PUSH_BUTTONS )                                *********************/
/*******************  Project        : Whack-A-Mole-Game                                        *********************/
/*******************  Microcontroller: Arduino Uno (or compatible)                              *********************/
/*******************  Version        : 1.00                                                     *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/

/**
 * @brief 
 * This file defines the functions for handling button presses.
 */
#include <Arduino.h>
#include "ButtonHandler.h"
#include "Config.h"

void checkButtonPresses(int button_pin, const int led_pins[], int &score) {
  int analogValue = analogRead(button_pin);
  for (int i = 0; i < LED_COUNT; i++) {
    if (analogValue > BUTTON_VALUES[i] - BUTTON_TOLERANCE && analogValue < BUTTON_VALUES[i] + BUTTON_TOLERANCE) {
      if (digitalRead(led_pins[i]) == HIGH) {
        digitalWrite(led_pins[i], LOW);
        score++;
      }
    }
  }
}

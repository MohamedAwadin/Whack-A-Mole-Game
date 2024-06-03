/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                           *********************/
/*******************  FILE NAME      : PinManager.cpp                                           *********************/
/*******************  Layer          : Private                                                  *********************/
/*******************  Project        : Whack-A-Mole-Game                                        *********************/
/*******************  Microcontroller: Arduino Uno (or compatible)                              *********************/
/*******************  Version        : 1.00                                                     *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/


/**
 * This file defines the functions for pin initialization.
 */
#include <Arduino.h>
#include "PinManager.h"
#include "Config.h"

void initializePins() {
  pinMode(PLAYER1_BUTTON_PIN, INPUT);
  pinMode(PLAYER2_BUTTON_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(PLAYER1_LEDS[i], OUTPUT);
    pinMode(PLAYER2_LEDS[i], OUTPUT);
  }
}

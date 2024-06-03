/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                           *********************/
/*******************  FILE NAME      : EndGameSequence.cpp                                        *********************/
/*******************  Layer          : Private (Algorithm)                                      *********************/
/*******************  Project        : Whack-A-Mole-Game                                        *********************/
/*******************  Microcontroller: Arduino Uno (or compatible)                              *********************/
/*******************  Version        : 1.00                                                     *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/

/**
 * @brief 
 * This file defines the functions for handling the end game sequence.
 */

#include <Arduino.h>
#include "EndGameSequence.h"
#include "Config.h"

void playEndGameSequence() {
  for (int i = 0; i < 3; i++) {
    flashLEDS(BUZZER_PIN, PLAYER1_LEDS, LED_COUNT);
    flashLEDS(BUZZER_PIN, PLAYER2_LEDS, LED_COUNT);
  }
}

void flashLEDS(int buzzer_pin, const int led_pins[], int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(led_pins[i], HIGH);
  }
  digitalWrite(buzzer_pin, HIGH);
  delay(500);
  
  for (int i = 0; i < count; i++) {
    digitalWrite(led_pins[i], LOW);
  }
  digitalWrite(buzzer_pin, LOW);
  delay(500);
}

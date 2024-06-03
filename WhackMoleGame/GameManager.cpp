/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                           *********************/
/*******************  FILE NAME      : GameManager.cpp                                          *********************/
/*******************  Layer          : Private                                                  *********************/
/*******************  Project        : Whack-A-Mole-Game                                        *********************/
/*******************  Microcontroller: Arduino Uno (or compatible)                              *********************/
/*******************  Version        : 1.00                                                     *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/

/**
 * @brief This file defines the functions for game management.
 * 
 */

#include <Arduino.h>
#include "GameManager.h"
#include "Config.h"
#include "LCDManager.h"
#include "ButtonHandler.h"

void initializeGame() {
  player1_score = 0;
  player2_score = 0;
  action_speed = INITIAL_ACTION_SPEED;
  step_counter = 0;
}

void handleGameLoop() {
  step_counter++;
  if (step_counter > action_speed) {
    triggerAction();
  }
  checkButtonPresses(PLAYER1_BUTTON_PIN, PLAYER1_LEDS, player1_score);
  checkButtonPresses(PLAYER2_BUTTON_PIN, PLAYER2_LEDS, player2_score);
  updateLCDs();
}

void triggerAction() {
  step_counter = 0;
  action_speed -= action_speed / ACTION_SPEED_DECREMENT_FACTOR;
  if (action_speed < MIN_ACTION_SPEED) {
    action_speed = MIN_ACTION_SPEED;
  }
  Serial.print("       s=");
  Serial.println(action_speed);

  int pin_light = random(0, LED_COUNT);
  digitalWrite(PLAYER1_LEDS[pin_light], HIGH);
  digitalWrite(PLAYER2_LEDS[pin_light], HIGH);
}

void displayWinner() {
  if (player1_score > player2_score) {
    lcd1.setCursor(8, 0);
    lcd1.print("WINNER");
    lcd2.setCursor(8, 0);
    lcd2.print("LOSSER");
  } else {
    lcd1.setCursor(8, 0);
    lcd1.print("LOSSER");
    lcd2.setCursor(8, 0);
    lcd2.print("WINNER");
  }
}

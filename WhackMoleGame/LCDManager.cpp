/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                           *********************/
/*******************  FILE NAME      : LCDManager.cpp                                            *********************/
/*******************  Layer          : HAL (LCD 16x2)                                           *********************/
/*******************  Project        : Whack-A-Mole-Game                                        *********************/
/*******************  Microcontroller: Arduino Uno (or compatible)                              *********************/
/*******************  Version        : 1.00                                                     *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/

/*
 * This file defines the functions for LCD management.
 */
#include <Arduino.h>
#include "LCDManager.h"
#include "Config.h"

void initializeLCDs() {
  lcd1.init();
  lcd2.init();
  lcd1.backlight();
  lcd2.backlight();

  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("PLAYER1:");
  
  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("PLAYER2:");
}

void updateLCDs() {
  if (step_counter % 100 == 0) {
    lcd1.setCursor(0, 1);
    lcd1.print(player1_score);
    
    lcd2.setCursor(0, 1);
    lcd2.print(player2_score);
  }
}

/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                           *********************/
/*******************  FILE NAME      : Config.cpp                                               *********************/
/*******************  Layer          : Configuration                                            *********************/
/*******************  Project        : Whack-A-Mole-Game                                        *********************/
/*******************  Microcontroller: Arduino Uno (or compatible)                              *********************/
/*******************  Version        : 1.00                                                     *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/

/*
 * This file defines the global variables declared in "Config.h".
 * 
*/

#include <Arduino.h>
#include "Config.h"

int player1_score = 0;
int player2_score = 0;
int action_speed = INITIAL_ACTION_SPEED;
int step_counter = 0;

LiquidCrystal_I2C lcd1(LCD1_ADDRESS, 16, 2); // LCD for Player 1
LiquidCrystal_I2C lcd2(LCD2_ADDRESS, 16, 2); // LCD for Player 2

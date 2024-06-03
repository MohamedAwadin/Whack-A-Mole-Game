/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                           *********************/
/*******************  FILE NAME      : Config.h                                                 *********************/
/*******************  Layer          : Configuration                                            *********************/
/*******************  Project        : Whack-A-Mole-Game                                        *********************/
/*******************  Microcontroller: Arduino Uno (or compatible)                              *********************/
/*******************  Version        : 1.00                                                     *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/
/*
 * This file contains all the constants and global variables. 
 * 
*/
#ifndef CONFIG_H
#define CONFIG_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin Definitions
const int BUZZER_PIN = 7;
const int PLAYER1_BUTTON_PIN = A0;
const int PLAYER2_BUTTON_PIN = A1;
const int RANDOM_SEED_PIN = A2;

// LED Pin Arrays
const int PLAYER1_LEDS[] = {2, 3, 4, 5, 6};
const int PLAYER2_LEDS[] = {8, 9, 10, 11, 12};

// Button Analog Values and Tolerance
const int BUTTON_VALUES[] = {913, 429, 267, 179, 110};
const int BUTTON_TOLERANCE = 20;

// Game Settings
const int LED_COUNT = 5;
const int MAX_SCORE = 100;
const int INITIAL_ACTION_SPEED = 2000;
const int MIN_ACTION_SPEED = 250;
const int ACTION_SPEED_DECREMENT_FACTOR = 50;

// LCD Display Addresses
const uint8_t LCD1_ADDRESS = 0x20;
const uint8_t LCD2_ADDRESS = 0x27;

// Global Variables
extern int player1_score;
extern int player2_score;
extern int action_speed;
extern int step_counter;

extern LiquidCrystal_I2C lcd1;
extern LiquidCrystal_I2C lcd2;

#endif

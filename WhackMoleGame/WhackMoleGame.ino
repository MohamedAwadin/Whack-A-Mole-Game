/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                           *********************/
/*******************  FILE NAME      : WhackMoleGame.ino                                        *********************/
/*******************  Layer          : Application (RUNNABLE&SETUP)                             *********************/
/*******************  Project        : Whack-A-Mole-Game                                        *********************/
/*******************  Microcontroller: Arduino Uno (or compatible)                              *********************/
/*******************  Version        : 1.00                                                     *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/

/*
 * This is the main Arduino sketch file
 * 
*/

#include "Config.h"
#include "LCDManager.h"
#include "PinManager.h"
#include "GameManager.h"
#include "ButtonHandler.h"
#include "EndGameSequence.h"

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(RANDOM_SEED_PIN));
  
  initializeLCDs();
  initializePins();
  initializeGame();
}

void loop() {
  if (player1_score < MAX_SCORE && player2_score < MAX_SCORE) {
    handleGameLoop();
  } else {
    displayWinner();
    playEndGameSequence();
  }
}

/********************************************************************************************************************/
/********************************************************************************************************************/
/*******************  Author         : Mohamed Awadin                                           *********************/
/*******************  FILE NAME      : GameManager.h                                             *********************/
/*******************  Layer          : Private                                                  *********************/
/*******************  Project        : Whack-A-Mole-Game                                        *********************/
/*******************  Microcontroller: Arduino Uno (or compatible)                              *********************/
/*******************  Version        : 1.00                                                     *********************/
/********************************************************************************************************************/
/********************************************************************************************************************/

/**
 * @brief This file declares functions for game management.
 * 
 */

#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

void initializeGame();
void handleGameLoop();
void triggerAction(); 
void displayWinner();

#endif

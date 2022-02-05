#ifndef GAME_H
#define GAME_H

#include "functions.h"

enum class GameMode
{
	Menu = 0,
	Words = 1,
	Numbers = 2,
};

extern GameMode Mode;

extern uint16_t cows, bulls, lives;
extern std::string theSequence, guessSequence;
extern bool gameWin, gameInit;

// This function procceses user input in menu and after the game ends
void processChoice(GameMode& Mode, bool& gameInit);

// This function generates the sequence depending on the game mode
void generateSequence(GameMode Mode, std::string& theSequence);

// This function searches for "bulls" and "cows" in user inputted sequence 
void findTheBeasts(std::string word, std::string guess, uint16_t& bulls, uint16_t& ñows);

#endif

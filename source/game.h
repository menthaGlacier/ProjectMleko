#ifndef GAME_H
#define GAME_H

#include <string>
#include "functions.h"

enum class GameMode
{
	Menu = 0,
	Words = 1,
	Numbers = 2,
};

extern uint16_t cows, bulls, lives;
extern std::string theSequence, guessSequence;
extern bool gameWin, gameInit;

extern GameMode Mode;

void generateSequence(GameMode Mode, std::string& theSequence);

#endif

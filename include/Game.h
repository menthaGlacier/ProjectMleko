#ifndef GAME_H
#define GAME_H

#include "common.h"

class Game {
public:
	Game();
	Game(const Game& copy) = delete;

	void init();
private:
	enum class GameMode {
		None, Words, Numbers
	} gameMode;

	uint16_t cows, bulls, tries;
	std::string answer;
};

#endif /* GAME_H */

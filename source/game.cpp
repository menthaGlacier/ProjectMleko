#include "game.h"

uint16_t cows = 0, bulls = 0, lives = 1;
bool gameWin = false, gameInit = false;
bool debugToggle = false;
std::string theSequence, guessSequence;
GameMode Mode = GameMode::Menu;

void generateSequence(GameMode Mode, std::string& theSequence)
{
	if (Mode == GameMode::Words)
	{
		size_t wordsValue;

		std::ifstream readFile("words.txt");
		if (!readFile)
		{
			std::cerr << "FILE READING ERROR" << '\n';
			system("pause");
			exit(1);
		}

		readFile >> wordsValue;
		std::string* words = new std::string[wordsValue];

		for (int i = 0; i < wordsValue; i++)
		{
			readFile >> words[i];
		}

		if (Mode == GameMode::Words) { theSequence = words[randomGenerator(0, wordsValue)]; }
		delete[] words;
	}

	else if (Mode == GameMode::Numbers)
	{
		uint16_t difficulty = randomGenerator(4, 7);
		std::string number = "";

		for (int i = 0; i < difficulty; i++)
		{
			// There will be algorithm eventually
		}

		theSequence = number;
	}
}

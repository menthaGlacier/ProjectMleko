#include "game.h"

uint16_t cows = 0, bulls = 0, lives = 1;
bool gameWin = false, gameInit = false;
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
			std::cerr << "An error occured while trying to open words.txt!" << '\n';
			system("pause");
			exit(1);
		}

		readFile >> wordsValue;
		std::string* words = new std::string[wordsValue];

		for (int i = 0; i < wordsValue; i++)
		{
			std::string tryWord;
			readFile >> tryWord;
			if (tryWord == "") { wordsValue = i-1; break; }
			if (!filter(tryWord)) { --i; continue; }
			words[i] = tryWord;
		}

		if (wordsValue < 10)
		{
			std::cerr << "Value of Words can't be lower than 10, please modify your words.txt file!" << '\n';
			system("pause");
			exit(1);
		}

		theSequence = words[randomGenerator(0, wordsValue)];
		delete[] words;
	}

	else if (Mode == GameMode::Numbers)
	{
		// The algorithm takes a random number (in range of 0 to N) in array of numbers
		// and replaces it with 99, it then sorts array and decreasing N, repeating the
		// process until the number of length of diffuculty is created 
		uint16_t N = 10;
		uint16_t buffer[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		uint16_t difficulty = randomGenerator(4, 7);
		std::string number = "";

		for (int i = 0; i < difficulty; i++)
		{
			uint16_t tryNumber = randomGenerator(0, N-1);
			number += std::to_string(buffer[tryNumber]);
			buffer[tryNumber] = 99;
			std::sort(buffer, buffer+N); N--;
		}

		theSequence = number;
	}
}

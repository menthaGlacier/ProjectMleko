#include "game.h"

uint16_t cows = 0, bulls = 0, lives = 1;
bool gameWin = false, gameInit = false;
std::string theSequence, guessSequence;
GameMode Mode = GameMode::Menu;

void processChoice(GameMode& Mode, bool& gameInit)
{
	char choice;

	while (true)
	{
		std::cout << "Your choice: ";
		std::cin >> choice;
		std::cin.ignore(255, '\n');

		if (Mode == GameMode::Menu)
		{
			if (choice == '1') { Mode = GameMode::Words; break; }
			else if (choice == '2') { Mode = GameMode::Numbers; break; }
		}

		else if (Mode == GameMode::Words || Mode == GameMode::Numbers)
		{
			if (choice == '1')
			{
				gameInit = false;
				system("cls");
				break;
			}

			else if (choice == '2')
			{
				if (Mode == GameMode::Words) { Mode = GameMode::Numbers; }
				else if (Mode == GameMode::Numbers) { Mode = GameMode::Words; }

				gameInit = false;
				system("cls");
				break;
			}
		}
		
		if (choice == '3') { exit(0); }
	}
}

void generateSequence(GameMode Mode, std::string& theSequence)
{
	// Words Game Mode Algorithm:
	// The algorithm opens "words.txt" file and reads from it a number that specifies
	// the size of the words array. It then reads words from file until the size limit
	// is reached, or until the words run out earlier. Each word is converted to lowercase
	// and written in the array if it successfully passes the filter. The sequence is then
	// randomly selected from the array and array gets deleted

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
			toLowercase(tryWord);
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

	// Numbers Game Mode Algorithm:
	// The algorithm takes a random number (in range of 0 to N) in array of numbers
	// and replaces it with 99, it then sorts array and decreasing N, repeating the
	// process until the number of length of diffuculty is created 

	else if (Mode == GameMode::Numbers)
	{
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

void findTheBeasts(std::string word, std::string guess, uint16_t& bulls, uint16_t& cows)
{
	bulls = 0, cows = 0;
	for (int i = 0; i <= guess.length() - 1; i++)
	{
		for (int j = 0; j <= word.length() - 1; j++)
		{
			if (guess[i] == word[j])
			{
				if (i == j) { bulls++; break; }
				else if (i != j) { cows++; break; }
			}
		}
	}
}
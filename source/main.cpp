//-----------------------------------------------------
// Project Mleko
// Created by Andrew Valkonov
//-----------------------------------------------------
// Version: Release 1.1
//-----------------------------------------------------
// https://github.com/menthaGlacier/ProjectMleko
//-----------------------------------------------------

#include <iostream>
#include "words.h"
#include "functions.h"

int main()
{
	uint16_t cows = 0, bulls = 0, lives = 1;
	bool gameWin = false, gameInit = false;
	std::string theWord, guessWord;

	std::cout << "Welcome to the in-console Bulls and Cows game!" << "\t\t\t\t\t\t\t" << "Made by Andrew Valkonov." << '\n';
	std::cout << "If you don't know the rules - go to the Wikipedia, lol." << '\n';
	std::cout << "Here we use isograms - the words with no repeating letters." << "\n\n";

	system("pause");
	system("cls");

	while (true)
	{
		if (gameWin)
		{
			uint16_t choice = 0;
			gameWin = false;
			std::cout << "Nice one! Thanks for playing, king or a lady." << '\n';
			std::cout << "Do you want to play again? (1 - Yes, 2 - No)" << '\n';
			while (!(choice == 1 || choice == 2))
			{ std::cout << "Your answer: "; std::cin >> choice; }

			if (choice == 1) { gameInit = false; system("cls"); break; }
			else { std::cout << '\n' << "Bye then!"; exit(0); }
		}

		if (lives == 0)
		{
			uint16_t choice = 0;
			std::cout << "Game over, man, game over." << '\n';
			std::cout << "The word: " << theWord << '\n';
			std::cout << "Do you want to play again? (1 - Yes, 2 - No)" << '\n';
			while (!(choice == 1 || choice == 2))
			{
				std::cout << "Your answer: "; std::cin >> choice;
			}

			if (choice == 1) { gameInit = false; system("cls"); break; }
			else { std::cout << '\n' << "Bye then!"; exit(0); }
		}

		if (!gameInit)
		{
			theWord = words[randomGenerator(0, (sizeof(words) / sizeof(words[0])) - 1)];

			lives = theWord.length() * 2;
			gameInit = true;
			std::cout << "Try to guess the " << theWord.length() << " letter word!" << '\n';
		}
		
		else if (lives == 1) { std::cout << "It's your last attempt. You can make it!" << '\n'; }
		else { std::cout << "You have " << lives << " lives to go." << '\n'; }

		std::cout << "Your guess: ";
		std::cin >> guessWord;
		findTheBeats(theWord, guessWord, bulls, cows);

		std::cout << "Bulls: " << bulls << " " << "Cows: "<< cows << "\n\n";

		if (bulls == theWord.length()) { gameWin = true; }
		lives--;
	} 

}

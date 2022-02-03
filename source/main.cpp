//-----------------------------------------------------
// Project Mleko - Bulls and Cows
// Created by Andrew Valkonov
//-----------------------------------------------------
// Version: Release 2.2
//-----------------------------------------------------
// https://github.com/menthaGlacier/ProjectMleko
//-----------------------------------------------------

#include "game.h"

int main()
{
	std::cout << "Welcome to the in-console Bulls and Cows game!" << '\n' << "Made by Andrew Valkonov." << '\n';

	system("pause");
	system("cls");

	std::cout << "Main Menu." << '\n';
	std::cout << "1 - Game Mode - Words" << '\n' << "2 - Game Mode - Numbers" << '\n' << "3 - Exit" << '\n';

	processChoice(Mode, gameInit);

	while (true)
	{
		// This is a win check
		if (gameWin)
		{
			gameWin = false;
			std::cout << "Nice one! Thanks for playing!" << '\n';
			std::cout << "Do you want to play again? (1 - Yes, continue, 2 - Yes, switch Game Mode, 3 - No, Exit the Game)" << '\n';

			processChoice(Mode, gameInit);
		}

		// This is a game over check
		if (lives == 0)
		{
			std::cout << "Game over, man, game over." << '\n';
			std::cout << "The answer: " << theSequence << '\n';
			std::cout << "Do you want to play again? (1 - Yes, continue, 2 - Yes, switch Game Mode, 3 - No, Exit the Game)" << '\n';

			processChoice(Mode, gameInit);
		}

		// This is entry point of the game process and triggering everytime player starts new game
		if (!gameInit)
		{
			system("cls");

			generateSequence(Mode, theSequence);
			std::cout << "Try to guess the " << theSequence.length();

			if (Mode == GameMode::Words) { std::cout << " letter word!" << '\n'; }
			else if (Mode == GameMode::Numbers) { std::cout << " digit number!" << '\n'; }

			lives = theSequence.length() * 2;
			gameInit = true;
		}

		if (lives == 1) { std::cout << "It's your last attempt. You can make it!" << '\n'; }
		else { std::cout << "You have " << lives << " lives to go." << '\n'; }

		std::cout << "Your guess: ";
		std::cin >> guessSequence;
		std::cin.ignore(255, '\n');
		findTheBeasts(theSequence, guessSequence, bulls, cows);

		std::cout << "Bulls: " << bulls << " " << "Cows: " << cows << "\n\n";

		if (bulls == theSequence.length()) { gameWin = true; }
		lives--;
	}
}

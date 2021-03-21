//-----------------------------------------------------
// Project Mleko - Bulls and Cows
// Created by Andrew Valkonov
//-----------------------------------------------------
// Version: Pre-Release 2.0.1
//-----------------------------------------------------
// https://github.com/menthaGlacier/ProjectMleko
//-----------------------------------------------------

#include <iostream>
#include "functions.h"
#include "game.h"

int main()
{
	std::cout << "Welcome to the in-console Bulls and Cows game!" << "\t\t\t\t\t\t\t" << "Made by Andrew Valkonov." << '\n';

	system("pause");
	system("cls");

	std::cout << "Main Menu." << '\n';
	std::cout << "1 - Game Mode - Words" << '\n' << "2 - Game Mode - Numbers" << '\n' << "3 - Exit" << '\n';

	while (true)
	{
		char choice;
		std::cout << "Your choice: ";
		std::cin >> choice;
		if (choice == '1') { Mode = GameMode::Words; break; }
		else if (choice == '2') { Mode = GameMode::Numbers; break; }
		else if (choice == '3') { exit(0); }
	}

	while (true)
	{
		if (gameWin)
		{
			char choice = 0;
			gameWin = false;
			std::cout << "Nice one! Thanks for playing!" << '\n';
			std::cout << "Do you want to play again? (1 - Yes, continue, 2 - Yes, switch Game Mode, 3 - No, Exit the Game)" << '\n';

			while (true)
			{
				std::cout << "Your choice: ";
				std::cin >> choice;

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

				else if (choice == '3') { exit(0); }
			}
		}

		if (lives == 0)
		{
			char choice = 0;
			std::cout << "Game over, man, game over." << '\n';
			std::cout << "The answer: " << theSequence << '\n';
			std::cout << "Do you want to play again? (1 - Yes, continue, 2 - Yes, switch Game Mode, 3 - No, Exit the Game)" << '\n';

			while (true)
			{
				std::cout << "Your choice: ";
				std::cin >> choice;

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

				else if (choice == '3') { exit(0); }
			}
		}

		// This is entry point of the game process and triggering everytime player starts new game
		if (!gameInit)
		{
			system("cls");

			if (Mode == GameMode::Words)
			{
				generateSequence(Mode, theSequence);
				std::cout << "Try to guess the " << theSequence.length() << " letter word!" << '\n';
			}

			else if (Mode == GameMode::Numbers)
			{
				generateSequence(Mode, theSequence);
				std::cout << "Try to guess the " << theSequence.length() << " digit number!" << '\n';
			}

			lives = theSequence.length() * 2;
			gameInit = true;
		}

		if (lives == 1) { std::cout << "It's your last attempt. You can make it!" << '\n'; }
		else { std::cout << "You have " << lives << " lives to go." << '\n'; }

		std::cout << "Your guess: ";
		std::cin >> guessSequence;
		findTheBeats(theSequence, guessSequence, bulls, cows);

		std::cout << "Bulls: " << bulls << " " << "Cows: " << cows << "\n\n";

		if (bulls == theSequence.length()) { gameWin = true; }
		lives--;
	}
}

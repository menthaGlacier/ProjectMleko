//-----------------------------------------------------
// Project Mleko
// Created by Andrew Valkonov
//-----------------------------------------------------
// Version: Release 1.0
//-----------------------------------------------------
// https://github.com/menthaGlacier/ProjectMleko
//-----------------------------------------------------

#include <iostream>
#include <string>
#include "functions.h"

int main()
{
	std::string words[110] = { "abandon", "absorb", "draft", "dramatically", "encounter", "educate", "flag", "horse", "dairy", "animal", "stomach",
	"daughter", "hollow", "pork", "herbivore", "gorgeous", "language", "goth", "sheep", "coal", "captain", "noble", "europe", "coconut",
	"shell", "rocket", "sawmill", "grave", "painting", "crew", "palace", "cure", "fallout", "trumpet", "small", "town", "cow", "bull",
	"game", "this", "coast", "lived", "skyhigh", "mother", "more", "entity", "distant", "wood", "land", "mansion", "roaring", "away", "from", "here",
	"josuke", "part", "eight", "best", "manga", "honest", "honey", "charge", "phone", "king", "crimson", "sticky", "fingers", "vento", "aureo",
	"expectation", "dream", "wanted", "help", "door", "stuck", "please", "below", "jingle", "funny", "jigsaw", "asked", "nobody", "picture", "hotline",
	"slow", "abcdef", "qwerty", "love", "delux", "milagro", "boy", "door", "gainer", "fan", "graphics", "stick", "borov", "resort", "bozar",
	"boxes", "continue", "hamon", "towel", "truth", "wolf", "mouth", "will", "never", "reach", "end" };
	uint16_t cows = 0, bulls = 0, lives = 1;
	bool gameWin = false, gameInit = false;
	std::string theWord, guessWord;

	std::cout << "Welcome to the in-console Bulls and Cows game!" << '\n';
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

			if (choice == 1) { gameInit = false; system("cls"); }
			else { std::cout << '\n' << "Bye then!"; exit(0); }
		}

		if (lives == 0)
		{
			uint16_t choice = 0;
			std::cout << "Game over, man, game over." << '\n';
			std::cout << "Do you want to play again? (1 - Yes, 2 - No)" << '\n';
			while (!(choice == 1 || choice == 2))
			{
				std::cout << "Your answer: "; std::cin >> choice;
			}

			if (choice == 1) { gameInit = false; system("cls"); }
			else { std::cout << '\n' << "Bye then!"; exit(0); }
		}

		if (!gameInit)
		{
			bool check = false;
			while (!check)
			{
				theWord = words[randomGenerator(0, (sizeof(words) / sizeof(words[0])) - 1)];
				check = isogramCheck(theWord, theWord.length());
			}

			lives = theWord.length() * 2;
			gameInit = true;
			//std::cout << theWord << " " << theWord.length() << '\n';
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
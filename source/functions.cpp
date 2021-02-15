#include "functions.h"

int randomGenerator(uint16_t min, uint16_t max)
{
	srand(time(NULL));
	return (rand() % (max - min + 1)) + min;
}

bool isogramCheck(std::string word, uint16_t length)
{
	sort(word.begin(), word.end());

	for (int i = 0; i < length; i++)
	{ if (word[i + 1] == word[i]) { return false; } }
	return true;
}

void findTheBeats(std::string word, std::string guess, uint16_t& bulls, uint16_t& cows)
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
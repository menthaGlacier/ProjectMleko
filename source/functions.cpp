#include "functions.h"

int randomGenerator(uint16_t min, uint16_t max)
{
	srand(time(NULL));
	return (rand() % (max - min + 1)) + min;
}

bool filter(std::string word)
{
	// Length check
	if (word.length() < 4) { return false; }

	// Isogram check
	for (int i = 0; i < word.length(); i++)
	{
		sort(word.begin(), word.end());
		if (word[i + 1] == word[i]) { return false; }
	}

	// Letter check
	for (int i = 0; i < word.length(); i++)
	{
		if (!(word[i] >= 'a' && word[i] <= 'z')) { return false; }
	}

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

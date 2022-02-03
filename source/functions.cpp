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

	// Letter and isogram check
	for (int i = 0; i < word.length(); i++)
	{
		sort(word.begin(), word.end());
		if (!(word[i] >= 'a' && word[i] <= 'z')) { return false; }
		if (word[i + 1] == word[i]) { return false; }
	}

	return true;
}


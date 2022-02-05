#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <algorithm> // For sort() 
#include <string>
#include <time.h>
#include <fstream>

// This function generates the random number in (min, max) range
int randomGenerator(uint16_t min, uint16_t max);

// This function converts all uppercase letters into lowercase
void toLowercase(std::string& word);

// This function filters the words taken from a words.txt file
bool filter(std::string word);

#endif

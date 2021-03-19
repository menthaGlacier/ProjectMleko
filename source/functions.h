#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <algorithm> // For sort() 
#include <math.h>
#include <time.h>
#include <fstream>

int randomGenerator(uint16_t min, uint16_t max);
bool filter(std::string word);
bool isogramCheck(std::string word);
void findTheBeats(std::string word, std::string guess, uint16_t& bulls, uint16_t& сows); // It's actully trying to find bulls and cows

#endif

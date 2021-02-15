#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <math.h>
#include <time.h>
#include <algorithm>  // for sort() 

int randomGenerator(uint16_t min, uint16_t max);
bool isogramCheck(std::string word, uint16_t length);
void findTheBeats(std::string word, std::string guess, uint16_t& bulls, uint16_t& с); // its actully trying to find bulls and cows

#endif

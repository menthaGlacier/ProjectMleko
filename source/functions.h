#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <math.h>
#include <time.h>
#include <algorithm>  // for sort() 

int randomGenerator(uint16_t min, uint16_t max);
bool isogramCheck(std::string word); // now there are no other words than isograms, yet function will remain for debug purposes
void findTheBeats(std::string word, std::string guess, uint16_t& bulls, uint16_t& сows); // its actully trying to find bulls and cows

#endif

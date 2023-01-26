#ifndef INTERFACE_H
#define INTERFACE_H

#include "common.h"
#include "Game.h"

class Interface {
public:
	Interface();
	Interface(const Interface& copy) = delete;

	void displayMenu();
private:
	Game session;
	std::string input;
};

#endif /* INTERFACE_H */

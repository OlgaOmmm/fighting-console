#pragma once
#include <iostream>

#include "Hero.h"

class Game {
public:
	explicit Game();
	void start();
	char getPlayerData(const char& diapason);
	bool isEndOfGame(const std::unique_ptr<Hero>& player1, const std::unique_ptr<Hero>& player2);

	friend std::ostream& operator<<(std::ostream& os, const std::unique_ptr<Hero>& hero);
};

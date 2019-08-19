#pragma once
#include <iostream>
#include "Hero.h"

class Game {
public:
	Game();
	void start();
	char getPlayerData(const char& diapason);
	bool endOfGame(const std::unique_ptr<Hero>& player1, const std::unique_ptr<Hero>& player2);
};

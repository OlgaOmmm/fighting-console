#pragma once
#include <iostream>

#include "Hero.h"

class Game {
public:
	explicit Game();
	void start();

	void playersCreating(std::unique_ptr<Hero>(& player)[2]);
	void playersOutfit(const std::unique_ptr<Hero>(&player)[2]) const;
	void autoFight(const std::unique_ptr<Hero>(&player)[2]) const;

	bool isEndOfGame(const std::unique_ptr<Hero>(&player)[2]) const;
	char getPlayerData(const char& diapason) const;
};

#include <iostream>
#include <ostream>
#include <string>
#include <ctime>

#include "Hero.h"
#include "Races.h"
#include "Items.h"
#include "Game.h"

Game::Game() {
	srand(time(NULL));
	std::cout << "About game races: \nHuman race has average stats between Elf race and Orc race. \nAlien race has special alien damage but can't avoid or do critical damage. \nGood luck!\n\n";
};

void Game::start() {
	std::unique_ptr<Hero> player[2];
	playersCreating(player);

	playersOutfit(player);

	std::cout << "\n\tPlayer1 said:\n" << player[0];
	std::cout << "\n\tPlayer2 said:\n" << player[1];

	std::cout << "\n\tFIGHT!!!\n\n";
	autoFight(player);
}

void Game::playersCreating(std::unique_ptr<Hero>(&player)[2]) {
	for (int i = 0; i < 2; ++i) {
		std::cout << "\t\tCreating player" << i + 1 << "\n";
		std::cout << "\tChoose race: 1-Human, 2-Orc, 3-Elf, 4-Alien\t";
		switch (getPlayerData('4')) {
		case '1': player[i] = std::make_unique<Human>(); break;
		case '2': player[i] = std::make_unique<Orc>(); break;
		case '3': player[i] = std::make_unique<Elf>(); break;
		case '4': player[i] = std::make_unique<Alien>(); break;
		default: break;
		}
		std::cout << "\tPlease, enter name of your hero\t\t";
		std::cin >> player[i]->Name;
	}
}

void Game::playersOutfit(const std::unique_ptr<Hero>(&player)[2]) const {
	for (int i = 0; i < 2; ++i) {
		std::cout << "\t\tPlease, choose outfit for player" << i + 1 << "\n";

		std::unique_ptr<Weapon> playerWeapon[2];
		std::cout << "\tWeapon in right hand: 1-Sword, 2-Katana, 3-Knife, 4-None\t";
		switch (getPlayerData('4')) {
		case '1': playerWeapon[i] = std::make_unique<Sword>(player[i]); break;
		case '2': playerWeapon[i] = std::make_unique<Katana>(player[i]); break;
		case '3': playerWeapon[i] = std::make_unique<Knife>(player[i]); break;
		case '4': playerWeapon[i] = std::make_unique<NoWeapon>(player[i]); break;
		}

		std::unique_ptr<Weapon2> playerWeapon2[2];
		std::cout << "\tIn left hand: 1-Shield, 2-Sword, 3-Knife, 4-None\t";
		switch (getPlayerData('4')) {
		case '1': playerWeapon2[i] = std::make_unique<Shield>(player[i]); break;
		case '2': playerWeapon2[i] = std::make_unique<Sword2>(player[i]); break;
		case '3': playerWeapon2[i] = std::make_unique<Knife2>(player[i]); break;
		case '4': playerWeapon2[i] = std::make_unique<NoWeapon2>(player[i]); break;
		}

		std::unique_ptr<Armor> playerArmor[2];
		std::cout << "\tArmor: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
		switch (getPlayerData('4')) {
		case '1': playerArmor[i] = std::make_unique<SteelArmor>(player[i]); break;
		case '2': playerArmor[i] = std::make_unique<PlateArmor>(player[i]); break;
		case '3': playerArmor[i] = std::make_unique<LeatherArmor>(player[i]); break;
		case '4': playerArmor[i] = std::make_unique<NoArmor>(player[i]); break;
		}

		std::unique_ptr<Helmet> playerHelmet[2];
		std::cout << "\tHelmet: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
		switch (getPlayerData('4')) {
		case '1': playerHelmet[i] = std::make_unique<SteelHelmet>(player[i]); break;
		case '2': playerHelmet[i] = std::make_unique<PlateHelmet>(player[i]); break;
		case '3': playerHelmet[i] = std::make_unique<LeatherHelmet>(player[i]); break;
		case '4': playerHelmet[i] = std::make_unique<NoHelmet>(player[i]); break;
		}

		std::unique_ptr<Gloves> playerGloves[2];
		std::cout << "\tGloves: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
		switch (getPlayerData('4')) {
		case '1': playerGloves[i] = std::make_unique<SteelGloves>(player[i]); break;
		case '2': playerGloves[i] = std::make_unique<PlateGloves>(player[i]); break;
		case '3': playerGloves[i] = std::make_unique<LeatherGloves>(player[i]); break;
		case '4': playerGloves[i] = std::make_unique<NoGloves>(player[i]); break;
		}

		std::unique_ptr<Greaves> playerGreaves[2];
		std::cout << "\tGreaves: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
		switch (getPlayerData('4')) {
		case '1': playerGreaves[i] = std::make_unique<SteelGreaves>(player[i]); break;
		case '2': playerGreaves[i] = std::make_unique<PlateGreaves>(player[i]); break;
		case '3': playerGreaves[i] = std::make_unique<LeatherGreaves>(player[i]); break;
		case '4': playerGreaves[i] = std::make_unique<NoGreaves>(player[i]); break;
		}

		std::unique_ptr<Ring> playerRing[2];
		std::cout << "\tRing: 1-Emerald, 2-Ruby, 3-Saphire, 4-None\t";
		switch (getPlayerData('4')) {
		case '1': playerRing[i] = std::make_unique<EmeraldRing>(player[i]); break;
		case '2': playerRing[i] = std::make_unique<RubyRing>(player[i]); break;
		case '3': playerRing[i] = std::make_unique<SaphireRing>(player[i]); break;
		case '4': playerRing[i] = std::make_unique<NoRing>(player[i]); break;
		}
	}
}

void Game::autoFight(const std::unique_ptr<Hero>(&player)[2]) const {
	while (true) {
		if (player[0]->Spd >= player[1]->Spd) {
			if (!isEndOfGame(player[0], player[1]))
				player[0]->attack(player[0], player[1]);
			else
				break;
			if (!isEndOfGame(player[0], player[1]))
				player[1]->attack(player[1], player[0]);
			else
				break;
		}
		else
		{
			if (!isEndOfGame(player[0], player[1]))
				player[0]->attack(player[1], player[0]);
			else
				break;
			if (!isEndOfGame(player[0], player[1]))
				player[1]->attack(player[0], player[1]);
			else
				break;
		}
	}
}

bool Game::isEndOfGame(const std::unique_ptr<Hero>& player1, const std::unique_ptr<Hero>& player2) const {
	if (player1->HP == 0) {
		std::cout << player2->Name << " win!!!\n\nGAME OVER\n";
		return true;
	}
	else if (player2->HP == 0) {
		std::cout << player1->Name << " win!!!\n\nGAME OVER\n";
		return true;
	}
	else
		return false;
}

char Game::getPlayerData(const char& diapason) const {
	std::string playerData;
	char verifiedData;
	while (true) {
		std::getline(std::cin, playerData);
		if (playerData.length() == 1 && playerData[0] <= diapason && playerData[0] >= '1')
			return verifiedData = playerData[0];
	}
}

#include <iostream>
#include <ostream>
#include <string>
#include <ctime>

#include "Hero.h"
#include "Game.h"

// ------------------------ RACE CLASSES ------------------------

// class Hero in file "Hero.h"

class Human : public Hero {
public:
	Human() {
		currentRace = PlayerRace::Human;
		HP = 1000;
		Str = 100;
		Def = 100;
		Mnt = 100;
		Lck = 100;
		Spd = 100;
	}
	void attack(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) override {
		double damage;

		if (!ableToAvoidAttack(currentPlayer, attackedPlayer)) {
			damage = getDamage(currentPlayer, attackedPlayer);
			setDamage(attackedPlayer, damage);
			printDamage(currentPlayer, attackedPlayer, damage);
		}
		printHP(currentPlayer, attackedPlayer);
	}
};

class Orc : public Hero {
public:
	Orc() {
		currentRace = PlayerRace::Orc;
		HP = 1000;
		Str = 125;
		Def = 125;
		Mnt = 75;
		Lck = 75;
		Spd = 75;
	}
	void attack(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) override {
		double damage;

		if (!ableToAvoidAttack(currentPlayer, attackedPlayer)) {
			damage = getDamage(currentPlayer, attackedPlayer);
			setDamage(attackedPlayer, damage);
			printDamage(currentPlayer, attackedPlayer, damage);
		}
		printHP(currentPlayer, attackedPlayer);
	}
};

class Elf : public Hero {
public:
	Elf() {
		currentRace = PlayerRace::Elf;
		HP = 1000;
		Str = 125;
		Def = 75;
		Mnt = 125;
		Lck = 125;
		Spd = 125;
	}
	void attack(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) override {
		double damage;

		if (!ableToAvoidAttack(currentPlayer, attackedPlayer)) {
			damage = getDamage(currentPlayer, attackedPlayer);
			setDamage(attackedPlayer, damage);
			printDamage(currentPlayer, attackedPlayer, damage);
		}
		printHP(currentPlayer, attackedPlayer);
	}
};

class Alien : public Hero {
public:
	Alien() {
		currentRace = PlayerRace::Alien;
		HP = 1000;
		Str = 10;
		Def = 200;
		Mnt = 200;
		Lck = 10;
		Spd = 100;
	}
	void attack(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) override {
		double damage;

		if (countUltimateAttack() > 0)
			damage = getDamage(currentPlayer, attackedPlayer);
		else
			damage = ultimateAttack(attackedPlayer);

		setDamage(attackedPlayer, damage);

		printDamage(currentPlayer, attackedPlayer, damage);
		printHP(currentPlayer, attackedPlayer);
	}

	int countUltimateAttack() {
		static int countAttack = 6; //instead of critical damage Aliens have special alien damage
		--countAttack;
		std::cout << "\tWarning! Powerful alien damage after " << countAttack << " turn(s)!\n\n";
		return countAttack;
	}
	double ultimateAttack(const std::unique_ptr<Hero>& player2) {
		std::cout << "\tDANGER!!! Powerful alien damage right now!!!\n\n";
		return player2->HP;
	}
};

// ------------------------ ITEM CLASSES ------------------------

// ------------------------ RIGHT HAND (WEAPON) ------------------------
class Weapon {
public:
	std::string Name;
};
class Sword : public Weapon {
public:
	Sword(const std::unique_ptr<Hero>& player1) {
		Name = "sword";
		player1->Str += 100;
	}
};
class Katana : public Weapon {
public:
	Katana(const std::unique_ptr<Hero>& player1) {
		Name = "katana";
		player1->Str += 75;
		player1->Spd += 25;
	}
};
class Knife : public Weapon {
public:
	Knife(const std::unique_ptr<Hero>& player1) {
		Name = "knife";
		player1->Str += 50;
		player1->Spd += 50;
	}
};
class NoWeapon : public Weapon {
public:
	NoWeapon(const std::unique_ptr<Hero>& player1) {
		Name = "no weapon";
		player1->Str += 25;
		player1->Spd += 75;
	}
};
// ------------------------ LEFT HAND (SHIELD OR WEAPON) ------------------------
class Weapon2 {
public:
	std::string Name;
};
class Shield : public Weapon2 {
public:
	Shield(const std::unique_ptr<Hero>& player1) {
		Name = "shield";
		player1->Def += 500;
	}
};
class Sword2 : public Weapon2 {
public:
	Sword2(const std::unique_ptr<Hero>& player1) {
		Name = "sword";
		player1->Str += 100;
	}
};
class Knife2 : public Weapon2 {
public:
	Knife2(const std::unique_ptr<Hero>& player1) {
		Name = "knife";
		player1->Str += 50;
		player1->Spd += 50;
	}
};
class NoWeapon2 : public Weapon2 {
public:
	NoWeapon2(const std::unique_ptr<Hero>& player1) {
		Name = "no item";
		player1->Str += 25;
		player1->Spd += 75;
	}
};
// ------------------------ ARMOR ------------------------
class Armor {
public:
	std::string Name;
};
class SteelArmor : public Armor {
public:
	SteelArmor(const std::unique_ptr<Hero>& player1) {
		Name = "steel armor";
		player1->Def += 1500;
	}
};
class PlateArmor : public Armor {
public:
	PlateArmor(const std::unique_ptr<Hero>& player1) {
		Name = "plate armor";
		player1->Def += 1000;
	}
};
class LeatherArmor : public Armor {
public:
	LeatherArmor(const std::unique_ptr<Hero>& player1) {
		Name = "leather armor";
		player1->Def += 750;
		player1->Spd += 250;
	}
};
class NoArmor : public Armor {
public:
	NoArmor(const std::unique_ptr<Hero>& player1) {
		Name = "no armor";
		player1->Def += 250;
		player1->Spd += 750;
	}
};

// ------------------------ HELMET ------------------------
class Helmet {
public:
	std::string Name;
};
class SteelHelmet : public Helmet {
public:
	SteelHelmet(const std::unique_ptr<Hero>& player1) {
		Name = "steel helmet";
		player1->Def += 150;
	}
};
class PlateHelmet : public Helmet {
public:
	PlateHelmet(const std::unique_ptr<Hero>& player1) {
		Name = "plate helmet";
		player1->Def += 100;
	}
};
class LeatherHelmet : public Helmet {
public:
	LeatherHelmet(const std::unique_ptr<Hero>& player1) {
		Name = "leather helmet";
		player1->Def += 75;
		player1->Spd += 25;
	}
};
class NoHelmet : public Helmet {
public:
	NoHelmet(const std::unique_ptr<Hero>& player1) {
		Name = "no helmet";
		player1->Def += 25;
		player1->Spd += 75;
	}
};
// ------------------------ GLOVES ------------------------
class Gloves {
public:
	std::string Name;
};
class SteelGloves : public Gloves {
public:
	SteelGloves(const std::unique_ptr<Hero>& player1) {
		Name = "steel gloves";
		player1->Def += 150;
	}
};
class PlateGloves : public Gloves {
public:
	PlateGloves(const std::unique_ptr<Hero>& player1) {
		Name = "plate gloves";
		player1->Def += 100;
	}
};
class LeatherGloves : public Gloves {
public:
	LeatherGloves(const std::unique_ptr<Hero>& player1) {
		Name = "leather gloves";
		player1->Def += 75;
		player1->Spd += 25;
	}
};
class NoGloves : public Gloves {
public:
	NoGloves(const std::unique_ptr<Hero>& player1) {
		Name = "no gloves";
		player1->Def += 25;
		player1->Spd += 75;
	}
};
// ------------------------ GREAVES ------------------------
class Greaves {
public:
	std::string Name;
};
class SteelGreaves : public Greaves {
public:
	SteelGreaves(const std::unique_ptr<Hero>& player1) {
		Name = "steel greaves";
		player1->Def += 150;
	}
};
class PlateGreaves : public Greaves {
public:
	PlateGreaves(const std::unique_ptr<Hero>& player1) {
		Name = "plate greaves";
		player1->Def += 100;
	}
};
class LeatherGreaves : public Greaves {
public:
	LeatherGreaves(const std::unique_ptr<Hero>& player1) {
		Name = "leather greaves";
		player1->Def += 75;
		player1->Spd += 25;
	}
};
class NoGreaves : public Greaves {
public:
	NoGreaves(const std::unique_ptr<Hero>& player1) {
		Name = "no greaves";
		player1->Def += 25;
		player1->Spd += 75;
	}
};
// ------------------------ RING ------------------------
class Ring {
public:
	std::string Name;
};
class EmeraldRing : public Ring {
public:
	EmeraldRing(const std::unique_ptr<Hero>& player1) {
		Name = "emerald ring";
		player1->Lck += 100;
	}
};
class RubyRing : public Ring {
public:
	RubyRing(const std::unique_ptr<Hero>& player1) {
		Name = "ruby ring";
		player1->Str += 100;
	}
};
class SaphireRing : public Ring {
public:
	SaphireRing(const std::unique_ptr<Hero>& player1) {
		Name = "saphire ring";
		player1->Mnt += 100;
	}
};
class NoRing : public Ring {
public:
	NoRing(const std::unique_ptr<Hero>& player1) {
		Name = "no ring";
		player1->Spd += 100;
	}
};

//game cycle
Game::Game() {
	srand(time(NULL));
	std::cout << "About game races: \nHuman race has average stats between Elf race and Orc race. \nAlien race has special alien damage but can't avoid or do critical damage. \nGood luck!\n\n";
};
void Game::start() {
	// ------------------------ CREATING ------------------------

	//CREATING PLAYER 1 and PLAYER2
	std::unique_ptr<Hero> player[2];
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

	//------------------------TUNING PLAYER1 ------------------------
	for (int i = 0; i < 2; ++i) {
		std::cout << "\t\tPlease, choose clothes for player" << i + 1 << "\n";

		//right hand (weapon)
		std::unique_ptr<Weapon> playerWeapon[2];
		std::cout << "\tWeapon in right hand: 1-Sword, 2-Katana, 3-Knife, 4-None\t";
		switch (getPlayerData('4'))
		{
		case '1': playerWeapon[i] = std::make_unique<Sword>(player[i]); break;
		case '2': playerWeapon[i] = std::make_unique<Katana>(player[i]); break;
		case '3': playerWeapon[i] = std::make_unique<Knife>(player[i]); break;
		case '4': playerWeapon[i] = std::make_unique<NoWeapon>(player[i]); break;
		}

		//left hand (shield or weapon)
		std::unique_ptr<Weapon2> playerWeapon2[2];
		std::cout << "\tIn left hand: 1-Shield, 2-Sword, 3-Knife, 4-None\t";
		switch (getPlayerData('4'))
		{
		case '1': playerWeapon2[i] = std::make_unique<Shield>(player[i]); break;
		case '2': playerWeapon2[i] = std::make_unique<Sword2>(player[i]); break;
		case '3': playerWeapon2[i] = std::make_unique<Knife2>(player[i]); break;
		case '4': playerWeapon2[i] = std::make_unique<NoWeapon2>(player[i]); break;
		}

		//armor
		std::unique_ptr<Armor> playerArmor[2];
		std::cout << "\tArmor: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
		switch (getPlayerData('4'))
		{
		case '1': playerArmor[i] = std::make_unique<SteelArmor>(player[i]); break;
		case '2': playerArmor[i] = std::make_unique<PlateArmor>(player[i]); break;
		case '3': playerArmor[i] = std::make_unique<LeatherArmor>(player[i]); break;
		case '4': playerArmor[i] = std::make_unique<NoArmor>(player[i]); break;
		}

		//helmet
		std::unique_ptr<Helmet> playerHelmet[2];
		std::cout << "\tHelmet: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
		switch (getPlayerData('4'))
		{
		case '1': playerHelmet[i] = std::make_unique<SteelHelmet>(player[i]); break;
		case '2': playerHelmet[i] = std::make_unique<PlateHelmet>(player[i]); break;
		case '3': playerHelmet[i] = std::make_unique<LeatherHelmet>(player[i]); break;
		case '4': playerHelmet[i] = std::make_unique<NoHelmet>(player[i]); break;
		}

		//gloves
		std::unique_ptr<Gloves> playerGloves[2];
		std::cout << "\tGloves: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
		switch (getPlayerData('4'))
		{
		case '1': playerGloves[i] = std::make_unique<SteelGloves>(player[i]); break;
		case '2': playerGloves[i] = std::make_unique<PlateGloves>(player[i]); break;
		case '3': playerGloves[i] = std::make_unique<LeatherGloves>(player[i]); break;
		case '4': playerGloves[i] = std::make_unique<NoGloves>(player[i]); break;
		}

		//greaves
		std::unique_ptr<Greaves> playerGreaves[2];
		std::cout << "\tGreaves: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
		switch (getPlayerData('4'))
		{
		case '1': playerGreaves[i] = std::make_unique<SteelGreaves>(player[i]); break;
		case '2': playerGreaves[i] = std::make_unique<PlateGreaves>(player[i]); break;
		case '3': playerGreaves[i] = std::make_unique<LeatherGreaves>(player[i]); break;
		case '4': playerGreaves[i] = std::make_unique<NoGreaves>(player[i]); break;
		}

		//ring
		std::unique_ptr<Ring> playerRing[2];
		std::cout << "\tRing: 1-Emerald, 2-Ruby, 3-Saphire, 4-None\t";
		switch (getPlayerData('4'))
		{
		case '1': playerRing[i] = std::make_unique<EmeraldRing>(player[i]); break;
		case '2': playerRing[i] = std::make_unique<RubyRing>(player[i]); break;
		case '3': playerRing[i] = std::make_unique<SaphireRing>(player[i]); break;
		case '4': playerRing[i] = std::make_unique<NoRing>(player[i]); break;
		}
	}

	std::cout << "\n\tPlayer1 said:\n" << player[0];
	std::cout << "\n\tPlayer2 said:\n" << player[1];

	//------------------------ AUTO FIGHT ------------------------

	std::cout << "\n\tFIGHT!!!\n\n";

	while (!isEndOfGame(player[0], player[1])) {
		if (player[0]->Spd >= player[1]->Spd) {
			player[0]->attack(player[0], player[1]);
			if (!isEndOfGame(player[0], player[1]))
				player[1]->attack(player[1], player[0]);
			else
				break;
		}
		else
		{
			player[1]->attack(player[1], player[0]);
			if (!isEndOfGame(player[0], player[1]))
				player[0]->attack(player[0], player[1]);
			else
				break;
		}
	}
}

bool Game::isEndOfGame(const std::unique_ptr<Hero>& player1, const std::unique_ptr<Hero>& player2) {
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

char Game::getPlayerData(const char& diapason) {
	std::string playerData;
	char verifiedData;
	while (true) {
		std::getline(std::cin, playerData);
		if (playerData.length() == 1 && playerData[0] <= diapason && playerData[0] >= '1')
			return verifiedData = playerData[0];
	}
}

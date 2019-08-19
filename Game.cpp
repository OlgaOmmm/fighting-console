#include <iostream>
#include <ostream>
#include <string>

#include "Hero.h"
#include "Game.h"

// ------------------------ RACE CLASSES ------------------------

// class Hero in file "Hero.h"

class Human : public Hero {
public:
	Human() { Race = "Human"; 
		HP = 1000;
		STR = 100;
		DEF = 100;
		INT = 100;
		LCK = 100;
		SPD = 100;
	}
	void attack(const std::unique_ptr<Hero>& player1, const std::unique_ptr<Hero>& player2) override {
		double oldHP;
		double damage;
		
		oldHP = player2->HP;

		if(player1->STR > player2->DEF)
			damage = (player1->STR * 0.5) * ((player1->STR - player2->DEF) * 0.0005);
		else
			damage = (player1->STR * 0.5) / ((player2->DEF - player1->STR) * 0.0005);

		player2->HP -= damage;

		if (player2->HP < 0)
			player2->HP = 0;

		std::cout << "Player " << player1->Name << " hit " << player2->Name << " with " << oldHP - player2->HP << " damage.\n";
		std::cout << player1->Name << "'s HP is " << player1->HP << " now. " << player2->Name << "'s HP is " << player2->HP << " now.\n\n";
	}
};
class Orc : public Hero {
public:
	Orc() { Race = "Orc"; 
		HP = 1200;
		STR = 125;
		DEF = 125;
		INT = 75;
		LCK = 75;
		SPD = 75;
	}
	void attack(const std::unique_ptr<Hero>& player1, const std::unique_ptr<Hero>& player2) override {
		double oldHP;
		double damage;

		oldHP = player2->HP;

		if (player1->STR > player2->DEF)
			damage = (player1->STR * 0.5) * ((player1->STR - player2->DEF) * 0.0005);
		else
			damage = (player1->STR * 0.5) / ((player2->DEF - player1->STR) * 0.0005);

		player2->HP -= damage;

		if (player2->HP < 0)
			player2->HP = 0;

		std::cout << "Player " << player1->Name << " hit " << player2->Name << " with " << oldHP - player2->HP << " damage.\n";
		std::cout << player1->Name << "'s HP is " << player1->HP << " now. " << player2->Name << "'s HP is " << player2->HP << " now.\n\n";
	}
};
class Elf : public Hero {
public:
	Elf() { Race = "Elf"; 
		HP = 800;
		STR = 75;
		DEF = 75;
		INT = 125;
		LCK = 125;
		SPD = 125;
	}
	void attack(const std::unique_ptr<Hero>& player1, const std::unique_ptr<Hero>& player2) override {
		double oldHP;
		double damage;

		oldHP = player2->HP;

		if (player1->STR > player2->DEF)
			damage = (player1->STR * 0.5) * ((player1->STR - player2->DEF) * 0.0005);
		else
			damage = (player1->STR * 0.5) / ((player2->DEF - player1->STR) * 0.0005);

		player2->HP -= damage;

		if (player2->HP < 0)
			player2->HP = 0;

		std::cout << "Player " << player1->Name << " hit " << player2->Name << " with " << oldHP - player2->HP << " damage.\n";
		std::cout << player1->Name << "'s HP is " << player1->HP << " now. " << player2->Name << "'s HP is " << player2->HP << " now.\n\n";
	}
};
class Alien : public Hero {
public:
	Alien() { Race = "Alien"; 
		HP = 1500;
		STR = 100;
		DEF = 1;
		INT = 200;
		LCK = 200;
		SPD = 1;
	}
	void attack(const std::unique_ptr<Hero>& player1, const std::unique_ptr<Hero>& player2) override {
		double oldHP;
		double damage;

		oldHP = player2->HP;

		if (player1->STR > player2->DEF)
			damage = (player1->STR * 0.5) * ((player1->STR - player2->DEF) * 0.0005);
		else
			damage = (player1->STR * 0.5) / ((player2->DEF - player1->STR) * 0.0005);

		player2->HP -= damage;

		if (player2->HP < 0)
			player2->HP = 0;

		std::cout << "Player " << player1->Name << " hit " << player2->Name << " with " << oldHP - player2->HP << " damage.\n";
		std::cout << player1->Name << "'s HP is " << player1->HP << " now. " << player2->Name << "'s HP is " << player2->HP << " now.\n\n";
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
		player1->STR += 100;
	}
};
class Katana : public Weapon {
public:
	Katana(const std::unique_ptr<Hero>& player1) {
		Name = "katana";
		player1->STR += 75;
		player1->SPD += 25;
	}
};
class Knife : public Weapon {
public:
	Knife(const std::unique_ptr<Hero>& player1) {
		Name = "knife";
		player1->STR += 50;
		player1->SPD += 50;
	}
};
class NoWeapon : public Weapon {
public:
	NoWeapon(const std::unique_ptr<Hero>& player1) {
		Name = "no weapon";
		player1->STR += 25;
		player1->SPD += 75;
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
		player1->DEF += 500;
	}
};
class Sword2 : public Weapon2 {
public:
	Sword2(const std::unique_ptr<Hero>& player1) {
		Name = "sword";
		player1->STR += 100;
	}
};
class Knife2 : public Weapon2 {
public:
	Knife2(const std::unique_ptr<Hero>& player1) {
		Name = "knife";
		player1->STR += 50;
		player1->SPD += 50;
	}
};
class NoWeapon2 : public Weapon2 {
public:
	NoWeapon2(const std::unique_ptr<Hero>& player1) {
		Name = "no item";
		player1->STR += 25;
		player1->SPD += 75;
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
		player1->DEF += 1500;
	}
};
class PlateArmor : public Armor {
public:
	PlateArmor(const std::unique_ptr<Hero>& player1) {
		Name = "plate armor";
		player1->DEF += 1000;
	}
};
class LeatherArmor : public Armor {
public:
	LeatherArmor(const std::unique_ptr<Hero>& player1) {
		Name = "leather armor";
		player1->DEF += 750;
		player1->SPD += 250;
	}
};
class NoArmor : public Armor {
public:
	NoArmor(const std::unique_ptr<Hero>& player1) {
		Name = "no armor";
		player1->DEF += 250;
		player1->SPD += 750;
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
		player1->DEF += 150;
	}
};
class PlateHelmet : public Helmet {
public:
	PlateHelmet(const std::unique_ptr<Hero>& player1) {
		Name = "plate helmet";
		player1->DEF += 100;
	}
};
class LeatherHelmet : public Helmet {
public:
	LeatherHelmet(const std::unique_ptr<Hero>& player1) {
		Name = "leather helmet";
		player1->DEF += 75;
		player1->SPD += 25;
	}
};
class NoHelmet : public Helmet {
public:
	NoHelmet(const std::unique_ptr<Hero>& player1) {
		Name = "no helmet";
		player1->DEF += 25;
		player1->SPD += 75;
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
		player1->DEF += 150;
	}
};
class PlateGloves : public Gloves {
public:
	PlateGloves(const std::unique_ptr<Hero>& player1) {
		Name = "plate gloves";
		player1->DEF += 100;
	}
};
class LeatherGloves : public Gloves {
public:
	LeatherGloves(const std::unique_ptr<Hero>& player1) {
		Name = "leather gloves";
		player1->DEF += 75;
		player1->SPD += 25;
	}
};
class NoGloves : public Gloves {
public:
	NoGloves(const std::unique_ptr<Hero>& player1) {
		Name = "no gloves";
		player1->DEF += 25;
		player1->SPD += 75;
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
		player1->DEF += 150;
	}
};
class PlateGreaves : public Greaves {
public:
	PlateGreaves(const std::unique_ptr<Hero>& player1) {
		Name = "plate greaves";
		player1->DEF += 100;
	}
};
class LeatherGreaves : public Greaves {
public:
	LeatherGreaves(const std::unique_ptr<Hero>& player1) {
		Name = "leather greaves";
		player1->DEF += 75;
		player1->SPD += 25;
	}
};
class NoGreaves : public Greaves {
public:
	NoGreaves(const std::unique_ptr<Hero>& player1) {
		Name = "no greaves";
		player1->DEF += 25;
		player1->SPD += 75;
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
		player1->LCK += 100;
	}
};
class RubyRing : public Ring {
public:
	RubyRing(const std::unique_ptr<Hero>& player1) {
		Name = "ruby ring";
		player1->STR += 100;
	}
};
class SaphireRing : public Ring {
public:
	SaphireRing(const std::unique_ptr<Hero>& player1) {
		Name = "saphire ring";
		player1->INT += 100;
	}
};
class NoRing : public Ring {
public:
	NoRing(const std::unique_ptr<Hero>& player1) {
		Name = "no ring";
		player1->SPD += 50;
	}
};

//game cycle
Game::Game() {};
void Game::start() {
	// ------------------------ CREATING ------------------------

	//CREATING PLAYER 1
	std::unique_ptr<Hero> player1;
	std::cout << "\t\tCreating player1\n";
	std::cout << "\tChoose race: 1-Human, 2-Orc, 3-Elf, 4-Alien\t";
	switch (getPlayerData('4')) {
	case '1': player1 = std::make_unique<Human>(); break;
	case '2': player1 = std::make_unique<Orc>(); break;
	case '3': player1 = std::make_unique<Elf>(); break;
	case '4': player1 = std::make_unique<Alien>(); break;
	default: break;
	}
	std::cout << "\tPlease, enter name of your hero\t\t";
	std::cin >> player1->Name;

	//CREATING PLAYER 2
	std::unique_ptr<Hero> player2;
	std::cout << "\t\tCreating player2\n";
	std::cout << "\tChoose race: 1-Human, 2-Orc, 3-Elf, 4-Alien\t";
	switch (getPlayerData('4')) {
	case '1': player2 = std::make_unique<Human>(); break;
	case '2': player2 = std::make_unique<Orc>(); break;
	case '3': player2 = std::make_unique<Elf>(); break;
	case '4': player2 = std::make_unique<Alien>(); break;
	default: break;
	}
	std::cout << "\tPlease, enter name of your hero\t\t";
	std::cin >> player2->Name;

	//------------------------TUNING PLAYER1 ------------------------
	//right hand (weapon)
	std::unique_ptr<Weapon> player1Weapon;
	std::cout << "\t\tPlease, choose clothes for player1\n";
	std::cout << "\tWeapon in right hand: 1-Sword, 2-Katana, 3-Knife, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player1Weapon = std::make_unique<Sword>(player1); break;
	case '2': player1Weapon = std::make_unique<Katana>(player1); break;
	case '3': player1Weapon = std::make_unique<Knife>(player1); break;
	case '4': player1Weapon = std::make_unique<NoWeapon>(player1); break;
	}

	//left hand (shield or weapon)
	std::unique_ptr<Weapon2> player1Weapon2;
	std::cout << "\tIn left hand: 1-Shield, 2-Sword, 3-Knife, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player1Weapon2 = std::make_unique<Shield>(player1); break;
	case '2': player1Weapon2 = std::make_unique<Sword2>(player1); break;
	case '3': player1Weapon2 = std::make_unique<Knife2>(player1); break;
	case '4': player1Weapon2 = std::make_unique<NoWeapon2>(player1); break;
	}

	//armor
	std::unique_ptr<Armor> player1Armor;
	std::cout << "\tArmor: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player1Armor = std::make_unique<SteelArmor>(player1); break;
	case '2': player1Armor = std::make_unique<PlateArmor>(player1); break;
	case '3': player1Armor = std::make_unique<LeatherArmor>(player1); break;
	case '4': player1Armor = std::make_unique<NoArmor>(player1); break;
	}

	//helmet
	std::unique_ptr<Helmet> player1Helmet;
	std::cout << "\tHelmet: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player1Helmet = std::make_unique<SteelHelmet>(player1); break;
	case '2': player1Helmet = std::make_unique<PlateHelmet>(player1); break;
	case '3': player1Helmet = std::make_unique<LeatherHelmet>(player1); break;
	case '4': player1Helmet = std::make_unique<NoHelmet>(player1); break;
	}

	//gloves
	std::unique_ptr<Gloves> player1Gloves;
	std::cout << "\tGloves: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player1Gloves = std::make_unique<SteelGloves>(player1); break;
	case '2': player1Gloves = std::make_unique<PlateGloves>(player1); break;
	case '3': player1Gloves = std::make_unique<LeatherGloves>(player1); break;
	case '4': player1Gloves = std::make_unique<NoGloves>(player1); break;
	}

	//greaves
	std::unique_ptr<Greaves> player1Greaves;
	std::cout << "\tGreaves: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player1Greaves = std::make_unique<SteelGreaves>(player1); break;
	case '2': player1Greaves = std::make_unique<PlateGreaves>(player1); break;
	case '3': player1Greaves = std::make_unique<LeatherGreaves>(player1); break;
	case '4': player1Greaves = std::make_unique<NoGreaves>(player1); break;
	}

	//ring
	std::unique_ptr<Ring> player1Ring;
	std::cout << "\tRing: 1-Emerald, 2-Ruby, 3-Saphire, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player1Ring = std::make_unique<EmeraldRing>(player1); break;
	case '2': player1Ring = std::make_unique<RubyRing>(player1); break;
	case '3': player1Ring = std::make_unique<SaphireRing>(player1); break;
	case '4': player1Ring = std::make_unique<NoRing>(player1); break;
	}

	//------------------------TUNING PLAYER2 ------------------------
	//right hand (weapon)
	std::unique_ptr<Weapon> player2Weapon;
	std::cout << "\t\tPlease, choose clothes for player2\n";
	std::cout << "\tWeapon in right hand: 1-Sword, 2-Katana, 3-Knife, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player2Weapon = std::make_unique<Sword>(player2); break;
	case '2': player2Weapon = std::make_unique<Katana>(player2); break;
	case '3': player2Weapon = std::make_unique<Knife>(player2); break;
	case '4': player2Weapon = std::make_unique<NoWeapon>(player2); break;
	}

	//left hand (shield or weapon)
	std::unique_ptr<Weapon2> player2Weapon2;
	std::cout << "\tIn left hand: 1-Shield, 2-Sword, 3-Knife, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player2Weapon2 = std::make_unique<Shield>(player2); break;
	case '2': player2Weapon2 = std::make_unique<Sword2>(player2); break;
	case '3': player2Weapon2 = std::make_unique<Knife2>(player2); break;
	case '4': player2Weapon2 = std::make_unique<NoWeapon2>(player2); break;
	}

	//armor
	std::unique_ptr<Armor> player2Armor;
	std::cout << "\tArmor: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player2Armor = std::make_unique<SteelArmor>(player2); break;
	case '2': player2Armor = std::make_unique<PlateArmor>(player2); break;
	case '3': player2Armor = std::make_unique<LeatherArmor>(player2); break;
	case '4': player2Armor = std::make_unique<NoArmor>(player2); break;
	}

	//helmet
	std::unique_ptr<Helmet> player2Helmet;
	std::cout << "\tHelmet: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player2Helmet = std::make_unique<SteelHelmet>(player2); break;
	case '2': player2Helmet = std::make_unique<PlateHelmet>(player2); break;
	case '3': player2Helmet = std::make_unique<LeatherHelmet>(player2); break;
	case '4': player2Helmet = std::make_unique<NoHelmet>(player2); break;
	}

	//gloves
	std::unique_ptr<Gloves> player2Gloves;
	std::cout << "\tGloves: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player2Gloves = std::make_unique<SteelGloves>(player2); break;
	case '2': player2Gloves = std::make_unique<PlateGloves>(player2); break;
	case '3': player2Gloves = std::make_unique<LeatherGloves>(player2); break;
	case '4': player2Gloves = std::make_unique<NoGloves>(player2); break;
	}

	//greaves
	std::unique_ptr<Greaves> player2Greaves;
	std::cout << "\tGreaves: 1-Steel, 2-Plate, 3-Leather, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player2Greaves = std::make_unique<SteelGreaves>(player2); break;
	case '2': player2Greaves = std::make_unique<PlateGreaves>(player2); break;
	case '3': player2Greaves = std::make_unique<LeatherGreaves>(player2); break;
	case '4': player2Greaves = std::make_unique<NoGreaves>(player2); break;
	}

	//ring
	std::unique_ptr<Ring> player2Ring;
	std::cout << "\tRing: 1-Emerald, 2-Ruby, 3-Saphire, 4-None\t";
	switch (getPlayerData('4'))
	{
	case '1': player2Ring = std::make_unique<EmeraldRing>(player2); break;
	case '2': player2Ring = std::make_unique<RubyRing>(player2); break;
	case '3': player2Ring = std::make_unique<SaphireRing>(player2); break;
	case '4': player2Ring = std::make_unique<NoRing>(player2); break;
	}

	std::cout << "\n\tPlayer1 said:\n" << player1;
	std::cout << "\n\tPlayer2 said:\n" << player2;

	//------------------------ AUTO FIGHT ------------------------

	std::cout << "\n\tFIGHT!!!\n\n";

	while (!endOfGame(player1, player2)) {
		player1->attack(player1, player2);
		if (!endOfGame(player1, player2))
			player2->attack(player2, player1);
		else
			break;
	}
}
bool Game::endOfGame(const std::unique_ptr<Hero>& player1, const std::unique_ptr<Hero>& player2) {
	if (player1->HP == 0) {
		std::cout << "\tPlayer2 " << player2->Name << " win!!!\n\nGAME OVER";
		return true;
	}
	else if (player2->HP == 0) {
		std::cout << "\tPlayer1 " << player1->Name << " win!!!\n\nGAME OVER";
		return true;
	}
	else
		return false;
}

char Game::getPlayerData(const char &diapason) {
	std::string playerData;
	char verifiedData;
	while (true) {
		std::getline(std::cin, playerData);
		if (playerData.length() == 1 && playerData[0] <= diapason && playerData[0] >= '1')
			return verifiedData = playerData[0];
	}
}

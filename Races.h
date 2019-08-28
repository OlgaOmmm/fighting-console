#pragma once
#include "Hero.h"

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
		int damage;

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
		int damage;

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
		int damage;

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
		int damage;

		if (isUltimateAttack())
			damage = ultimateAttack(attackedPlayer);
		else
			damage = getDamage(currentPlayer, attackedPlayer);

		setDamage(attackedPlayer, damage);

		printDamage(currentPlayer, attackedPlayer, damage);
		printHP(currentPlayer, attackedPlayer);
	}

	bool isUltimateAttack() {
		static int countAttack = 5; 
		--countAttack;
		if (!countAttack)
			return true; 
		else {
			std::cout << "\tWarning! Powerful alien damage after " << countAttack << " turn(s)!\n\n";
			return false;
		}
	}
	
	double ultimateAttack(const std::unique_ptr<Hero>& player2) {
		std::cout << "\tDANGER!!! Powerful alien damage right now!!!\n\n";
		return player2->HP;
	}
};

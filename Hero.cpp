#include <iostream>
#include <string>

#include "Hero.h"
	
Hero::Hero(){}
Hero::~Hero() {}

void Hero::setDamage(const std::unique_ptr<Hero>& attackedPlayer, const int& damage) {
	attackedPlayer->HP -= damage;
	if (attackedPlayer->HP < 0)
		attackedPlayer->HP = 0;
}

int Hero::getDamage(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) const {
	double damage;
	damage = calcDamage(currentPlayer, attackedPlayer);
	damage = randCriticalDamage(currentPlayer, damage);
	return randomizeDamage(damage);
}


double Hero::calcDamage(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) const {
	if (currentPlayer->Str > attackedPlayer->Def)
		return (currentPlayer->Str * 0.5) * ((currentPlayer->Str - attackedPlayer->Def) * 0.0005) + (currentPlayer->Mnt / 100);
	else if (currentPlayer->Str < attackedPlayer->Def)
		return (currentPlayer->Str * 0.5) / ((currentPlayer->Def - currentPlayer->Str) * 0.0005);
	else
		return (currentPlayer->Str * 0.5);	
}

int Hero::randomizeDamage(const double& damage) const {
	return (int)(damage + (rand() % 20) - 10);
}

double Hero::randCriticalDamage(const std::unique_ptr<Hero>& currentPlayer, const double& damage) const {
	if ((rand() % 4) == 1) {
		switch (currentPlayer->currentRace) {
		case 1: {
			std::cout << "<Critical Human kick! Damage x1.5!>\n";
			return damage * 1.5;
		}
		case 2:
		{
			std::cout << "<Critical Orc kick! Damage x1.25!>\n";
			return damage * 1.25;
		}
		case 3: {
			std::cout << "<Critical Elf kick! Damage x2!>\n";
			return damage * 2;
		}
		default:
			return damage;
		}
	}
	else
		return damage;
}

bool Hero::ableToAvoidAttack(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) const {
	if ((attackedPlayer->Lck > currentPlayer->Lck) && ((rand() % 4) == 1)) {
		std::cout << "<Missed kick!!! " << attackedPlayer->Name << " was able to avoid the attack!!!>\n";
		return true;
	}
	else
		return false;
}

void Hero::printDamage(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer, const int& damage) const {
	std::cout << "<" << currentPlayer->Name << " hit " << attackedPlayer->Name << " with " << damage << " damage.>\n";
}

void Hero::printHP(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) const {
	std::cout << "<" << attackedPlayer->Name << "'s HP is " << attackedPlayer->HP << " now. " << currentPlayer->Name << "'s HP is " << currentPlayer->HP << " now.>\n\n";
}

std::ostream& operator<<(std::ostream& os, const std::unique_ptr<Hero>& hero) {
	os << "\"Hi! I'm a hero. My name is " << hero->Name << ".\n" <<
		"I have high stats: my Strength = " << hero->Str << ", Defence = " << hero->Def << ", Mentality = " << hero->Mnt <<
		", Luck = " << hero->Lck << " and Speed = " << hero->Spd << ". \nAnd I have " << hero->HP << " HealthPoints so I can win!\"\n";
	return os;
}

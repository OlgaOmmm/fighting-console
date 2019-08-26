#pragma once
#include <iostream>
#include <string>

class Hero
{
	public:
		enum PlayerRace { Human = 1, Orc, Elf, Alien } currentRace;
		std::string Name;

		double HP;
		int Str, Def, Mnt, Lck, Spd;

		Hero();
		virtual ~Hero();

		friend std::ostream& operator<<(std::ostream& os, const std::unique_ptr<Hero>& hero);

		bool ableToAvoidAttack(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) const;
		double calcDamage(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) const;
		double randCriticalDamage(const std::unique_ptr<Hero>& currentPlayer, const double& damage) const;
		int randomizeDamage(const double& damage) const;
		int getDamage(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) const;
		void setDamage(const std::unique_ptr<Hero>& attackedPlayer, const int& damage);

		void printDamage(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer, const int& damage) const;
		void printHP(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) const;

		virtual void attack(const std::unique_ptr<Hero>& currentPlayer, const std::unique_ptr<Hero>& attackedPlayer) = 0;
};

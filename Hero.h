#pragma once
#include <iostream>
#include <string>

class Hero
{
	public:
		Hero();
		virtual ~Hero();
	
		std::string Race, Name;
	
		double HP;
		int STR, DEF, INT, LCK, SPD; //статы в зависимости от расы, прописаны в классах-наследниках
	
		friend std::ostream& operator<<(std::ostream& os, const std::unique_ptr<Hero>& hero);
	
		virtual void attack(const std::unique_ptr<Hero>& player1, const std::unique_ptr<Hero>& player2) = 0;
};

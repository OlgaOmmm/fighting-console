#include <iostream>
#include <string>

#include "Hero.h"

Hero::Hero() {};
Hero::~Hero() {};
	
std::ostream& operator<<(std::ostream& os, const std::unique_ptr<Hero>& hero) {
	os << "\"Hi! I'm a hero. My name is " << hero->Name << " and my race is " << hero->Race << ".\n" <<
		"I have high stats: my Strength = " << hero->STR << ", Defence = " << hero->DEF << ", Intelligence = " << hero->INT <<
		", Luck = " << hero->LCK << " and Speed = " << hero->SPD << ". \nAnd I have " << hero->HP << " HealthPoints so I can win!\"\n";
	return os;
}

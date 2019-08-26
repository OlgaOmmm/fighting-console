#pragma once
#include "Hero.h"

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

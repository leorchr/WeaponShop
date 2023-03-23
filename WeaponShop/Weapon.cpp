#include "Weapon.h"
#include <iostream>
using namespace std;

Weapon::Weapon(){
	mName = "Default";
	mDescription = "Description manquante";
	mType = WeaponType::Default;
	mWeight = 1;
	mDamages = 0;
	mCost = 1;
	mDurability = 1;
}

Weapon::Weapon(string name, string description, WeaponType type, int weight, int damages, int cost, float durability) {
	mName = name;
	mDescription = description;
	mType = type;
	mWeight = weight;
	mDamages = damages;
	mCost = cost;
	mDurability = durability;
}

Weapon::Weapon(string name, WeaponType type, int weight, int damages, int cost) {
	mName = name;
	mDescription = "Description manquante";
	mType = type;
	mWeight = weight;
	mDamages = damages;
	mCost = cost;
	mDurability = 1;
}

Weapon::~Weapon() {}
#include "Weapon.h"
#include <iostream>
#include <cmath>
using namespace std;

Weapon::Weapon(){
	mName = "Default";
	mDescription = "Description manquante";
	mType = WeaponType::Default;
	mWeight = 1;
	mDamages = 0;
	mCost = 1;
	mStartCost = mCost;
	mDurability = 1;
}

Weapon::Weapon(string name, string description, WeaponType type, int weight, int damages, int cost, float durability) {
	mName = name;
	mDescription = description;
	mType = type;
	mWeight = weight;
	mDamages = damages;
	mCost = cost;
	mStartCost = cost;
	mDurability = durability;
}

Weapon::Weapon(string name, WeaponType type, int weight, int damages, int cost) {
	mName = name;
	mDescription = "Description manquante";
	mType = type;
	mWeight = weight;
	mDamages = damages;
	mCost = cost;
	mStartCost = cost;
	mDurability = 1;
}

Weapon::~Weapon() {}

string Weapon::WeaponToStr(WeaponType weapon) {
	switch (weapon)
	{
		case WeaponType::Default:   return "Default";
		case WeaponType::Bow:   return "Bow";
		case WeaponType::Dagger:   return "Dagger";
		case WeaponType::Staff:   return "Staff";
		case WeaponType::Sword:   return "Sword";
	}
}

string Weapon::GetWeaponName() {
	return(mName);
}

WeaponType Weapon::GetWeaponType() {
	return(mType);
}

int Weapon::GetWeaponWeight() {
	return(mWeight);
}

int Weapon::GetWeaponDamages() {
	return(mDamages);
}

int Weapon::GetWeaponCost() {
	return(mCost);
}

float Weapon::GetWeaponDurability() {
	return(mDurability);
}

void Weapon::SetDurability(float durability) {
	mDurability = durability;
}

void Weapon::SetCost() {
	mCost = round((mStartCost * mDurability));
}
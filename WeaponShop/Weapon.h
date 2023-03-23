#include <string>
#pragma once
using namespace std;

enum class WeaponType
{
	Default,
	Bow,
	Dagger,
	Staff,
	Sword
};


class Weapon
{
private:
	std::string mName;
	std::string mDescription;
	WeaponType mType;
	int mWeight;
	int mDamages;
	int mCost;
	float mDurability;

public:
	Weapon();
	Weapon(string name, string description, WeaponType type, int weight, int damages, int cost, float durability);
	Weapon(string name, WeaponType type, int weight, int damages, int cost);
	~Weapon();
};


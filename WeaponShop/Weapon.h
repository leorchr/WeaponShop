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
	int mStartCost;
	float mDurability;

public:
	Weapon();
	Weapon(string name, string description, WeaponType type, int weight, int damages, int cost, float durability);
	Weapon(string name, WeaponType type, int weight, int damages, int cost);
	~Weapon();

	string WeaponToStr(WeaponType weapon);
	string GetWeaponName();
	WeaponType GetWeaponType();
	int GetWeaponWeight();
	int GetWeaponDamages();
	int GetWeaponCost();
	float GetWeaponDurability();
	void SetDurability(float durability);
	void SetCost();
};


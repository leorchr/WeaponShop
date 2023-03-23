#include <string>
#include "Weapon.h"
#pragma once
using namespace std;

enum class Race
{
	Default,
	Elf,
	Orc,
	Gobelin,
	Human,
	Dwarf
};

enum class Job
{
	Default,
	Archer,
	Warrior,
	Priest,
	Paladin
};

class Character
{
private:
	std::string mFirstName;
	std::string mLastName;
	std::string mCatchPhrase;
	int mMoney;
	int mLifePoints;
	Weapon mWeapon;
	Race mRace;
	Job mJob;

public:
	Character();
	Character(string firstName,string lastName, string catchPhrase, int money, int lifePoints, Weapon weapon, Race race, Job job);
	~Character();

	string Introduce();
	/*void Buy();
	void Sell();
	void Attack();
	void Loot();*/
};
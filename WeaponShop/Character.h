#include <string>
#include "Weapon.h"
#include "Merchant.h"
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
	Weapon mWeapons[3];
	Race mRace;
	Job mJob;

public:
	Character();
	Character(string firstName,string lastName, string catchPhrase, int money, int lifePoints, Weapon weapons[3], Race race, Job job);
	~Character();

	string JobToStr(Job job);
	string RaceToStr(Race race);
	string GetName();
	int GetMoney();
	Weapon GetWeapon();
	int GetPV();
	void SetPV(int pv);
	void Introduce();
	void AddToInventory(Weapon weapon);
	void ShowInventory();
	bool IsInventoryFull();
	int InventorySize();
	void RemoveFromInventory(int number);
	void BuyWeapon(Merchant merchant, int number);
	void SellWeapon(Merchant merchant, int number);
	void Attack(Character& character, int number);
};
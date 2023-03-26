#include <string>
#include "Weapon.h"
#pragma once
using namespace std;

class Merchant
{
private:
	std::string mName;
	std::string mShopName;
	std::string mDescription;
	std::string mCatchphrase;
	int mMoney;
	Weapon mWeapons[4];

public:
	Merchant();
	Merchant(string name, string shopName, string description, string catchPhrase, int money, Weapon weapons[4]);
	Merchant(string name, string shopName, int money, Weapon weapons[]);
	~Merchant();
	
	void Introduce();
	Weapon GetWeapon(int number);
	int GetMoney();
	void SetMoney(int money);
};


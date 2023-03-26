#include "Merchant.h"
#include "Weapon.h"
#include <iostream>
using namespace std;

Merchant::Merchant() {
	mName = "Undefined";
	mShopName = "Undefined";
	mDescription = "Undefined";
	mCatchphrase = "Undefined";
	mMoney = 0;
	for (int i = 0; i < 4; i++) {
		mWeapons[i] = Weapon();
	}
}


Merchant::Merchant(string name, string shopName, string description, string catchPhrase, int money, Weapon weapons[4]) {
	mName = name;
	mShopName = shopName;
	mDescription = description;
	mCatchphrase = catchPhrase;
	mMoney = money;
	for (int i = 0; i < 4; i++) {
		mWeapons[i] = weapons[i];
	}
}

Merchant::Merchant(string name, string shopName, int money, Weapon weapons[]) {
	mName = name;
	mShopName = shopName;
	mDescription = "Undefined";
	mCatchphrase = "Undefined";
	mMoney = money;
	for (int i = 0; i < 4; i++) {
		mWeapons[i] = weapons[i];
	}
}

Merchant::~Merchant() {}

void Merchant::Introduce() {
	cout << endl;
	cout << "Bonjour, je m'appelle " << mName << endl;
	cout << "Ma boutique s'appelle " << mShopName << endl;
	cout << mDescription << endl;
	cout << mCatchphrase << endl << endl;
	cout << "Voici la liste de mes armes :" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "- Arme " << i + 1 << " : " << mWeapons[i].WeaponToStr(mWeapons[i].GetWeaponType())
			<< " | Poids : " << mWeapons[i].GetWeaponWeight()
			<< " | Degats : " << mWeapons[i].GetWeaponDamages()
			<< " | Cout : " << mWeapons[i].GetWeaponCost()
			<< " | Durabilite : " << mWeapons[i].GetWeaponDurability() << endl;
	}
	cout << endl;
	cout << mName << " possede " << mMoney << " rubis" << endl << endl;
}

Weapon Merchant::GetWeapon(int number) {
	return(mWeapons[number]);
}

int Merchant::GetMoney() {
	return(mMoney);
}

void Merchant::SetMoney(int money) {
	mMoney = money;
}
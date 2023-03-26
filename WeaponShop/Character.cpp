#include "Character.h"
#include <iostream>
using namespace std;


Character::Character() {
	mFirstName = "Undefined";
	mLastName = "Undefined";
	mCatchPhrase = "Undefined";
	mMoney = 0;
	mLifePoints = 0;
	for (int i = 0; i < 3; i++)
	{
		mWeapons[i] = Weapon();
	}
	mRace = Race::Default;
	mJob = Job::Default;
}


Character::Character(string firstName, string lastName, string catchPhrase, int money, int lifePoints, Weapon weapons[3], Race race, Job job) {
	mFirstName = firstName;
	mLastName = lastName;
	mCatchPhrase = catchPhrase;
	mMoney = money;
	mLifePoints = lifePoints;
	for (int i = 0; i < 3; i++)
	{
		mWeapons[i] = weapons[i];
	}
	mRace = race;
	mJob = job;
}

Character::~Character(){}


string Character::JobToStr(Job job) {
	switch (job)
	{
		case Job::Default:   return "Default";
		case Job::Archer:   return "Archer";
		case Job::Warrior:   return "Warrior";
		case Job::Priest:   return "Priest";
		case Job::Paladin:   return "Paladin";
	}
}

string Character::RaceToStr(Race race) {
	switch (race)
	{
	case Race::Default:   return "Default";
	case Race::Elf:   return "Elf";
	case Race::Orc:   return "Orc";
	case Race::Gobelin:   return "Gobelin";
	case Race::Human:   return "Human";
	case Race::Dwarf:   return "Dwarf";
	}
}

string Character::GetName() {
	return mFirstName + " " + mLastName;
}

int Character::GetMoney() {
	return mMoney;
}

Weapon Character::GetWeapon() {
	return mWeapons[0];
}

int Character::GetPV() {
	return mLifePoints;
}

void Character::SetPV(int pv) {
	mLifePoints = pv;
}

void Character::Introduce() {
	cout << endl;
	cout << "Bonjour, je m'appelle " << mFirstName << " " << mLastName << endl;
	cout << mCatchPhrase << endl;
	cout << "Argent : " << mMoney << " rubis" << endl;
	cout << "Vie : " << mLifePoints << " PV" << endl;

	for (int i = 0; i < 3; i++)
	{
		if (mWeapons[i].GetWeaponType() != WeaponType::Default) {
			cout << "Arme " << i+1 << " : " << mWeapons[i].WeaponToStr(mWeapons[i].GetWeaponType()) << endl;
		}
	}
	cout << "Race : " << RaceToStr(mRace) << endl;
	cout << "Job : " << JobToStr(mJob) << endl << endl;
}

void Character::AddToInventory(Weapon weapon) {
	bool CanAddToInventory = false;
	for (int i = 0; i < 3; i++)
	{
		if (mWeapons[i].GetWeaponType() == WeaponType::Default) {
			mWeapons[i] = weapon;
			cout << "Vous avez obtenu : " << weapon.WeaponToStr(weapon.GetWeaponType())
				<< " | Poids : " << weapon.GetWeaponWeight()
				<< " | Degats : " << weapon.GetWeaponDamages()
				<< " | Cout : " << weapon.GetWeaponCost()
				<< " | Durabilite : " << weapon.GetWeaponDurability() << endl;
			CanAddToInventory = true;
			return;
		}
	}
}

void Character::ShowInventory() {
	for (int i = 0; i < 3; i++)
	{
		if (mWeapons[i].GetWeaponType() != WeaponType::Default) {
			cout << "- Arme " << i+1 << " : " << mWeapons[i].WeaponToStr(mWeapons[i].GetWeaponType()) 
				<< " | Poids : " << mWeapons[i].GetWeaponWeight()
				<< " | Degats : " << mWeapons[i].GetWeaponDamages()
				<< " | Cout : " << mWeapons[i].GetWeaponCost()
				<< " | Durabilite : " << mWeapons[i].GetWeaponDurability() << endl;
		}
	}
}

bool Character::IsInventoryFull() {
	bool inventoryFull = true;
	for (int i = 0; i < 3; i++)
	{
		if (mWeapons[i].GetWeaponType() == WeaponType::Default) {
			inventoryFull = false;
		}
	}
	return inventoryFull;
}

int Character::InventorySize() {
	int size = 0;
	for (int i = 0; i < 3; i++)
	{
		if (mWeapons[i].GetWeaponType() != WeaponType::Default) {
			size++;
		}
	}
	return size;
}

void Character::RemoveFromInventory(int number) {
	mWeapons[number] = Weapon();
}

void Character::BuyWeapon(Merchant merchant, int number) {
	if (IsInventoryFull()) {
		cout << "Ton inventaire est plein, tu ne peux pas acheter cet objet" << endl;
		return;
	}
	Weapon merchantWeapon = merchant.GetWeapon(number);
	if (mMoney >= merchantWeapon.GetWeaponCost()) {
		mMoney -= merchantWeapon.GetWeaponCost();
		AddToInventory(merchantWeapon);
		cout << "Tu possedes desormais : " << merchantWeapon.GetWeaponName() << endl;
		cout << "Il te reste : " << mMoney << " rubis." << endl << endl;
	}
	else {
		cout << "Tu ne peux pas acheter cette arme, tu n'as pas assez d'argent." << endl;
	}
}

void Character::SellWeapon(Merchant merchant, int number) {
	if (InventorySize() <= 1) {
		cout << "Il ne te reste qu'une arme, tu ne peux pas la vendre." << endl;
		return;
	}

	Weapon weaponToSell = mWeapons[number];
	if (weaponToSell.GetWeaponType() == WeaponType::Default) {
		cout << "Tu ne peux pas me vendre cette arme." << endl;
		return;
	}

	if (merchant.GetMoney() < weaponToSell.GetWeaponCost()) {
		cout << "Je n'ai plus assez d'argent pour acheter ton arme. Il me reste " << merchant.GetMoney() << " rubis alors que ton arme coute " << weaponToSell.GetWeaponCost() << " rubis." << endl;
		return;
	}
	else if (merchant.GetMoney() >= weaponToSell.GetWeaponCost()) {
		RemoveFromInventory(number);
		merchant.SetMoney(merchant.GetMoney() - weaponToSell.GetWeaponCost());
		mMoney += weaponToSell.GetWeaponCost();
		cout << "Merci pour votre arme. Vous avez desormais " << mMoney << " rubis et il me reste " << merchant.GetMoney() << " rubis." << endl;
		return;
	}
}

void Character::Attack(Character& character, int number) {
	Weapon& attackWeapon = mWeapons[number];
	if (attackWeapon.GetWeaponType() == WeaponType::Default) {
		cout << "Tu ne peux attaquer avec cette arme." << endl;
		return;
	}

	character.SetPV(character.GetPV() - attackWeapon.GetWeaponDamages());
	if (character.GetPV() < 0) {
		character.SetPV(0);
	}

	attackWeapon.SetDurability(attackWeapon.GetWeaponDurability() - 0.1f);
	attackWeapon.SetCost();

	if (attackWeapon.GetWeaponDurability() <= 0) {
		cout << "Ton arme s'est cassee" << endl;
		attackWeapon = Weapon();
		return;
	}

	cout << attackWeapon.GetWeaponName() << " a inflige "
		<< attackWeapon.GetWeaponDamages() << " degats a " << character.GetName()
		<< ". Il lui reste " << character.GetPV() << " PV."
		<< endl;
}
#include "Character.h"
#include <iostream>
using namespace std;


Character::Character() {
	mFirstName = "Undefined";
	mLastName = "Undefined";
	mCatchPhrase = "Undefined";
	mMoney = 0;
	mLifePoints = 0;
	mWeapon = Weapon();
	mRace = Race::Default;
	mJob = Job::Default;
}


Character::Character(string firstName, string lastName, string catchPhrase, int money, int lifePoints, Weapon weapon, Race race, Job job) {
	mFirstName = firstName;
	mLastName = lastName;
	mCatchPhrase = catchPhrase;
	mMoney = money;
	mLifePoints = lifePoints;
	mWeapon = weapon;
	mRace = race;
	mJob = job;
}

Character::~Character(){}

string Character::Introduce() {
	cout << "Bonjour, je m'appelle" << mFirstName << " " << mLastName << endl;
	cout << mCatchPhrase << endl;
	cout << "Argent :" << mMoney << " rubis" << endl;
	cout << "Arme :" << mLifePoints << " PVs" << endl;
	cout << "Race :" << mRace << endl;
	cout << "Job :" << mJob << endl;
}

//void Buy();
//void Sell();
//void Attack();
//void Loot();
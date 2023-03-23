#include <iostream>
#include "Weapon.h"
#include "Character.h"
using namespace std;

Weapon Epee;
Character mainCharacter;

int main()
{
    Epee = Weapon("Epee", WeaponType::Sword, 10, 10, 10);
	mainCharacter = Character("Ethan", "Winters", "Aie", 10, 10, Epee, Race::Human, Job::Warrior);
	mainCharacter.Introduce();
	
}
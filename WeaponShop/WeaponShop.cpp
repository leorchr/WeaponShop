#include <iostream>
#include "Weapon.h"
#include "Character.h"
#include "Merchant.h"
using namespace std;

Weapon Bow = Weapon("Arc", WeaponType::Bow, 20, 10, 50);
Weapon Dagger = Weapon("Dague", WeaponType::Dagger, 15, 15, 100);
Weapon Staff = Weapon("Baton", WeaponType::Staff, 15, 17, 120);
Weapon Sword = Weapon("Epee", WeaponType::Sword, 50, 20, 150);
Weapon WeakSword = Weapon("Epee", WeaponType::Sword, 50, 5, 5);
Weapon WeakEnemySword = Weapon("Epee", WeaponType::Sword, 50, 2, 5);
Weapon playerInventory[3] = { WeakSword, Weapon(), Weapon() };
Weapon enemyInventory[3] = {WeakEnemySword, Weapon(), Weapon()};
Weapon merchantInventory[4] = { Sword, Bow, Dagger, Staff };

Character mainCharacter;
Character enemy;
Merchant merchant = Merchant(
	"Sir Alfred",
	"L'Armurerie Royale",
	"Entrez dans l'Armurerie Royale et decouvrez un monde de puissance et de force.",
	"Devenez un expert en armes avec notre expertise.",
	50,
	merchantInventory
);
void GameIntroduction();
void PlayerChoice();
void StartFight();
void TalkToMerchant();
void MerchantChoice();
void BuyWeaponChoice();
void SellWeaponChoice();


int main()
{
	GameIntroduction();
	PlayerChoice();
	return 0;
}

void GameIntroduction() {
	cout << "-- Bienvenue dans le simulateur de marchand d'armes ! --" << endl << endl;
	cout << "Dans ce simulateur, tu vas pouvoir acheter des armes, vendre des armes et engager des combats." << endl;
	cout << "!!! Attention !!! Tu doit toujours repondre par des numeros sauf pour la creation du personnage." << endl;
	cout << "!!! Attention !!! Tu peux avoir 3 armes maximum dans ton inventaire." << endl << endl;
	cout << "Premierement, tu dois nommer ton personnage. Quel est ton prenom ?" << endl;
	string firstName;
	getline(cin, firstName);
	cout << "\nBien, ensuite quel est ton nom de famille ?" << endl;
	string lastName;
	getline(cin, lastName);
	cout << "\nChoisis ta phrase d'accroche :" << endl;
	string textIntro;
	getline(cin, textIntro);
	mainCharacter = Character(firstName, lastName, textIntro, 1000, 100, playerInventory, Race::Human, Job::Warrior);
}

void PlayerChoice() {
	cout << "\nQue veux-tu faire : " << endl;
	cout << "(1) Consulter ton inventaire" << endl;
	cout << "(2) Aller parler au marchand" << endl;
	cout << "(3) Engager un combat" << endl;
	int answer;
	do {
		cin >> answer;
		if (answer == 1) {
			cout << endl;
			mainCharacter.ShowInventory();
		}
		else if (answer == 2) {
			TalkToMerchant();
			merchant.Introduce();
			MerchantChoice();
		}
		else if (answer == 3) {
			StartFight();
		}
	} while (answer != 1 && answer != 2 && answer != 3);
	PlayerChoice();
}

void StartFight() {
	enemyInventory[1] = WeakEnemySword;
	Character enemy = Character("Clap", "Trap", "Je suis le dernier de mon espece. D'ailleurs, je n'ai pas d'amis.", 10, 20, enemyInventory, Race::Elf, Job::Archer);
	enemy.Introduce();

	int number;
	do {
		do {
			cout << "\nAvec quelle arme souhaites-tu attaquer l'ennemi ?" << endl;
			mainCharacter.ShowInventory();
			cin >> number;
			if (number == 1) {
				mainCharacter.Attack(enemy, number - 1);
			}
			else if (number == 2) {
				mainCharacter.Attack(enemy, number - 1);
			}
			else if (number == 3) {
				mainCharacter.Attack(enemy, number - 1);
			}
		} while (number != 1 && number != 2 && number != 3);

		if (enemy.GetPV() <= 0) {
			cout << "\nTu as gagne le combat." << endl;
			mainCharacter.AddToInventory(enemy.GetWeapon());
			mainCharacter.ShowInventory();
		}
		else if (mainCharacter.GetPV() <= 0) {
			cout << "\nTu es mort. Game Over" << endl;
		}
		else {
			enemy.Attack(mainCharacter, 0);
		}

	} while (enemy.GetPV() > 0 && mainCharacter.GetPV() > 0);
}

void TalkToMerchant() {
	cout << "\nSouhaites-tu te presenter au marchand ?" << endl;
	cout << "(1) Oui" << endl;
	cout << "(2) Non" << endl;
	int answer;
	do {
		cin >> answer;
		if (answer == 1) {
			mainCharacter.Introduce();
		}
		else if (answer == 2) {
			cout << "\nTu es malpoli..." << endl;
		}
	} while (answer != 1 && answer != 2);
}

void MerchantChoice() {
	cout << "\nQue veux-tu faire mon petit ?" << endl;
	cout << "(1) Acheter une arme" << endl;
	cout << "(2) Vendre une arme" << endl;
	cout << "(3) Ne rien faire" << endl;
	int number;
	do {
		cin >> number;
		if (number == 1) {
			BuyWeaponChoice();
		}
		else if (number == 2) {
			SellWeaponChoice();
		}
		else if (number == 3) {
			return;
		}
	} while (number != 1 && number != 2 && number != 3);
}

void BuyWeaponChoice() {
	cout << "\nQuelle arme veux-tu acheter ? 1, 2, 3 ou 4 ?" << endl;
	cout << "\nTu as " << mainCharacter.GetMoney() << " rubis." << endl;
	int number;
	do {
		cin >> number;
		if (number == 1) {
			mainCharacter.BuyWeapon(merchant, number - 1);
		}
		else if (number == 2) {
			mainCharacter.BuyWeapon(merchant, number - 1);
		}
		else if (number == 3) {
			mainCharacter.BuyWeapon(merchant, number - 1);
		}
		else if (number == 4) {
			mainCharacter.BuyWeapon(merchant, number - 1);
		}
	} while (number != 1 && number != 2 && number != 3 && number != 4);
}

void SellWeaponChoice() {
	cout << "\nQuelle arme veux-tu me vendre ?" << endl << endl;
	mainCharacter.ShowInventory();
	int number;
	do {
		cin >> number;
		if (number == 1) {
			mainCharacter.SellWeapon(merchant, number - 1);
		}
		else if (number == 2) {
			mainCharacter.SellWeapon(merchant, number - 1);
		}
		else if (number == 3) {
			mainCharacter.SellWeapon(merchant, number - 1);
		}
	} while (number != 1 && number != 2 && number != 3);
}
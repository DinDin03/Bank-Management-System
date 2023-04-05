#include "warrior.h"

#include <iostream>
#include <string>
using namespace std;

Warrior::Warrior(string name, int health, int damage, string weapon)
    : Player(name, health, damage) {
  this->weapon = weapon;
}
void Warrior::setWeapon(string weapon) { this->weapon = weapon; }
string Warrior::getWeapon() { return weapon; }
void Warrior::swingWeapon(Player* opponent) {
  cout << name << " swings his sword to " << opponent->getName() << " for "
       << damage << " damage!" << endl;
  opponent->takeDamage(damage);
}

#include "wizard.h"

#include <iostream>
#include <string>
using namespace std;

Wizard::Wizard(string name, int health, int damage, int mana)
    : Player(name, health, damage) {
  this->mana = mana;
}
void Wizard::setMana(int mana) { this->mana = mana; }
int Wizard::getMana() { return mana; }
void Wizard::castSpell(Player* opponent) {
  cout << name << " casts a spell on " << opponent->getName() << " for " << mana
       << " damage!" << endl;
  opponent->takeDamage(mana);
}
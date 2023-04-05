#include "wizard.h"
#include <iostream>

Wizard::Wizard(std::string name, int health, int damage, int mana)
    : Player(name, health, damage), mana(mana) {}

int Wizard::getMana() const {
    return mana;
}

void Wizard::setMana(int mana) {
    this->mana = mana;
}

void Wizard::castSpell(Player* opponent) {
    int damage = mana;
    opponent->takeDamage(damage);
    std::cout << name << " casts a spell on " << opponent->getName() << " for " << damage << " damage.\n" << std::endl;
}

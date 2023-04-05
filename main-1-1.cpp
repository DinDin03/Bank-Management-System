#include <iostream>
#include "player.h"
#include "warrior.h"
#include "wizard.h"

using namespace std;

int main() {
  // Wizard(name, health, damage, mana)
  Wizard wizard("Gandalf", 100, 20, 50);
  // Warrior(name, health, damage, weapon)
  Warrior warrior("Aragorn", 120, 25, "Sword");
  cout << "Let the battle begin!\n" << endl;
  cout << wizard.getName() << " has " <<wizard.getHealth() << " health" << endl;
  cout << warrior.getName() << " has " <<warrior.getHealth() << " health\n" << endl;
  while (wizard.getHealth() > 0 && warrior.getHealth() > 0) {
    cout << wizard.getName() << " casts a spell on " << warrior.getName() << " for " << wizard.getDamage() << " damage." << endl;
    warrior.takeDamage(wizard.getDamage());
    if (warrior.getHealth() > 0) {
      cout << warrior.getName() << " swings their " << warrior.getWeapon() << " at " << wizard.getName() << "!" << endl;
      wizard.takeDamage(warrior.getDamage());
    }
  }
  if (wizard.getHealth() > 0) {
    cout << wizard.getName() << " wins!" << endl;
  } else {
    cout << warrior.getName() << " wins!" << endl;
  }
  return 0;
}

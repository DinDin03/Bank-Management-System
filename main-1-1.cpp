#include <cstdlib>
#include <ctime>
#include <iostream>

#include "player.h"
#include "warrior.h"
#include "wizard.h"

using namespace std;

int main() {
    int option;
    cout << "Do you want to be the Wizard or the Warrior? Enter 1 for Wizard and 0 for Warrior: ";
    cin >> option;
    if(option == 0){
        cout << "You have chosen Wizard!" << endl;
    }
    else{
        cout << "You have chosen Warrior!" << endl;
    }
  srand(time(0));
  cout << "Let the battle begin!\n" << endl;

  Wizard wizard("Gandalf", 200, rand() % 20 + 1, rand() % 50 + 1);
  Warrior warrior("Aragorn", 200, rand() % 50 + 1, "Sword");

  while (wizard.getHealth() > 0 && warrior.getHealth() > 0) {
    int randomWizDamAtt = rand() % 20 + 1;
    int randomWizDamMan = rand() % 50 + 1;
    int randomWarDam = rand() % 50 + 1;

    wizard.setDamage(randomWizDamAtt);
    wizard.setMana(randomWizDamMan);
    warrior.setDamage(randomWarDam);

    wizard.castSpell(&warrior);
    if (warrior.getHealth() > 0) {
      warrior.swingWeapon(&wizard);
    }
  }

  if (wizard.getHealth() > 0) {
    cout << wizard.getName() << " wins!" << endl;
  } else {
    cout << warrior.getName() << " wins!" << endl;
  }

  return 0;
}

#ifndef WIZARD_H
#define WIZARD_H
#include <string>
using namespace std;
#include "player.h"

class Wizard : public Player {
 private:
  int mana;

 public:
  Wizard(string name, int health, int damage, int mana);
  void setMana(int mana);
  int getMana();
  void castSpell(Player* opponent);
};

#endif
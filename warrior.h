#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>
using namespace std;
#include "player.h"

class Warrior : public Player {
 private:
  string weapon;

 public:
  Warrior(string name, int health, int damage, string weapon);
  void setWeapon(string weapon);
  string getWeapon();
  void swingWeapon(Player* opponent);
};

#endif
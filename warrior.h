#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>
using namespace std;
#include "player.h"

class Warrior : public Player{
    private: 
      string weapon;
    public:
      void swingWeapon(Player* opponent);
    
};

#endif
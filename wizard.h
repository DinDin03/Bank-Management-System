#ifndef WIZARD_H
#define WIZARD_H
#include <string>
using namespace std;
#include "player.h"

class Wizard : public Player{
    private: 
      int mana;
    public:
      void castSpell(Player* opponent);
    
};

#endif
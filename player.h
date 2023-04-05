#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player{
    private:
      string name;
      int health;
      int damage;
    public:
      Player(string name, int health, int damage);
      void attack(Player* opponent, int damage)
      void takeDamage(int damage);
};

#endif
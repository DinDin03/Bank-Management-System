#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player {
 public:
  string name;
  int health;
  int damage;
  Player(string name, int health, int damage);
  string getName();
  int getDamage();
  int getHealth();
  void setName(string name);
  void setHealth(int health);
  void setDamage(int damage);
  void attack(Player* opponent, int damage);
  void takeDamage(int damage);
};

#endif
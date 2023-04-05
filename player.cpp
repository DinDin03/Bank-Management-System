#include "player.h"

#include <iostream>
#include <string>
using namespace std;

Player::Player(string name, int health, int damage) {
  this->name = name;
  this->health = health;
  this->damage = damage;
}
void Player::setName(string name) { this->name = name; }
void Player::setHealth(int health) { this->health = health; }
void Player::setDamage(int damage) { this->damage = damage; }
string Player::getName() { return name; }
int Player::getHealth() { return health; }
int Player::getDamage() { return damage; }
void Player::attack(Player* opponent, int damage) {
  opponent->takeDamage(damage);
}
void Player::takeDamage(int damage) {
  cout << name << " took " << damage << " damage" << endl;
  health -= damage;
  if (health > 0) {
    cout << "remaining health is " << health << endl;
  } else {
    cout << "no health left" << endl;
  }
}

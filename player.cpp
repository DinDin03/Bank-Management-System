#include "player.h"
#include <string>
#include <iostream>
using namespace std;

Player::Player(string name, int health, int damage){
    this->name = name;
    this->health = health;
    this->damage = damage;
}
string Player::setName(string name){
    this->name = name;
}
int Player::setHealth(int health){
    this->health = health;
}
int Player::setDamage(int damage){
    this->damage = damage;
}
string Player::getName(string name){
    return name;
}
int Player::getHealth(int health){
    return health;
}
int Player::getDamage(int damage){
    return damage;
}
void Player::attack(Player* opponent, int damage){
    this->opponent =
}

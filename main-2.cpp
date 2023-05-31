#include <iostream>
#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"

int main() {
    // Create Ship object
    Ship ship(3, 4);
    std::cout << "Ship Position: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")" << std::endl;
    ship.move(1, -1);
    std::cout << "New Ship Position: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")" << std::endl;

    // Create Mine object
    Mine mine(6, 2);
    std::cout << "Mine Position: (" << std::get<0>(mine.getPos()) << ", " << std::get<1>(mine.getPos()) << ")" << std::endl;
    Explosion explosion = mine.explode();
    std::cout << "Explosion Position: (" << std::get<0>(explosion.getPos()) << ", " << std::get<1>(explosion.getPos()) << ")" << std::endl;
    std::cout << "Ship Type before explosion: " << ship.getType() << std::endl;
    explosion.apply(ship);
    std::cout << "Ship Type after explosion: " << ship.getType() << std::endl;

    return 0;
}

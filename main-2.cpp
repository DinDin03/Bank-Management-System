#include "Trap.h"
#include "Character.h"
#include "Effect.h"
#include <iostream>
#include "Cell.h"

int main() {
    Trap trap(2, 3);
    std::cout << "Trap position: (" << std::get<0>(trap.getPos()) << ", " << std::get<1>(trap.getPos()) << ")" << std::endl;
    std::cout << "Trap type: " << trap.getType() << std::endl;
    std::cout << "Trap active status: " << (trap.isActive() ? "Active" : "Inactive") << std::endl;

    Character character(5, 7);
    std::cout << "Character position: (" << std::get<0>(character.getPos()) << ", " << std::get<1>(character.getPos()) << ")" << std::endl;
    std::cout << "Character type: " << character.getType() << std::endl;

    character.move(1, -1);
    std::cout << "Character position after move: (" << std::get<0>(character.getPos()) << ", " << std::get<1>(character.getPos()) << ")" << std::endl;

    trap.apply(character);
    std::cout << "Character type after trap activation: " << character.getType() << std::endl;
    std::cout << "Trap active status after activation: " << (trap.isActive() ? "Active" : "Inactive") << std::endl;

    return 0;
}

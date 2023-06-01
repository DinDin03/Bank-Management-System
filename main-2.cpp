#include <iostream>
using namespace std;
#include "Cell.h"
#include "Character.h"
#include "Effect.h"
#include "Trap.h"

int main() {
  Trap trap(2, 3);
  cout << "Trap position: (" << get<0>(trap.getPos()) << ", "
       << get<1>(trap.getPos()) << ")" << endl;
  cout << "Trap type: " << trap.getType() << endl;
  cout << "Trap active status: " << (trap.isActive() ? "Active" : "Inactive")
       << endl;

  Character character(5, 7);
  cout << "Character position: (" << get<0>(character.getPos()) << ", "
       << get<1>(character.getPos()) << ")" << endl;
  cout << "Character type: " << character.getType() << endl;

  character.move(1, -1);
  cout << "Character position after move: (" << get<0>(character.getPos())
       << ", " << get<1>(character.getPos()) << ")" << endl;

  trap.apply(character);
  cout << "Character type after trap activation: " << character.getType()
       << endl;
  cout << "Trap active status after activation: "
       << (trap.isActive() ? "Active" : "Inactive") << endl;

  return 0;
}

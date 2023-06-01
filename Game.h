#ifndef GAME_H
#define GAME_H
using namespace std;
#include <iostream>
#include <vector>
#include "Cell.h"
#include "Character.h"
#include "Effect.h"
#include "Trap.h"
#include "Utils.h"

class Game {
 private:
  vector<Cell*> grid;
  int gridWidth, gridHeight;

 public:
  vector<Cell*>& getGrid() { return grid; }

  void initGame(int numCharacters, int numTraps, int gridWidth,
                int gridHeight) {
    this->gridWidth = gridWidth;
    this->gridHeight = gridHeight;
    for (int i = 0; i < numCharacters; i++) {
      tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
      Character* character = new Character(get<0>(pos), get<1>(pos));
      grid.push_back(character);
    }

    for (int i = 0; i < numTraps; i++) {
      tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
      Trap* trap = new Trap(get<0>(pos), get<1>(pos));
      grid.push_back(trap);
    }
  }

  void gameLoop(int maxIterations, double trapActivationDistance) {
    for (int i = 0; i < maxIterations; i++) {
      for (Cell* cell : grid) {
        if (Character* character = dynamic_cast<Character*>(cell)) {
          character->move(1, 0);

          for (Cell* otherCell : grid) {
            if (Trap* trap = dynamic_cast<Trap*>(otherCell)) {
              double distance =
                  Utils::calculateDistance(character->getPos(), trap->getPos());
              if (distance <= trapActivationDistance && trap->isActive()) {
                trap->apply(*character);
              }
            }
          }

          if (get<0>(character->getPos()) < 0 ||
              get<0>(character->getPos()) >= gridWidth ||
              get<1>(character->getPos()) < 0 ||
              get<1>(character->getPos()) >= gridHeight) {
            cout << "Character has won the game!" << endl;
            return;
          }
        }
      }
    }

    cout << "Maximum number of iterations reached. Game over." << endl;
  }
};

#endif  // GAME_H

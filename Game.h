#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Cell.h"
#include "Character.h"
#include "Effect.h"
#include "Trap.h"
#include "Utils.h"

class Game {
 private:
  std::vector<Cell*> grid;
  int gridWidth, gridHeight;

 public:
  std::vector<Cell*>& getGrid() { return grid; }

  void initGame(int numCharacters, int numTraps, int gridWidth,
                int gridHeight) {
    this->gridWidth = gridWidth;
    this->gridHeight = gridHeight;
    for (int i = 0; i < numCharacters; i++) {
      std::tuple<int, int> pos =
          Utils::generateRandomPos(gridWidth, gridHeight);
      Character* character = new Character(std::get<0>(pos), std::get<1>(pos));
      grid.push_back(character);
    }

    for (int i = 0; i < numTraps; i++) {
      std::tuple<int, int> pos =
          Utils::generateRandomPos(gridWidth, gridHeight);
      Trap* trap = new Trap(std::get<0>(pos), std::get<1>(pos));
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

          if (std::get<0>(character->getPos()) < 0 ||
              std::get<0>(character->getPos()) >= gridWidth ||
              std::get<1>(character->getPos()) < 0 ||
              std::get<1>(character->getPos()) >= gridHeight) {
            std::cout << "Character has won the game!" << std::endl;
            return;
          }
        }
      }
    }

    std::cout << "Maximum number of iterations reached. Game over."
              << std::endl;
  }
};

#endif  // GAME_H

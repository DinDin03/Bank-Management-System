#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GameEntity.h"
#include "Utils.h"
#include "Ship.h"
#include "Mine.h"


class Game {
public:
    std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight) {
        for (int i = 0; i < numShips; i++) {
            std::tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Ship(std::get<0>(pos), std::get<1>(pos)));
        }

        for (int i = 0; i < numMines; i++) {
            std::tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Mine(std::get<0>(pos), std::get<1>(pos)));
        }

        return entities;
    }

    void gameLoop(int maxIterations, double mineDistanceThreshold) {
        int iteration = 0;
        while (iteration < maxIterations) {
            for (GameEntity* entity : entities) {
                if (Ship* ship = dynamic_cast<Ship*>(entity)) {
                    ship->move(1, 0);
                }
            }

            for (GameEntity* entity : entities) {
                if (Mine* mine = dynamic_cast<Mine*>(entity)) {
                    for (GameEntity* otherEntity : entities) {
                        if (Ship* ship = dynamic_cast<Ship*>(otherEntity)) {
                            double distance = Utils::calculateDistance(mine->getPos(), ship->getPos());
                            if (distance <= mineDistanceThreshold) {
                                Explosion explosion = mine->explode();
                                explosion.apply(*ship);
                            }
                        }
                    }
                }
            }

            iteration++;
        }
    }

private:
    std::vector<GameEntity*> entities;
};

#endif // GAME_H

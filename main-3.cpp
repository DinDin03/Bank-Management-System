#include <iostream>
#include "Game.h"

int main() {
    // Create Game object
    Game game;
    
    // Initialize game entities
    int numShips = 3;
    int numMines = 4;
    int gridWidth = 10;
    int gridHeight = 10;
    
    std::vector<GameEntity*> entities = game.initGame(numShips, numMines, gridWidth, gridHeight);
    
    // Print initial entity positions
    std::cout << "Initial Entity Positions:" << std::endl;
    for (GameEntity* entity : entities) {
        std::cout << "Entity Type: " << entity->getType() << ", Position: (" << std::get<0>(entity->getPos()) << ", "
                  << std::get<1>(entity->getPos()) << ")" << std::endl;
    }
    
    // Run the game loop
    int maxIterations = 10;
    double mineDistanceThreshold = 2.5;
    game.gameLoop(maxIterations, mineDistanceThreshold);
    
    // Print final entity positions
    std::cout << "\nFinal Entity Positions:" << std::endl;
    for (GameEntity* entity : entities) {
        std::cout << "Entity Type: " << entity->getType() << ", Position: (" << std::get<0>(entity->getPos()) << ", "
                  << std::get<1>(entity->getPos()) << ")" << std::endl;
    }
    
    // Free memory for game entities
    for (GameEntity* entity : entities) {
        delete entity;
    }
    
    return 0;
}

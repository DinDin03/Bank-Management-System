#include "Game.h"

int main() {
    int numCharacters = 2;
    int numTraps = 3;
    int gridWidth = 10;
    int gridHeight = 10;
    int maxIterations = 100;
    double trapActivationDistance = 2.0;

    Game game;
    game.initGame(numCharacters, numTraps, gridWidth, gridHeight);
    game.gameLoop(maxIterations, trapActivationDistance);

    return 0;
}

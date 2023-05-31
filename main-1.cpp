#include <iostream>
#include "Utils.h"

int main() {
    // Generate random positions
    int gridWidth = 10;
    int gridHeight = 10;

    std::cout << "Random Positions:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
        std::cout << "Position " << i + 1 << ": (" << std::get<0>(pos) << ", " << std::get<1>(pos) << ")" << std::endl;
    }

    // Calculate distances between positions
    std::tuple<int, int> pos1(2, 3);
    std::tuple<int, int> pos2(5, 7);
    double distance = Utils::calculateDistance(pos1, pos2);
    std::cout << "Distance between (" << std::get<0>(pos1) << ", " << std::get<1>(pos1) << ") and ("
              << std::get<0>(pos2) << ", " << std::get<1>(pos2) << "): " << distance << std::endl;

    return 0;
}

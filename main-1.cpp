#include "Cell.h"
#include "Effect.h"
#include "Utils.h"
#include <iostream>

int main() {
    Cell cell(2, 3, 'A');
    std::tuple<int, int> pos = cell.getPos();
    std::cout << "Cell position: (" << std::get<0>(pos) << ", " << std::get<1>(pos) << ")" << std::endl;
    std::cout << "Cell type: " << cell.getType() << std::endl;

    Utils utils;
    std::tuple<int, int> randomPos = utils.generateRandomPos(10, 10);
    std::cout << "Random position: (" << std::get<0>(randomPos) << ", " << std::get<1>(randomPos) << ")" << std::endl;

    std::tuple<int, int> pos1(2, 3);
    std::tuple<int, int> pos2(5, 7);
    double distance = utils.calculateDistance(pos1, pos2);
    std::cout << "Distance between pos1 and pos2: " << distance << std::endl;

    return 0;
}

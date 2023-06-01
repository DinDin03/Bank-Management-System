#ifndef UTILS_H
#define UTILS_H

#include <tuple>
#include <random>
#include <cmath>

class Utils {
public:
    static std::tuple<int, int> generateRandomPos(int gridWidth, int gridHeight) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> disX(0, gridWidth - 1);
        std::uniform_int_distribution<> disY(0, gridHeight - 1);
        int x = disX(gen);
        int y = disY(gen);
        return std::make_tuple(x, y);
    }

    static double calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {
        int x1, y1, x2, y2;
        std::tie(x1, y1) = pos1;
        std::tie(x2, y2) = pos2;
        double dx = x2 - x1;
        double dy = y2 - y1;
        return std::sqrt(dx * dx + dy * dy);
    }
};

#endif // UTILS_H

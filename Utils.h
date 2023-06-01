#ifndef UTILS_H
#define UTILS_H
using namespace std;
#include <cmath>
#include <random>
#include <tuple>

class Utils {
 public:
  static tuple<int, int> generateRandomPos(int gridWidth, int gridHeight) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> disX(0, gridWidth - 1);
    uniform_int_distribution<> disY(0, gridHeight - 1);
    int x = disX(gen);
    int y = disY(gen);
    return make_tuple(x, y);
  }

  static double calculateDistance(tuple<int, int> pos1, tuple<int, int> pos2) {
    int x1, y1, x2, y2;
    tie(x1, y1) = pos1;
    tie(x2, y2) = pos2;
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
  }
};

#endif  // UTILS_H

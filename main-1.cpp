#include <iostream>
using namespace std;
#include "Cell.h"
#include "Effect.h"
#include "Utils.h"

int main() {
  Cell cell(2, 3, 'A');
  tuple<int, int> pos = cell.getPos();
  cout << "Cell position: (" << get<0>(pos) << ", " << get<1>(pos) << ")"
       << endl;
  cout << "Cell type: " << cell.getType() << endl;

  Utils utils;
  tuple<int, int> randomPos = utils.generateRandomPos(10, 10);
  cout << "Random position: (" << get<0>(randomPos) << ", " << get<1>(randomPos)
       << ")" << endl;

  tuple<int, int> pos1(2, 3);
  tuple<int, int> pos2(5, 7);
  double distance = utils.calculateDistance(pos1, pos2);
  cout << "Distance between pos1 and pos2: " << distance << endl;

  return 0;
}

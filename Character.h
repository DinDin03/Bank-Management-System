#ifndef CHARACTER_H
#define CHARACTER_H
using namespace std;
#include "Cell.h"

class Character : public Cell {
 public:
  Character(int x, int y) : Cell(x, y, 'C') {}

  void move(int dx, int dy) {
    int currentX, currentY;
    tie(currentX, currentY) = getPos();
    setPos(currentX + dx, currentY + dy);
  }
};

#endif

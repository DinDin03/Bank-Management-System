#ifndef CELL_H
#define CELL_H
using namespace std;
#include <tuple>

class Cell {
 private:
  tuple<int, int> position;
  char type;

 public:
  Cell(int x, int y, char cellType)
      : position(make_tuple(x, y)), type(cellType) {}
  tuple<int, int> getPos() { return position; }
  char getType() { return type; }
  void setPos(int x, int y) { position = make_tuple(x, y); }
  void setType(char cellType) { type = cellType; }
  virtual ~Cell() {}
};

#endif  // CELL_H

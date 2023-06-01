#ifndef TRAP_H
#define TRAP_H

#include "Cell.h"
#include "Effect.h"
using namespace std;
class Trap : public Cell, public Effect {
private:
    bool active;

public:
    Trap(int x, int y) : Cell(x, y, 'T'), active(true) {}

    bool isActive() { return active; }

    void apply(Cell& cell) override {
        cell.setType('T');
        active = false;
    }
};

#endif // TRAP_H

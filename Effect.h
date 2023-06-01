#ifndef EFFECT_H
#define EFFECT_H
using namespace std;
class Cell;

class Effect {
public:
    virtual void apply(Cell& cell) = 0;
    virtual ~Effect(){}
};

#endif

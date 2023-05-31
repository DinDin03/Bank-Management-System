#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "AirCraft.h"

class Airplane : public AirCraft {
public:
    Airplane();
    Airplane(int w, int p);

    void reducePassengers(int x);
    int get_numPassengers();
    virtual void fly(int headwind, int minutes);

private:
    int numPassengers;
};

#endif

#ifndef BUS_H
#define BUS_H
#include <string>
#include "Vehicle.h"

class Bus : public Vehicle {
public:
    Bus(int id);
    int getParkingDuration();
    std::string getType();
};

#endif

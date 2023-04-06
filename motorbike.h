#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <string>
#include "Vehicle.h"

class Motorbike : public Vehicle {
public:
    Motorbike(int id);
    int getParkingDuration();
    std::string getType();

};

#endif

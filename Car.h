#ifndef CAR_H
#define CAR_H
#include <string>
#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(int id);
    int getParkingDuration();
    std::string getType();

};

#endif

#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>
using namespace std;

class Car : public Vehicle{
    public:
      int getParkingDuration();
      Car(int ID);
};

#endif
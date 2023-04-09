#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <ctime>
#include "Vehicle.h"

class Motorbike : public Vehicle{
    public:
      Motorbike(int ID);
      int getParkingDuration();
};

#endif
#ifndef BUS_H
#define BUS_H 
#include <ctime>
#include "Vehicle.h"

class Bus : public Vehicle{
    public:
      Bus(int ID);
      int getParkingDuration();
};

#endif
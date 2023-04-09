#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include <ctime>
#include <string>
#include "Vehicle.h"
using namespace std;

class ParkingLot : public Vehicle{
    protected:
      int maxVehicle;
      int currentCount;
    public:
      ParkingLot(int maxVehicle);
      int getCount();
      void parkVehicle(Vehicle* vehicle);
      void unparkVehicle(int ID);
      ~ParkingLot();
};
#endif

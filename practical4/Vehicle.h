#ifndef VEHICLE_H
#define VEHICLE_H

#include <ctime>
#include <string>
using namespace std;

class Vehicle {
 protected:
  time_t timeOfEntry;
  int ID;
  int parkingDuration;

 public:
  int getID();
  Vehicle(int ID);
  virtual int getParkingDuration() const;
};

#endif
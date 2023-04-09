#ifndef VEHICLE_H
#define VEHICLE_H

#include <ctime>
#include <string>
using namespace std;

class Vehicle {
 protected:
  std::time_t timeOfEntry;
  int ID;

 public:
  void setID(int ID);
  int getID();
};
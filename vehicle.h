#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
using namespace std;

class Vehicle{
    protected:
      time_t timeOfEntry;
      int ID;
    public:
      Vehicle(int ID);
      void setID(int ID);
      int getID();
};
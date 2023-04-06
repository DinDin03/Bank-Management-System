#ifndef VEHICLE_H
#define VEHICLE_H

#include <ctime>
#include <string>

class Vehicle {
protected:
    std::time_t timeOfEntry;
    int ID;
public:
    Vehicle(int id);
    int getID();
    virtual int getParkingDuration() = 0;
    std::string getType();

};

#endif

#include <iostream>
#include <string>
#include <ctime>
#include "Vehicle.h"

int Vehicle::getID(){
    return ID;
}
Vehicle::Vehicle(int ID){
    this->ID = ID;
    this->timeOfEntry = time(nullptr);
}

int Vehicle::getParkingDuration() const{
    time_t currentTime = time(nullptr);
    return currentTime - timeOfEntry;
}
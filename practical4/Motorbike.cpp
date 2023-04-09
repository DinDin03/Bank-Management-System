#include "Motorbike.h"
#include <string>
#include <ctime>

using namespace std;

Motorbike::Motorbike(int ID) : Vehicle(ID){
    this->ID = ID;
}

int Motorbike::getParkingDuration(){
    time_t currentTime = time(nullptr);
    parkingDuration = 0.85*(currentTime - timeOfEntry);
    return parkingDuration;
}
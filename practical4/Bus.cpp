#include "Bus.h"
#include <string>
#include <ctime>

using namespace std;

Bus::Bus(int ID) : Vehicle(ID){
    this->ID = ID;
}

int Bus::getParkingDuration(){
    time_t currentTime = time(nullptr);
    parkingDuration = 0.75*(currentTime - timeOfEntry);
    return parkingDuration;
}
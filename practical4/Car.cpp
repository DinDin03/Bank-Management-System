#include "Car.h"
#include <string>
#include <ctime>

using namespace std;

Car::Car(int ID) : Vehicle(ID){
    this->ID = ID;
}

int Car::getParkingDuration(){
    time_t currentTime = time(nullptr);
    parkingDuration = 0.9*(currentTime - timeOfEntry);
    return parkingDuration;
}
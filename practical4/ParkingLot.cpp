#include "ParkingLot.h"

#include <ctime>
#include <iostream>
#include <string>
using namespace std;

ParkingLot::ParkingLot(int maxVehicle){
    vehicles = new Vehicle*[maxVehicle];
}

int ParkingLot::getCount() { return currentCount; }
void ParkingLot::parkVehicle(Vehicle* vehicle) {
  if (currentCount == maxVehicle) {
    cout << "The lot is full" << endl;
  } else {
    vehicles[count] = vehicle;
    count++
  }
}
void ParkingLot::unparkVehicle(int ID) {
    int index;
  for (int i = 0; i < currentCount; i++) {
    if (this->ID == vehicles[i]->getID()) {
        index = i;
    }
    else{
        cout << "Vehicle not in the lot" << endl;
    }
  }
  delete vehicles[index];
}
ParkingLot::~ParkingLot(){
    delete[] vehicles;
}
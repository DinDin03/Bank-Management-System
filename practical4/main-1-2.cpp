#include <ctime>
#include <iostream>
#include <string>
#include "Bus.h"
#include "Car.h"
#include "Motorbike.h"
#include "Vehicle.h"
#include "ParkingLot.h"

using namespace std;

int main() {
  int numVehicles, maxVehicle = 10;
  string type;
  ParkingLot lot(maxVehicle);
  
  cout << "Enter how many vehicles will be parked: ";
  cin >> numVehicles;
  int ID[numVehicles];
  
  for (int i = 0; i < numVehicles; i++) {
    bool validID = false;
    while (!validID) {
      cout << "Enter vehicle type (car, bus, motorbike) followed by ID: ";
      cin >> type >> ID[i];
      validID = true;
      for (int j = 0; j < i; j++) {
        if (ID[i] == ID[j]) {
          cout << "Error: ID " << ID[i] << " is already taken. Please enter a different ID." << endl;
          validID = false;
          break;
        }
      }
    }
    if (type == "car") {
      Car* car = new Car(ID[i]);
      lot.parkVehicle(car);
    } else if (type == "bus") {
      Bus* bus = new Bus(ID[i]);
      lot.parkVehicle(bus);
    } else if (type == "motorbike") {
      Motorbike* motorbike = new Motorbike(ID[i]);
      lot.parkVehicle(motorbike);
    }
  }
  
  for(int i = 0; i < numVehicles; i++){
    cout << "The vehicle " << lot[i]->getID() << " has been parked for " << lot[i]->getParkingDuration() << " seconds." << endl; 
  }

  int numUnpark, id;
  cout << "Enter how many vehicles you want to unpark: ";
  cin >> numUnpark;
  for(int i = 0; i < numUnpark; i++){
    cout << "Enter the ID of the vehicle to unpark: ";
    cin >> id;
    cout << "Vehicle " << lot[index]->getID() << " has been unparked" << endl;
    lot->unparkVehicle(id);
  }
  
  return 0;
}

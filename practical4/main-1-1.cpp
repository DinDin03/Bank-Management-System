#include <ctime>
#include <iostream>
#include <string>
#include "Bus.h"
#include "Car.h"
#include "Motorbike.h"
#include "Vehicle.h"

using namespace std;

int main() {
  int numVehicles;
  string type;
  
  cout << "Enter how many vehicles will be parked: ";
  cin >> numVehicles;
  int ID[numVehicles];
  
  Vehicle* vehicles[numVehicles];
  
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
      vehicles[i] = new Car(ID[i]);
    } else if (type == "bus") {
      vehicles[i] = new Bus(ID[i]);
    } else if (type == "motorbike") {
      vehicles[i] = new Motorbike(ID[i]);
    }
  }
  
  for(int i = 0; i < numVehicles; i++){
    cout << "The vehicle " << vehicles[i]->getID() << " has been parked for " << vehicles[i]->getParkingDuration() << " seconds." << endl; 
  }
  
  return 0;
}

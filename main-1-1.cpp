#include <iostream>
#include <string>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    // Prompt user for number of vehicles
    int numVehicles;
    std::cout << "How many vehicles do you want to park? ";
    std::cin >> numVehicles;

    // Create vector to hold pointers to Vehicle objects
    std::vector<Vehicle*> vehicles;

    // Prompt user for each vehicle type and ID and add to vector
    for (int i = 0; i < numVehicles; i++) {
        std::string vehicleType;
        int vehicleID;
        std::cout << "Enter vehicle type (car, bus, or motorbike) and ID separated by a space: ";
        std::cin >> vehicleType >> vehicleID;

        if (vehicleType == "car") {
            vehicles.push_back(new Car(vehicleID));
        }
        else if (vehicleType == "bus") {
            vehicles.push_back(new Bus(vehicleID));
        }
        else if (vehicleType == "motorbike") {
            vehicles.push_back(new Motorbike(vehicleID));
        }
        else {
            std::cout << "Invalid vehicle type. Please try again." << std::endl;
            i--;
        }
    }

    // Iterate over vector and call getParkingDuration() for each vehicle
    std::cout << std::endl;
    for (auto vehicle : vehicles) {
        std::cout << "Vehicle " << vehicle->getID() << " has been parked for "
                  << vehicle->getParkingDuration() << " seconds." << std::endl;
    }

    // Free memory allocated to Vehicle objects
    for (auto vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}

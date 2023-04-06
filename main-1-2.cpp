#include <iostream>
#include <string>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"

int main() {
    // Create ParkingLot object with capacity of 10 vehicles
    int maxCapacity = 10;
    ParkingLot lot(maxCapacity);

    // Prompt user for each vehicle type and ID and park in the lot
    while (lot.getCount() < maxCapacity) {
        std::string vehicleType;
        int vehicleID;
        std::cout << "Enter vehicle type (car, bus, or motorbike) and ID separated by a space: ";
        std::cin >> vehicleType >> vehicleID;

        if (vehicleType == "car") {
            Car* car = new Car(vehicleID);
            lot.parkVehicle(car);
        }
        else if (vehicleType == "bus") {
            Bus* bus = new Bus(vehicleID);
            lot.parkVehicle(bus);
        }
        else if (vehicleType == "motorbike") {
            Motorbike* motorbike = new Motorbike(vehicleID);
            lot.parkVehicle(motorbike);
        }
        else {
            std::cout << "Invalid vehicle type. Please try again." << std::endl;
        }
    }

    // Print current count of vehicles in lot
    std::cout << "The lot is full. " << lot.getCount() << " vehicles are parked in the lot." << std::endl;

    // Prompt user for vehicle ID to unpark and remove from the lot
    int vehicleID;
    std::cout << "Enter the ID of the vehicle to unpark: ";
    std::cin >> vehicleID;
    lot.unparkVehicle(vehicleID);

    // Print updated count of vehicles in lot
    std::cout << "There are now " << lot.getCount() << " vehicles parked in the lot." << std::endl;

    return 0;
}

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

    // Count the number of vehicles that have overstayed in the parking lot for more than 15 seconds
    int maxParkingDuration = 15;
    int overstayingVehicles = lot.countOverStayingVehicles(maxParkingDuration);

    // Print current count of vehicles in lot
    std::cout << "The lot is full. " << lot.getCount() << " vehicles are parked in the lot." << std::endl;

    // Print the number of vehicles that have overstayed in the parking lot for more than 15 seconds
    std::cout << "There are " << overstayingVehicles << " vehicles that have overstayed for more than " << maxParkingDuration << " seconds." << std::endl;

    return 0;
}

#include "parkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int capacity) {
    maxCapacity = capacity;
    count = 0;
    vehicles = new Vehicle*[maxCapacity];
}

ParkingLot::~ParkingLot() {
    for (int i = 0; i < count; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;
}

void ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (count < maxCapacity) {
        vehicles[count] = vehicle;
        count++;
        std::cout << vehicle->getType() << " with ID " << vehicle->getID() << " parked successfully!" << std::endl;
    }
    else {
        std::cout << "The lot is full" << std::endl;
    }
}

void ParkingLot::unparkVehicle(int id) {
    bool vehicleFound = false;
    for (int i = 0; i < count; i++) {
        if (vehicles[i]->getID() == id) {
            delete vehicles[i];
            vehicles[i] = nullptr;
            vehicleFound = true;
            std::cout << "Vehicle with ID " << id << " unparked successfully!" << std::endl;
            // Shift all vehicles after the unparked vehicle one index to the left
            for (int j = i + 1; j < count; j++) {
                vehicles[j - 1] = vehicles[j];
            }
            count--;
            break;
        }
    }
    if (!vehicleFound) {
        std::cout << "Vehicle not in the lot" << std::endl;
    }
}

int ParkingLot::getCount() const {
    return count;
}

int ParkingLot::countOverStayingVehicles(int maxParkingDuration) {
    int overstayingCount = 0;
    for (int i = 0; i < count; i++) {
        if (vehicles[i]->getParkingDuration() > maxParkingDuration) {
            overstayingCount++;
        }
    }
    return overstayingCount;
}

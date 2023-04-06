#include "ParkingLot.h"
#include <iostream>
#include <ctime>

ParkingLot::ParkingLot(int maxCapacity) {
    this->maxCapacity = maxCapacity;
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
    if (count == maxCapacity) {
        std::cout << "The lot is full" << std::endl;
    } else {
        vehicles[count] = vehicle;
        count++;
    }
}

void ParkingLot::unparkVehicle(int id) {
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (vehicles[i]->getID() == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        std::cout << "Vehicle not in the lot" << std::endl;
    } else {
        delete vehicles[index];
        count--;
        for (int i = index; i < count; i++) {
            vehicles[i] = vehicles[i + 1];
        }
    }
}

int ParkingLot::getCount() const {
    return count;
}

int ParkingLot::countOverStayingVehicles(int maxParkingDuration) {
    int countOverStaying = 0;
    time_t currentTime;
    time(&currentTime);

    for (int i = 0; i < count; i++) {
        int parkingDuration = currentTime - vehicles[i]->getParkingDuration();
        if (parkingDuration > maxParkingDuration) {
            countOverStaying++;
        }
    }

    return countOverStaying;
}

#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "vehicle.h"

class ParkingLot {
private:
    int maxCapacity;
    int count;
    int maxParkingDuration;
    Vehicle** vehicles;

public:
    ParkingLot(int capacity);
    ~ParkingLot();
    void parkVehicle(Vehicle* vehicle);
    void unparkVehicle(int id);
    int getCount() const;
    int countOverStayingVehicles(int maxParkingDuration);
};

#endif

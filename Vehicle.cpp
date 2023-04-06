#include "Vehicle.h"
#include <string>
Vehicle::Vehicle(int id) {
    timeOfEntry = std::time(nullptr);
    ID = id;
}

int Vehicle::getID() {
    return ID;
}
std::string Vehicle::getType() {
    return "Vehicle";
}


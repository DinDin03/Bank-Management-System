#include "Car.h"
#include <string>
Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() {
    return 0.9 * std::difftime(std::time(nullptr), timeOfEntry);
}
std::string Car::getType() {
    return "car";
}
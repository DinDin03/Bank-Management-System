#include "Motorbike.h"
#include <string>
Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() {
    return 0.85 * std::difftime(std::time(nullptr), timeOfEntry);
}
std::string Motorbike::getType() {
    return "Motorbike";
}

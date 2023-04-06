#include "Bus.h"
#include <string>
Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() {
    return 0.75 * std::difftime(std::time(nullptr), timeOfEntry);
}
std::string Bus::getType() {
    return "bus";
}

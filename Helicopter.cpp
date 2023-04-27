#include "Helicopter.h"

Helicopter::Helicopter(int w, std::string n) : AirCraft(w), name(n) {}

std::string Helicopter::get_name() const {
    return name;
}

void Helicopter::set_name(std::string n) {
    name = n;
}

void Helicopter::fly(int headwind, int minutes) {
    double fuelUsed;
    if (headwind >= 40) {
        fuelUsed = minutes * (0.4 + (weight - 5670) * 0.0001);
    } else {
        fuelUsed = minutes * (0.2 + (weight - 5670) * 0.0001);
    }
    if ((fuel - fuelUsed) < 0.2) {
        return;
    }
    fuel -= fuelUsed;
    numberOfFlights++;
}

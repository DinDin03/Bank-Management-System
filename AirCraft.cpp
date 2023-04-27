#include "AirCraft.h"

AirCraft::AirCraft() {}

AirCraft::AirCraft(int w) {
    weight = w;
    fuel = 80.0f;
    numberOfFlights = 0;
}

void AirCraft::refuel() {
    fuel = 80.0f;
}

void AirCraft::fly(int headwind, int minutes) {
    float fuelConsumed = (float) (weight + headwind) * (float) minutes / 60.0f / 1000.0f;
    fuel -= fuelConsumed;
    numberOfFlights++;
}

int AirCraft::get_weight() {
    return weight;
}

void AirCraft::set_weight(int w) {
    weight = w;
}

float AirCraft::get_fuel() {
    return fuel;
}

void AirCraft::set_fuel(float f) {
    fuel = f;
}

int AirCraft::get_numberOfFlights() {
    return numberOfFlights;
}

void AirCraft::set_numberOfFlights(int n) {
    numberOfFlights = n;
}

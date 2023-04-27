#include "AirCraft.h"

AirCraft::AirCraft() {}

AirCraft::AirCraft(int w) {
    weight = w;
    fuel = 100.0f;
    numberOfFlights = 0;
}

void AirCraft::refuel() {
    fuel = 100.0f;
}

void AirCraft::fly(int headwind, int minutes) {
    float fuelConsumed = (float) (weight + headwind) * (float) minutes / 60.0f / 1000.0f;
    fuel -= fuelConsumed;
    numberOfFlights++;
}

int AirCraft::get_Weight() {
    return weight;
}

void AirCraft::set_Weight(int w) {
    weight = w;
}

float AirCraft::get_Fuel() {
    return fuel;
}

void AirCraft::set_Fuel(float f) {
    fuel = f;
}

int AirCraft::get_NumberOfFlights() {
    return numberOfFlights;
}

void AirCraft::set_NumberOfFlights(int n) {
    numberOfFlights = n;
}

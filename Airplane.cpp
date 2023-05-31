#include "Airplane.h"

Airplane::Airplane() {
    numPassengers = 0;
}

Airplane::Airplane(int w, int p) {
    weight = w;
    numPassengers = p;
    fuel = 100.0;
    numberOfFlights = 0;
}

void Airplane::reducePassengers(int x) {
    numPassengers -= x;
    if (numPassengers < 0) {
        numPassengers = 0;
    }
}

int Airplane::get_numPassengers() {
    return numPassengers;
}

void Airplane::fly(int headwind, int minutes) {
    float fuelUsed = 0.3 * minutes;
    double initialFuel;
    initialFuel = fuel;
    if (headwind >= 60) {
        fuelUsed = 0.5 * minutes;
    }
    fuelUsed += 0.001 * numPassengers * minutes;
    if (fuel - fuelUsed < 20.0) {
        fuel = initialFuel;
        return;
    }
    else {
        fuel -= fuelUsed;
        numberOfFlights++;
    }
    
}

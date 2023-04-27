#include <iostream>
#include "AirCraft.h"

int main() {
    AirCraft ac(1000);
    std::cout << "Weight: " << ac.get_weight() << std::endl;
    std::cout << "Fuel: " << ac.get_fuel() << std::endl;
    std::cout << "Number of flights: " << ac.get_numberOfFlights() << std::endl;

    ac.fly(50, 60);
    std::cout << "Fuel after flight: " << ac.get_fuel() << std::endl;
    std::cout << "Number of flights after flight: " << ac.get_numberOfFlights() << std::endl;

    ac.refuel();
    std::cout << "Fuel after refueling: " << ac.get_fuel() << std::endl;

    return 0;
}

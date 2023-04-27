#include <iostream>
#include "AirCraft.h"

int main() {
    AirCraft ac(1000);
    std::cout << "Weight: " << ac.get_Weight() << std::endl;
    std::cout << "Fuel: " << ac.get_Fuel() << std::endl;
    std::cout << "Number of flights: " << ac.get_NumberOfFlights() << std::endl;

    ac.fly(50, 60);
    std::cout << "Fuel after flight: " << ac.get_Fuel() << std::endl;
    std::cout << "Number of flights after flight: " << ac.get_NumberOfFlights() << std::endl;

    ac.refuel();
    std::cout << "Fuel after refueling: " << ac.get_Fuel() << std::endl;

    return 0;
}

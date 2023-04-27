#include <iostream>
#include "AirCraft.h"
#include "Helicopter.h"

int main() {
    Helicopter helicopter(6000, "Black Hawk");
    std::cout << "Helicopter created: " << helicopter.get_name() << std::endl;
    std::cout << "Initial fuel level: " << helicopter.get_fuel() << std::endl;
    helicopter.fly(30, 10);
    std::cout << "Fuel level after 10 minute flight with 30 km/h headwind: " << helicopter.get_fuel() << std::endl;
    std::cout << "Number of flights: " << helicopter.get_numberOfFlights() << std::endl;
    return 0;
}

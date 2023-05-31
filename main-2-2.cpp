#include <iostream>
#include "Airplane.h"

int main() {
    Airplane a(10000, 150);
    std::cout << "Initial fuel: " << a.get_fuel() << std::endl;
    std::cout << "Initial number of passengers: " << a.get_numPassengers() << std::endl;

    a.fly(70, 120);
    std::cout << "Fuel after 2 hour flight: " << a.get_fuel() << std::endl;
    std::cout << "Number of flights: " << a.get_numberOfFlights() << std::endl;

    a.reducePassengers(50);
    std::cout << "Passengers after reduction: " << a.get_numPassengers() << std::endl;

    a.fly(50, 180);
    std::cout << "Fuel after 3 hour flight: " << a.get_fuel() << std::endl;
    std::cout << "Number of flights: " << a.get_numberOfFlights() << std::endl;

    a.set_fuel(19);
    a.fly(60, 30);
    std::cout << "Fuel after insufficient flight: " << a.get_fuel() << std::endl;
    std::cout << "Number of flights: " << a.get_numberOfFlights() << std::endl;

    return 0;
}

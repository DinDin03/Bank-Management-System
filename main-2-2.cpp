#include <iostream>
#include "Airplane.h"

int main() {
    // Create an airplane with weight 10000 kg and 150 passengers
    Airplane a(10000, 150);
    std::cout << "Initial fuel: " << a.get_Fuel() << std::endl;
    std::cout << "Initial number of passengers: " << a.get_NumPassengers() << std::endl;

    // Fly for 2 hours into a 70 km/h headwind
    a.fly(70, 120);
    std::cout << "Fuel after 2 hour flight: " << a.get_Fuel() << std::endl;
    std::cout << "Number of flights: " << a.get_NumberOfFlights() << std::endl;

    // Reduce passengers by 50
    a.reducePassengers(50);
    std::cout << "Passengers after reduction: " << a.get_NumPassengers() << std::endl;

    // Fly for 3 hours into a 50 km/h headwind
    a.fly(50, 180);
    std::cout << "Fuel after 3 hour flight: " << a.get_Fuel() << std::endl;
    std::cout << "Number of flights: " << a.get_NumberOfFlights() << std::endl;

    // Try to fly with insufficient fuel
    a.set_Fuel(19);
    a.fly(60, 30);
    std::cout << "Fuel after insufficient flight: " << a.get_Fuel() << std::endl;
    std::cout << "Number of flights: " << a.get_NumberOfFlights() << std::endl;

    return 0;
}

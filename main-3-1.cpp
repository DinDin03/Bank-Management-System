#include <iostream>
#include "House.h"
#include "Fridge.h"
#include "TV.h"

int main() {
    House house(2);
    Fridge fridge(150, 300);
    TV tv(200, 55);

    if (house.addAppliance(&fridge)) {
        std::cout << "Fridge added to the house" << std::endl;
    }
    else {
        std::cout << "House is full" << std::endl;
    }

    if (house.addAppliance(&tv)) {
        std::cout << "TV added to the house" << std::endl;
    }
    else {
        std::cout << "House is full" << std::endl;
    }

    std::cout << "Total power consumption of the house is: " << house.getTotalPowerConsumption() << std::endl;

    return 0;
}

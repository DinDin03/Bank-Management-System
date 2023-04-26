#include <iostream>
#include "TV.h"

int main() {
    TV tv1;
    TV tv2(100, 50.0);

    std::cout << "TV 1 power consumption: " << tv1.getPowerConsumption() << std::endl;
    std::cout << "TV 2 power consumption: " << tv2.getPowerConsumption() << std::endl;

    return 0;
}

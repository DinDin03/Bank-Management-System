#include "House.h"

House::House() {
    numAppliances = 0;
    appliances = nullptr;
}

House::House(int numAppliances) {
    this->numAppliances = numAppliances;
    appliances = new Appliance*[numAppliances];
    for (int i = 0; i < numAppliances; i++) {
        appliances[i] = nullptr;
    }
}

House::~House() {
    for (int i = 0; i < numAppliances; i++) {
        if (appliances[i] != nullptr) {
            delete appliances[i];
        }
    }
    delete[] appliances;
}


bool House::addAppliance(Appliance* appliance) {
    for (int i = 0; i < numAppliances; i++) {
        if (appliances[i] == nullptr) {
            appliances[i] = appliance;
            return true;
        }
    }
    return false;
}

double House::getTotalPowerConsumption() {
    double totalPower = 0.0;
    for (int i = 0; i < numAppliances; i++) {
        if (appliances[i] != nullptr) {
            totalPower += appliances[i]->getPowerConsumption();
        }
    }
    return totalPower;
}

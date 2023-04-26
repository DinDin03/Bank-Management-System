#pragma once
#include "Appliance.h"

class House {
public:
    House();
    House(int numAppliances);
    ~House();

    bool addAppliance(Appliance* appliance);
    double getTotalPowerConsumption();

private:
    Appliance** appliances;
    int numAppliances;
};

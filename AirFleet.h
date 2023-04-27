#ifndef AIRFLEET_H
#define AIRFLEET_H

#include "AirCraft.h"
#include "Airplane.h"
#include "Helicopter.h"

class AirFleet {
public:
    AirFleet();
    AirCraft **get_fleet();

private:
    AirCraft *fleet[5];
};

#endif // AIRFLEET_H

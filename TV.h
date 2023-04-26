#ifndef TV_H
#define TV_H

#include "Appliance.h"

class TV : public Appliance {
public:
    TV();
    TV(int powerRating, double screenSize);

    void setScreenSize(double screenSize);
    double getScreenSize();

    double getPowerConsumption();

private:
    double screenSize; // screen size in inches
};

#endif // TV_H

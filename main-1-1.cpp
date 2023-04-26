#include <iostream>
#include "Appliance.h"

using namespace std;

int main() {
    Appliance appliance1(100);
    cout << "Initial Power Rating: " << appliance1.get_powerRating() << endl;
    cout << "Initial isOn: " << appliance1.get_isOn() << endl;
    cout << "Initial Power Consumption: " << appliance1.getPowerConsumption() << endl;

    appliance1.set_powerRating(50);
    cout << "New Power Rating: " << appliance1.get_powerRating() << endl;

    appliance1.turnOn();
    cout << "isOn after turnOn: " << appliance1.get_isOn() << endl;

    appliance1.turnOff();
    cout << "isOn after turnOff: " << appliance1.get_isOn() << endl;

    return 0;
}

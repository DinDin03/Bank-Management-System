#include <iostream>
#include "AirFleet.h"

using namespace std;

int main() {
    AirFleet myFleet;
    AirCraft **fleet = myFleet.get_fleet();

    for (int i = 0; i < 5; i++) {
        cout << "Aircraft #" << i+1 << endl;
    }
}
       

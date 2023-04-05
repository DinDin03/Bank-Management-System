#include <iostream>
#include <string>
#include <time>
#include "vehicle.h"
using namespace std;

class Car : public Vehicle {
 public:
  int getParkingDuration(int timeOfEntry);
};
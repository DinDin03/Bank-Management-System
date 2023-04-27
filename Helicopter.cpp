#include "Helicopter.h"

#include <iostream>

Helicopter::Helicopter(int w, std::string n) : AirCraft(w), name(n) {}

std::string Helicopter::get_name() const { return name; }

void Helicopter::set_name(std::string n) { name = n; }

void Helicopter::fly(int headwind, int minutes) {
  double fuelUsed;
  if (headwind >= 40) {
    fuelUsed = (minutes * 0.4);
    if (weight > 5670) {
      int dif = weight - 5670;
      fuelUsed += 0.01 * dif * minutes;
    }
  } else {
    fuelUsed = (minutes * 0.2); 
    if (weight > 5670) {
      int dif = weight - 5670;          
      fuelUsed += 0.01 * dif * minutes;  
    }
  }
  if ((fuel - fuelUsed) <= 0.2) {
    fuel = 100.0;
    return;
  }
  else{
    fuel -= fuelUsed;
  }
  numberOfFlights++;
}

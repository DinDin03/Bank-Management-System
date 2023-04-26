#include <iostream>
#include "Fridge.h"
#include "Appliance.h"

int main() {
  Fridge fridge(200, 200);

  std::cout << "Power consumption of fridge: " << fridge.getPowerConsumption() << std::endl;

  return 0;
}

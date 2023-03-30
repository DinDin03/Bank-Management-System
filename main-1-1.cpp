#include <iostream>
#include <string>
#include "Unit.h"
using namespace std;

int main() {
  Unit u1(500000, 3, 156.8);

  cout << "The number of bedrooms is: " << u1.get_num_bedrooms() << endl;
  cout << "The market value of the house is: " << u1.get_value() << endl;
  cout << "The area of the house is: " << u1.get_area() << endl;
  return 0;
}

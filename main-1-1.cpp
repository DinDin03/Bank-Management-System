#include "Unit.h"
#include <iostream>
#include <string>

Unit u1(500000,3,156.8);
int beds = u1.get_num_bedrooms();
int val = u1.get_value();
double Area = u1.get_area();

std::cout << "The number of bedrooms is: " << beds << std::endl;
std::cout << "The market value of the house is: " << val << std::endl;
std::cout << "The area of the house is: " << Area << std::endl;


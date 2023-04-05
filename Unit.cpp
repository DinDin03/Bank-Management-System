#include "Unit.h"
#include <iostream>
#include <string>

Unit::Unit() {
  marketVal = 0;
  numBed = 0;
  area = 0;}
Unit::Unit(int NmarketVal, int NnumBed, double Narea) {
  marketVal = NmarketVal;
  numBed = NnumBed;
  area = Narea;
}
int Unit::get_num_bedrooms() { return numBed; }
int Unit::get_value() { return marketVal; }
double Unit::get_area() { return area; }
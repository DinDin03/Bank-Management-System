#include <string>
#include <iostream>
#ifndef UNIT_H
#define UNIT_H
class Unit{
    private:
        int marketVal;
        double area;
        int numBed;
    public:
        Unit();
        Unit(int NmarketVal, int NnumBed, double Narea);
        int get_num_bedrooms();
        int get_value();
        double get_area();
};
#endif
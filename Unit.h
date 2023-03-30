#include <string>
#include <iostream>

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
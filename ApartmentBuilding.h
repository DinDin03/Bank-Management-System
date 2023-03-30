#include "Unit.h"
#include <string>
#include <iostream>

class Apartment : public Unit{
    public:
        int capacity;
        int nowCap = 0;
        Unit *units;
        Apartment();
        Apartment(int capacity);
        int get_capacity();
        int get_current_number_of_units();
        Unit *get_contents();
        bool add_unit(Unit unit);
        ~Apartment();
};
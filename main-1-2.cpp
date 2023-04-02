#include <iostream>
#include "ApartmentBuilding.h"
#include <string>
#include "Unit.h"
using namespace std;

int main(){
    ApartmentBuilding a1(9);
    Unit u1(500000,10,183.4);

    cout << "The size of the apartment is : " << a1.get_capacity() << endl;
    cout << "Adding an unit" << a1.add_unit(u1) << endl;
    cout << "The size of apartment is: " << a1.get_current_number_of_units() << endl;
    return 0;
}
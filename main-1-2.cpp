#include <iostream>
#include "ApartmentBuilding.h"
#include <string>
using namespace std;

int main(){
    ApartmentBuilding a1(9);

    cout << "The size of the apartment is : " << a1.get_capacity() << endl;
    cout << "Adding an unit" << a1.add_unit(a1) << endl;
    cout << "The size of apartment is: " << a1.get_current_number_of_units() << endl;
    return 0;
}
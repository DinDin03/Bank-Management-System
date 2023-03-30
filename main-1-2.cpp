#include <iostream>
#include "ApartmentBuilding.h"
#include <string>
using namespace std;

int main(){
    Apartment a1(9);

    cout << "The size of the apartment is : " << a1.get_capacity() << endl;
    return 0;
}
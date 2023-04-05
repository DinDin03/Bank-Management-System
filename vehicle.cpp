#include <string>
#include <time>
#include <iostream>
#include "vehicle.h"
using namespace std;

Vehicle::Vehicle(int ID){
    this->ID = ID;
}
void Vehicle::setID(int ID){
    this->ID = ID;
}
int Vehicle::getID(){
    return ID;
}

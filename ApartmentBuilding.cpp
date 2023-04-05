#include "ApartmentBuilding.h"
#include "Unit.h"
#include <string>
#include <iostream>

ApartmentBuilding::ApartmentBuilding(){
    units = new Unit[10];
}
ApartmentBuilding::ApartmentBuilding(int capacity){
    units = new Unit[capacity];
}
int ApartmentBuilding::get_capacity(){
    return capacity;
}
int ApartmentBuilding::get_current_number_of_units(){
    return nowCap;
}
Unit ApartmentBuilding::*get_contents(Unit *units){
    return units;
}
bool ApartmentBuilding::add_unit(Unit new_unit){
    if(nowCap < capacity){
        units[nowCap] = new_unit;
        nowCap++;
        return true;
    }
    else
    return false;
} 
ApartmentBuilding::~ApartmentBuilding(){
    delete[] units;
}
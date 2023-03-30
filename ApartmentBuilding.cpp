#include "ApartmentBuilding.h"
#include <string>
#include <iostream>

Apartment::Apartment(){
    int capacity = 10;
    int nowCap = 0;
    units = new Unit[10];
}
Apartment::Apartment(int capacity){
    int nowCap = 0;
    units = new Unit[capacity];
}
int Apartment::get_capacity(){
    return capacity;
}
int Apartment::get_current_number_of_units(){
    return nowCap;
}
Unit *get_contents(Unit *units){
    return units;
}
bool Apartment::add_unit(Unit new_unit){
    if(nowCap < capacity){
        units[nowCap] = new_unit;
        nowCap++;
        return true;
    }
    else
    return false;
} 
Apartment::~Apartment(){
    delete[] units;
}
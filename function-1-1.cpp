#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

Person* createPersonArray(int n){
    Person* array = new Person[n];
    return array;

}


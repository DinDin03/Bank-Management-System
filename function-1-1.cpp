#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

Person* createPersonArray(int n){
    Person* array = new Person[n];
    for(int i = 0; i < n; i++){
        array[i].name = "John Doe";
        array[i].age = 0;
    }
    return array;
}

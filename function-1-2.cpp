#include <iostream>
#include <string>
#include "Person.h"
using namespace std;



PersonList createPersonList(int n){
    PersonList pList;
    pList.numPeople = n;
    Person* array = new Person[pList.numPeople];
    pList.people = array;
    for(int i = 0; i < n; i++){
        array[i].name = "Jane Doe";
        array[i].age = 1;
    }
    return pList;
}

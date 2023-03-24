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
        array[i].name = "John doe";
        array[i].age = 0;
    }
    return pList;
}

PersonList shallowCopyPersonList(PersonList pl){
    Person* newarray = new Person[pl.numPeople];
    pl.people = newarray;
    for(int i = 0; i < pl.numPeople; i++){
        newarray[i].name = "John Doe";
        newarray[i].age = 0;
    }
    return pl;
}
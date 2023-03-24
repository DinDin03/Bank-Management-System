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

PersonList deepCopyPersonList(PersonList pl){
    PersonList pList;
    pList.numPeople = pl.numPeople;
    Person* newarray = new Person[pl.numPeople];
    Person* oldArray;
    pList.people = newarray;
    pl.people = oldArray;
    for(int i = 0; i < pl.numPeople; i++){
        newarray[i].name = oldArray[i].name;
        newarray[i].age = oldArray[i].age;
    }
    return pList;
}
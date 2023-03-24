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

PersonList shallowCopyPersonList(PersonList pl){
    PersonList pList2;
    pList2.numPeople = pl.numPeople;
    Person* newarray = new Person[pList2.numPeople];
    Person* oldArray;
    pList2.people = newarray;
    oldArray = pl.people;
    for(int i = 0; i < pl.numPeople; i++){
        newarray[i].name = oldArray[i].name;
        newarray[i].age = oldArray[i].age;
    }
    return pList2;
}
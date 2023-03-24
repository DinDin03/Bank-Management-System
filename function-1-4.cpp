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

PersonList shallowCopyPersonList(PersonList pList){
    PersonList pList2;
    pList2.numPeople = pList.numPeople;
    Person* oldArray;
    oldArray = pList.people;
    pList2.people = oldArray;
    return pList2;
}
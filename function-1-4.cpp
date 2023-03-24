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
    Person* newarray = new Person[pList.numPeople];
    Person* oldArray;
    pList.people = newarray;
    oldArray = pList.people;
    for(int i = 0; i < pList.numPeople; i++){
        newarray[i].name = oldArray[i].name;
        newarray[i].age = oldArray[i].age;
    }
    return pList;
}
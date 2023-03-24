#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

extern PersonList deepCopyPersonList(PersonList);
extern PersonList createPersonList(int);

int main(){

    PersonList pList = createPersonList(5);
    deepCopyPersonList(pList);
    return 0;
}
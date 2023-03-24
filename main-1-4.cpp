#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

extern PersonList shallowCopyPersonList(PersonList);
extern PersonList createPersonList(int);

int main(){

    PersonList pList = createPersonList(5);
    shallowCopyPersonList(pList);
    return 0;
}
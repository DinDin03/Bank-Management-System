#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

extern Person createPersonArray(int);

int main(){

    Person p1;
    p1.name = "John Doe";
    p1.age = 0;
    createPersonArray(5);
    return 0;
}
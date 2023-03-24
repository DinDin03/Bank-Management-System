#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

extern Person* createPersonArray(int);

int main(){

    createPersonArray(5);
    return 0;
}
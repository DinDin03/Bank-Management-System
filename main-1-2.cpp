#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

extern PersonList createPersonList(int);

int main(){

    createPersonList(5);
    return 0;
}
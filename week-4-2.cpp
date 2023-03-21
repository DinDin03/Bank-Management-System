#include <iostream>
#include <string>
#include "student.h"
using namespace std;

Student* Factory(){
    Student* k = new Student();
    return k;
}

int main(){

    Student *p = Factory();
    p -> setGrade(55.5);

    cout << p->getName() << endl;
    cout << p->getGrade() << endl;

    return 0; 

}
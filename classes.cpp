#include <string>
#include <iostream>
using namespace std;

class TestName{
    public:
        string myName;
        int myAge;
        string id;
        void printid();
        void printDetails(){
            cout << "My name is " << myName << " and my age is " << myAge << endl;
        }
    private:
        int myExperience = 15;
};
void TestName::printid(){
    cout << "My ID number is : " << id << endl;
}
int main(){
    TestName t1;
    t1.myAge = 15;
    t1.myName = "Dineth";
    t1.id = "a1868070";
    // t1.myExperience = 18; not allowed - private 
    t1.printDetails();
    t1.printid();
    return 0;
}
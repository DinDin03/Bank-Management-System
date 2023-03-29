#include <string>
#include <iostream>
using namespace std;

class TestName{
    public:
        string id;
        TestName(){
            cout << "Default constructer called" << endl;
            id = "-1";
        }
        TestName(string s_id){
            cout << "Parameterized constructer called" << endl;
            id = s_id;
        }
        ~TestName(){
            cout << "destructer called for ID: " << id << endl;
        }
};
int main(){
    TestName t1;
    cout << "My ID is : " << t1.id << endl;
    TestName t2("a1868070");
    cout << "My ID is : " << t2.id << endl;
    return 0;
}
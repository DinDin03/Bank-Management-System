#include <iostream>
#include <string>
using namespace std;

class Student {
 private:
  string name;
  int ID;
  double grade;

 public:
 Student(string s_name, int s_ID, double s_grade){
    name = s_name;
    ID = s_ID;
    grade = s_grade;
 }
  string getName() { return name; }
  int getID() { return ID; }
  double getGrade() { return grade; }

  void setName(string newName){
    name = newName;
  }
  void setGrade(double newGrade){
    grade = newGrade;
  }
  string is_pass();
};

string Student::is_pass(){
    if(grade < 50){
        return "Fail";
    }
    else
        return "Pass";
}

int main(){
    Student s1("Ferras",1868070,40);

    cout << s1.getName() << endl;
    cout << s1.getID() << endl;
    cout << s1.getGrade() << endl;
    cout << s1.is_pass() << endl;

    return 0;

}
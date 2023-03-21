#include <iostream>
#include <string>
using namespace std;

class Student {
 private:
  string name;
  int ID;
  double grade;

 public:
  Student(string s_name, int s_ID, double s_grade);
  Student(string s_name, int s_ID);

  string getName() { return name; }
  int getID() { return ID; }
  double getGrade() { return grade; }

  void setName(string newName) { name = newName; }
  void setGrade(double newGrade) { grade = newGrade; }
  string is_pass();
};

Student::Student(string s_name, int s_ID, double s_grade) {
  name = s_name;
  ID = s_ID;
  grade = s_grade;
}

Student::Student(string s_name, int s_ID) {
  name = s_name;
  ID = s_ID;
  grade = 0;
}

string Student::is_pass() {
  if (grade < 50) {
    return "Fail";
  } else
    return "Pass";
}

int main() {
  Student s1("Ferras", 1868070, 40);
  Student s2("Adam", 18789034);

  cout << s1.getName() << endl;
  cout << s1.getID() << endl;
  cout << s1.getGrade() << endl;
  cout << s1.is_pass() << endl;

  return 0;
}
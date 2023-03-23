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
  Student(); 
  ~Student();

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

Student::Student(): Student("Placeholder",0,0.0){
    cout << "A student object was created" << endl;
}

Student::~Student(){
  cout << "A student object was deleted" << endl;
}

string Student::is_pass() {
  if (grade < 50) {
    return "Fail";
  } else
    return "Pass";
}
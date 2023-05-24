#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <fstream>
#include <string>

#include "User.h"
using namespace std;

class Employee : public User {
 protected:
  string id;
  string department;

 public:
  Employee();
  Employee(string name, string id, string department, string email,
           string phone);
  string getEmployeeID() const;
  string getDepartment() const;

  void setDepartment(string department);
  void setID(string employeeID);
  bool checkEmployeeDetails(string name, string id);
  void saveEmployeeInfo(string filename);
  void loadUserInfo(string filename) override;
  bool employeeLogin(string name, string phone);
};

#endif  // EMPLOYEE_H

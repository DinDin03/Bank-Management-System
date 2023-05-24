#ifndef MANAGER_H
#define MANAGER_H
#include <fstream>
#include <string>

#include "Employee.h"
using namespace std;

class Manager : public Employee {
 public:
  Manager();
  Manager(string name, string id, string department, string email,
          string phone);
  bool managerLogin(string name, string id);
  bool checkManagerDetails(string name, string id);
};

#endif  // MANAGER_H

#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <fstream>
#include "Employee.h"

class Manager : public Employee {
public:
    Manager();
    Manager(std::string name, std::string id, std::string department, std::string email, std::string phone);
    bool managerLogin(std::string name, std::string id);
};

#endif // MANAGER_H

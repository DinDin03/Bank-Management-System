#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <fstream>
#include "User.h"

class Employee :public User {
protected:
    std::string id;
    std::string department;

public:
    Employee();
    Employee(std::string name, std::string id, std::string department, std::string email, std::string phone);
    std::string getEmployeeID() const;
    std::string getDepartment() const;

    void setDepartment(std::string department);
    void setID(std::string employeeID);

    void saveEmployeeInfo(std::string filename);
    void loadEmployeeInfo(std::string filename);
    bool employeeLogin(std::string name, std::string phone);
};

#endif // EMPLOYEE_H

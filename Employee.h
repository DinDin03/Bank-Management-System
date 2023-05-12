#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Bank.h"

class Employee {
private:
    std::string employeeName;
    int employeeID;
    std::string employeeDepartment;
    std::string employeeEmail;
    std::string employeePhone;
public:
    Employee(std::string name, int id, std::string department, std::string email, std::string phone);
    void createCustomer(Bank& bank, std::string name, std::string address, std::string phone, std::string email);
    std::string getEmployeeName() const;
    int getEmployeeID() const;
    std::string getDepartment() const;
    std::string getEmail() const;
    std::string getPhone() const;
};

#endif //EMPLOYEE_H

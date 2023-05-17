#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <fstream>

class Employee {
private:
    std::string employeeName;
    std::string employeeID;
    std::string employeeDepartment;
    std::string employeeEmail;
    std::string employeePhone;

public:
    Employee(std::string employeeName, std::string employeeID, std::string employeeDepartment, std::string employeeEmail, std::string employeePhone);
    std::string getEmployeeName() const;
    std::string getEmployeeID() const;
    std::string getDepartment() const;
    std::string getEmail() const;
    std::string getPhone() const;

    void setName(std::string name);
    void setEmail(std::string email);
    void setDepartment(std::string department);
    void setPhone(std::string phone);
    void setID(std::string employeeID);

    void saveEmployeeInfo(std::string filename);
    void loadEmployeeInfo(std::string filename);
    bool employeeLogin(std::string name, std::string phone);
};

#endif // EMPLOYEE_H

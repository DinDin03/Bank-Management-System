#include "Employee.h"

Employee::Employee(std::string name, int id, std::string department, std::string email, std::string phone)
    : employeeName(name), employeeID(id), employeeDepartment(department), employeeEmail(email), employeePhone(phone)
{}

void Employee::createCustomer(Bank& bank, std::string name, std::string address, std::string phone, std::string email) {
    Customer newCustomer(name, address, phone, email);
    bank.addCustomer(newCustomer);
}

std::string Employee::getEmployeeName() const {
    return employeeName;
}

int Employee::getEmployeeID() const {
    return employeeID;
}

std::string Employee::getDepartment() const {
    return employeeDepartment;
}

std::string Employee::getEmail() const {
    return employeeEmail;
}

std::string Employee::getPhone() const {
    return employeePhone;
}

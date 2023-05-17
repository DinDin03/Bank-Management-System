#include "Employee.h"

Employee::Employee(std::string name, std::string id, std::string department, std::string email, std::string phone)
    : employeeName(name), employeeID(id), employeeDepartment(department), employeeEmail(email), employeePhone(phone)
{
}

std::string Employee::getEmployeeName() const {
    return employeeName;
}

std::string Employee::getEmployeeID() const {
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

void Employee::setName(std::string name) {
    employeeName = name;
}

void Employee::setEmail(std::string email) {
    employeeEmail = email;
}

void Employee::setDepartment(std::string department) {
    employeeDepartment = department;
}

void Employee::setPhone(std::string phone) {
    employeePhone = phone;
}
void Employee::setID(std::string id){
    employeeID = id;
}
void Employee::saveEmployeeInfo(std::string filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << employeeName << std::endl;
        outFile << employeeID << std::endl;
        outFile << employeeDepartment << std::endl;
        outFile << employeeEmail << std::endl;
        outFile << employeePhone << std::endl;
        outFile.close();
    }
}

void Employee::loadEmployeeInfo(std::string filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::getline(inFile, employeeName);
        inFile >> employeeID;
        inFile.ignore(); // Ignore the newline character
        std::getline(inFile, employeeDepartment);
        std::getline(inFile, employeeEmail);
        std::getline(inFile, employeePhone);
        inFile.close();
    }
}

bool Employee::employeeLogin(std::string name, std::string phone) {
    std::ifstream inFile(name + ".txt");
    if (inFile.is_open()) {
        std::string empName;
        int empID;
        std::string empDepartment;
        std::string empEmail;
        std::string empPhone;
        std::getline(inFile, empName);
        inFile >> empID;
        inFile.ignore(); // Ignore the newline character
        std::getline(inFile, empDepartment);
        std::getline(inFile, empEmail);
        std::getline(inFile, empPhone);
        inFile.close();
        if (empPhone == phone) {
            return true;
        }
    }
    return false;
}

#include "Employee.h"

Employee::Employee() : User("","","") {}

Employee::Employee(std::string name, std::string id, std::string department, std::string email, std::string phone)
    : User(name,phone,email), id(id), department(department) {}

std::string Employee::getEmployeeID() const {
    return id;
}

std::string Employee::getDepartment() const {
    return department;
}

void Employee::setDepartment(std::string department) {
    this->department = department;
}

void Employee::setID(std::string id){
    this->id = id;
}
void Employee::saveEmployeeInfo(std::string filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << User::getName() << std::endl;
        outFile << id << std::endl;
        outFile << department << std::endl;
        outFile << User::getEmail() << std::endl;
        outFile << User::getPhone() << std::endl;
        outFile.close();
    }
}

void Employee::loadEmployeeInfo(std::string filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::getline(inFile, name);
        inFile >> id;
        inFile.ignore(); // Ignore the newline character
        std::getline(inFile, department);
        std::getline(inFile, email);
        std::getline(inFile, phone);
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

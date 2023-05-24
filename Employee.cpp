#include "Employee.h"
#include <iostream>

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

void Employee::loadUserInfo(std::string filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::getline(inFile, name);
        std::cout << "New Employee's name: "<< name << std::endl;
        inFile >> id;
        std::cout << "New Employee's ID: " << id << std::endl;
        inFile.ignore(); // Ignore the newline character
        std::getline(inFile, department);
        std::cout << "New Employee's Department: " << department << std::endl;
        std::getline(inFile, email);
        std::cout << "New Employee's Email: " << email << std::endl;
        std::getline(inFile, phone);
        std::cout << "New Employee's Phone: " << phone << std::endl;
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
bool Employee::checkEmployeeDetails(std::string name, std::string id) {
    std::ifstream inFile(name + ".txt");
    if (inFile.is_open()) {
        std::string empName;
        std::string empID;
        std::string department;
        std::string email;
        std::string phone;
        std::getline(inFile, empName);
        std::getline(inFile, empID);
        std::getline(inFile, department);
        std::getline(inFile, email);
        std::getline(inFile, phone);
        inFile.close();

        return (empName == name && empID == id);
    }
    
    return false;
}

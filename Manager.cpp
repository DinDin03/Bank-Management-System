#include "Manager.h"

Manager::Manager() : Employee() {}

Manager::Manager(std::string name, std::string id, std::string department, std::string email, std::string phone)
    : Employee(name, id, department, email, phone) {}

bool Manager::managerLogin(std::string name, std::string id) {
    std::ifstream inFile(name + ".txt");
    if (inFile.is_open()) {
        std::string empName;
        std::string empID;
        std::string empDepartment;
        std::string empEmail;
        std::string empPhone;
        std::getline(inFile, empName);
        std::getline(inFile, empID);
        std::getline(inFile, empDepartment);
        std::getline(inFile, empEmail);
        std::getline(inFile, empPhone);
        inFile.close();
        if (empID == id && empName == name) {
            return true;
        }
    }
    return false;
}
bool Manager::checkManagerDetails(std::string name, std::string id) {
    std::ifstream inFile(name + ".txt");
    if (inFile.is_open()) {
        std::string mgrName;
        std::string mgrID;
        std::string department;
        std::string email;
        std::string phone;
        std::getline(inFile, mgrName);
        std::getline(inFile, mgrID);
        std::getline(inFile, department);
        std::getline(inFile, email);
        std::getline(inFile, phone);
        inFile.close();

        return (mgrName == name && mgrID == id);
    }
    
    return false;
}

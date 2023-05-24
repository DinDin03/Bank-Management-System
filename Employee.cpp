#include "Employee.h"

#include <iostream>
using namespace std;

Employee::Employee() : User("", "", "") {}

Employee::Employee(string name, string id, string department, string email,
                   string phone)
    : User(name, phone, email), id(id), department(department) {}

string Employee::getEmployeeID() const { return id; }

string Employee::getDepartment() const { return department; }

void Employee::setDepartment(string department) {
  this->department = department;
}

void Employee::setID(string id) { this->id = id; }
void Employee::saveEmployeeInfo(string filename) {
  ofstream outFile(filename);
  if (outFile.is_open()) {
    outFile << User::getName() << endl;
    outFile << id << endl;
    outFile << department << endl;
    outFile << User::getEmail() << endl;
    outFile << User::getPhone() << endl;
    outFile.close();
  }
}

void Employee::loadUserInfo(string filename) {
  ifstream inFile(filename);
  if (inFile.is_open()) {
    getline(inFile, name);
    cout << "New Employee's name: " << name << endl;
    inFile >> id;
    cout << "New Employee's ID: " << id << endl;
    inFile.ignore();  // Ignore the newline character
    getline(inFile, department);
    cout << "New Employee's Department: " << department << endl;
    getline(inFile, email);
    cout << "New Employee's Email: " << email << endl;
    getline(inFile, phone);
    cout << "New Employee's Phone: " << phone << endl;
    inFile.close();
  }
}

bool Employee::employeeLogin(string name, string phone) {
  ifstream inFile(name + ".txt");
  if (inFile.is_open()) {
    string empName;
    int empID;
    string empDepartment;
    string empEmail;
    string empPhone;
    getline(inFile, empName);
    inFile >> empID;
    inFile.ignore();  // Ignore the newline character
    getline(inFile, empDepartment);
    getline(inFile, empEmail);
    getline(inFile, empPhone);
    inFile.close();
    if (empPhone == phone) {
      return true;
    }
  }
  return false;
}
bool Employee::checkEmployeeDetails(string name, string id) {
  ifstream inFile(name + ".txt");
  if (inFile.is_open()) {
    string empName;
    string empID;
    string department;
    string email;
    string phone;
    getline(inFile, empName);
    getline(inFile, empID);
    getline(inFile, department);
    getline(inFile, email);
    getline(inFile, phone);
    inFile.close();

    return (empName == name && empID == id);
  }

  return false;
}

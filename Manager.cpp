#include "Manager.h"
using namespace std;

Manager::Manager() : Employee() {}

Manager::Manager(string name, string id, string department, string email,
                 string phone)
    : Employee(name, id, department, email, phone) {}

bool Manager::managerLogin(string name, string id) {
  ifstream inFile(name + ".txt");
  if (inFile.is_open()) {
    string empName;
    string empID;
    string empDepartment;
    string empEmail;
    string empPhone;
    getline(inFile, empName);
    getline(inFile, empID);
    getline(inFile, empDepartment);
    getline(inFile, empEmail);
    getline(inFile, empPhone);
    inFile.close();
    if (empID == id && empName == name) {
      return true;
    }
  }
  return false;
}
bool Manager::checkManagerDetails(string name, string id) {
  ifstream inFile(name + ".txt");
  if (inFile.is_open()) {
    string mgrName;
    string mgrID;
    string department;
    string email;
    string phone;
    getline(inFile, mgrName);
    getline(inFile, mgrID);
    getline(inFile, department);
    getline(inFile, email);
    getline(inFile, phone);
    inFile.close();

    return (mgrName == name && mgrID == id);
  }

  return false;
}

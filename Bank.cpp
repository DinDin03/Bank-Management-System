#include "Bank.h"

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

Bank::Bank(const string& bankName, const string& bankAddress,
           const string& bankPhone, const string& bankEmail,
           const string& customerListFilename,
           const string& employeeListFilename,
           const string& managerListFilename)
    : bankName(bankName),
      bankAddress(bankAddress),
      bankPhone(bankPhone),
      bankEmail(bankEmail),
      customerListFilename(customerListFilename),
      employeeListFilename(employeeListFilename),
      managerListFilename(managerListFilename) {
  loadCustomerList("customerList.txt");
  loadEmployeeList("employeeList.txt");
  loadManagerList("managerList.txt");
}

Bank::~Bank() {}

void Bank::addCustomer(Customer* newCustomer) { customer = newCustomer; }

void Bank::removeCustomer(Customer* customer) {
  string customerName = customer->User::getName();

  string customerListFilename = "customerList.txt";
  ifstream fileIn(customerListFilename);
  if (fileIn.is_open()) {
    vector<string> customerNames;
    string line;
    while (getline(fileIn, line)) {
      if (line != customerName) {
        customerNames.push_back(line);
      }
    }
    fileIn.close();

    ofstream fileOut(
        customerListFilename,
        ios::trunc);  // Open the file in truncate mode to clear its contents
    if (fileOut.is_open()) {
      for (const string& name : customerNames) {
        fileOut << name << endl;
      }
      fileOut.close();
    } else {
      cout << "Error: Failed to update customerList.txt" << endl;
    }
  } else {
    cout << "Error: Failed to open customerList.txt" << endl;
  }
}
void Bank::addEmployee(Employee* newEmployee) { employee = newEmployee; }

void Bank::removeEmployee(Employee* employee) {
  string employeeName = employee->User::getName();

  string employeeListFilename = "employeeList.txt";
  ifstream fileIn(employeeListFilename);
  if (fileIn.is_open()) {
    vector<string> employeeNames;
    string line;
    while (getline(fileIn, line)) {
      if (line != employeeName) {
        employeeNames.push_back(line);
      }
    }
    fileIn.close();

    ofstream fileOut(
        employeeListFilename,
        ios::trunc);  // Open the file in truncate mode to clear its contents
    if (fileOut.is_open()) {
      for (const string& name : employeeNames) {
        fileOut << name << endl;
      }
      fileOut.close();
    } else {
      cout << "Error: Failed to update customerList.txt" << endl;
    }
  } else {
    cout << "Error: Failed to open customerList.txt" << endl;
  }
}

void Bank::addManager(Manager* newManager) { manager = newManager; }

void Bank::removeManager(Manager* manager) {
  string managerName = manager->User::getName();

  string managerListFilename = "managerList.txt";
  ifstream fileIn(managerListFilename);
  if (fileIn.is_open()) {
    vector<string> managerNames;
    string line;
    while (getline(fileIn, line)) {
      if (line != managerName) {
        managerNames.push_back(line);
      }
    }
    fileIn.close();

    ofstream fileOut(
        managerListFilename,
        ios::trunc);  // Open the file in truncate mode to clear its contents
    if (fileOut.is_open()) {
      for (const string& name : managerNames) {
        fileOut << name << endl;
      }
      fileOut.close();
    } else {
      cout << "Error: Failed to update customerList.txt" << endl;
    }
  } else {
    cout << "Error: Failed to open customerList.txt" << endl;
  }
}

string Bank::getBankName() const { return bankName; }

string Bank::getBankAddress() const { return bankAddress; }

string Bank::getBankPhone() const { return bankPhone; }

string Bank::getBankEmail() const { return bankEmail; }

void Bank::saveCustomerList(const string& customerListFilename) const {
  ofstream file(customerListFilename, ofstream::app);
  if (file.is_open()) {
    if (customer != nullptr) {
      file << customer->User::getName() << endl;
    }
    file.close();
  } else {
    cout << "Unable to save customer list. File could not be opened." << endl;
  }
}

void Bank::loadCustomerList(string customerListFilename) {
  ifstream file(customerListFilename);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      stringstream iss(line);
      string name, address, phone, email;
    }
    file.close();
  }
}
void Bank::saveEmployeeList(const string& employeeListFilename) const {
  ofstream file(employeeListFilename, ios::app);
  if (file.is_open()) {
    if (employee != nullptr) {
      file << employee->User::getName() << endl;
    }
    file.close();
  } else {
    cout << "Unable to save employee list. File could not be opened." << endl;
  }
}

void Bank::loadEmployeeList(string employeeListFilename) {
  ifstream file(employeeListFilename);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      stringstream iss(line);
      string name, phone, email, id, department;
    }
    file.close();
  }
}
void Bank::saveManagerList(const string& managerListFilename) const {
  ofstream file(managerListFilename, ios::app);
  if (file.is_open()) {
    if (manager != nullptr) {
      file << manager->User::getName() << endl;
    }
    file.close();
  } else {
    cout << "Unable to save employee list. File could not be opened." << endl;
  }
}

void Bank::loadManagerList(string managerListFilename) {
  ifstream file(managerListFilename);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      stringstream iss(line);
      string name, phone, email, id, department;
    }
    file.close();
  }
}
void Bank::displayBankInformation(const Bank& bank) {
  cout << "Bank Name: " << bank.getBankName() << endl;
  cout << "Bank Address: " << bank.getBankAddress() << endl;
  cout << "Bank Phone: " << bank.getBankPhone() << endl;
  cout << "Bank Email: " << bank.getBankEmail() << endl;
}

void Bank::displayCustomerList(const Bank& bank) {
  cout << "Customers:" << endl;

  ifstream file(customerListFilename);
  if (file.is_open()) {
    string customerName;
    while (getline(file, customerName)) {
      cout << " - " << customerName << endl;
    }
    file.close();
  } else {
    cout << "Unable to open customer list file." << endl;
  }
}

void Bank::displayEmployeeList(const Bank& bank) {
  cout << "Employees:" << endl;

  ifstream file(employeeListFilename);
  if (file.is_open()) {
    string employeeName;
    while (getline(file, employeeName)) {
      cout << " - " << employeeName << endl;
    }
    file.close();
  } else {
    cout << "Unable to open employees list file." << endl;
  }
}

void Bank::displayManagerList(const Bank& bank) {
  cout << "Managers:" << endl;

  ifstream file(managerListFilename);
  if (file.is_open()) {
    string managerName;
    while (getline(file, managerName)) {
      cout << " - " << managerName << endl;
    }
    file.close();
  } else {
    cout << "Unable to open employees list file." << endl;
  }
}

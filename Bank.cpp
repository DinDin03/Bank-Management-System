#include "Bank.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

Bank::Bank(const std::string& bankName, const std::string& bankAddress,
           const std::string& bankPhone, const std::string& bankEmail,
           const std::string& customerListFilename,
           const std::string& employeeListFilename)
    : bankName(bankName),
      bankAddress(bankAddress),
      bankPhone(bankPhone),
      bankEmail(bankEmail),
      customerListFilename(customerListFilename),
      employeeListFilename(employeeListFilename) {
  loadCustomerList("customerList.txt");
  loadEmployeeList("employeeList.txt");
}

Bank::~Bank() {}

void Bank::addCustomer(Customer* newCustomer) { customer = newCustomer; }

void Bank::removeCustomer(Customer* customer) {
  string customerName = customer->getName();

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
  void Bank::addEmployee(Employee * newEmployee) { employee = newEmployee; }

  void Bank::removeEmployee(Employee * employee) {
    delete employee;
    employee = nullptr;
  }

  std::string Bank::getBankName() const { return bankName; }

  std::string Bank::getBankAddress() const { return bankAddress; }

  std::string Bank::getBankPhone() const { return bankPhone; }

  std::string Bank::getBankEmail() const { return bankEmail; }

  void Bank::saveCustomerList(const std::string& customerListFilename) const {
    std::ofstream file(customerListFilename, std::ofstream::app);
    if (file.is_open()) {
      if (customer != nullptr) {
        file << customer->User::getName() << std::endl;
      }
      file.close();
    } else {
      std::cout << "Unable to save customer list. File could not be opened."
                << std::endl;
    }
  }

  void Bank::loadCustomerList(std::string customerListFilename) {
    std::ifstream file(customerListFilename);
    if (file.is_open()) {
      std::string line;
      while (std::getline(file, line)) {
        std::stringstream iss(line);
        std::string name, address, phone, email;
        if (std::getline(iss, name, ',') && std::getline(iss, address, ',') &&
            std::getline(iss, phone, ',') && std::getline(iss, email)) {
          Customer* customer = new Customer(name, address, phone, email);
          Customer* newCustomer = customer;
        }
      }
      file.close();
    }
  }
  void Bank::saveEmployeeList(const std::string& employeeListFilename) const {
    std::ofstream file(employeeListFilename, std::ios::app);
    if (file.is_open()) {
      if (employee != nullptr) {
        file << employee->User::getName() << std::endl;
      }
      file.close();
    } else {
      std::cout << "Unable to save employee list. File could not be opened."
                << std::endl;
    }
  }

  void Bank::loadEmployeeList(std::string employeeListFilename) {
    std::ifstream file(employeeListFilename);
    if (file.is_open()) {
      std::string line;
      while (std::getline(file, line)) {
        std::stringstream iss(line);
        std::string name, phone, email, id, department;
        if (std::getline(iss, name, ',') && std::getline(iss, id, ',') &&
            std::getline(iss, phone, ',') && std::getline(iss, email) &&
            std::getline(iss, department)) {
          Employee* employee = new Employee(name, id, department, email, phone);
          Employee* newEmployee = employee;
        }
      }
      file.close();
    }
  }
  void Bank::displayBankInformation(const Bank& bank) {
    std::cout << "Bank Name: " << bank.getBankName() << std::endl;
    std::cout << "Bank Address: " << bank.getBankAddress() << std::endl;
    std::cout << "Bank Phone: " << bank.getBankPhone() << std::endl;
    std::cout << "Bank Email: " << bank.getBankEmail() << std::endl;
  }

  void Bank::displayCustomerList(const Bank& bank) {
    std::cout << "Customers:" << std::endl;

    std::ifstream file(customerListFilename);
    if (file.is_open()) {
      std::string customerName;
      while (std::getline(file, customerName)) {
        std::cout << " - " << customerName << std::endl;
      }
      file.close();
    } else {
      std::cout << "Unable to open customer list file." << std::endl;
    }
  }

  void Bank::displayEmployeeList(const Bank& bank) {
    std::cout << "Employees:" << std::endl;

    std::ifstream file(employeeListFilename);
    if (file.is_open()) {
      std::string employeeName;
      while (std::getline(file, employeeName)) {
        std::cout << " - " << employeeName << std::endl;
      }
      file.close();
    } else {
      std::cout << "Unable to open employees list file." << std::endl;
    }
  }

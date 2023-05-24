#ifndef BANK_H
#define BANK_H

#include <fstream>
#include <iostream>
#include <vector>

#include "Customer.h"
#include "Employee.h"
#include "Manager.h"

// Import the entire std namespace
using namespace std;

class Bank {
 protected:
  string bankName;
  string bankAddress;
  string bankPhone;
  string bankEmail;
  Customer* customer;
  Employee* employee;
  Manager* manager;
  string customerListFilename;
  string employeeListFilename;
  string managerListFilename;

 public:
  // Constructor
  Bank(const string& bankName, const string& bankAddress,
       const string& bankPhone, const string& bankEmail,
       const string& customerListFilename, const string& employeeListFilename,
       const string& managerListFilename);

  // Destructor
  ~Bank();

  // Method to add a customer to the bank
  void addCustomer(Customer* customer);

  // Method to remove a customer from the bank
  void removeCustomer(Customer* customer);

  // Method to add an employee to the bank
  void addEmployee(Employee* employee);

  // Method to remove an employee from the bank
  void removeEmployee(Employee* employee);

  // Method to add a manager to the bank
  void addManager(Manager* manager);

  // Method to remove a manager from the bank
  void removeManager(Manager* manager);

  // Getter method for the bank name
  string getBankName() const;

  // Getter method for the bank address
  string getBankAddress() const;

  // Getter method for the bank phone number
  string getBankPhone() const;

  // Getter method for the bank email address
  string getBankEmail() const;

  // Method to save the customer list to a file
  void saveCustomerList(const string& customerListFilename) const;

  // Method to load the customer list from a file
  void loadCustomerList(string customerListFilename);

  // Method to save the employee list to a file
  void saveEmployeeList(const string& employeeListFilename) const;

  // Method to load the employee list from a file
  void loadEmployeeList(string employeeListFilename);

  // Method to save the manager list to a file
  void saveManagerList(const string& managerListFilename) const;

  // Method to load the manager list from a file
  void loadManagerList(string managerListFilename);

  // Method to display the bank's information
  void displayBankInformation(const Bank& bank);

  // Method to display the customer list
  void displayCustomerList(const Bank& bank);

  // Method to display the employee list
  void displayEmployeeList(const Bank& bank);

  // Method to display the manager list
  void displayManagerList(const Bank& bank);
};

#endif

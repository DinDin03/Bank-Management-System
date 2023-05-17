#ifndef BANK_H
#define BANK_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Customer.h"
#include "Employee.h"

class Bank {
 private:
  std::string bankName;
  std::string bankAddress;
  std::string bankPhone;
  std::string bankEmail;
  std::vector<Customer*> customers;
  std::vector<Employee*> employees; 
  std::string customerListFilename;  // Filename for customer list
  std::string employeeListFilename;

 public:
  Bank(const std::string& bankName, const std::string& bankAddress,
       const std::string& bankPhone, const std::string& bankEmail,
       const std::string& customerListFilename,
       const std::string& employeeListFilename);
  ~Bank();
  void addCustomer(Customer* customer);
  void removeCustomer(Customer* customer);
  void addEmployee(Employee* employee);
  void removeEmployee(Employee* employee);
  std::string getBankName() const;
  std::string getBankAddress() const;
  std::string getBankPhone() const;
  std::string getBankEmail() const;
  std::vector<Customer*> getCustomers() const;
  std::vector<Employee*> getEmployees() const;
  void saveCustomerList(std::string customerListFilename) const;
  void loadCustomerList(std::string customerListFilename);
  void saveEmployeeList(std::string employeeListFilename) const;
  void loadEmployeeList(std::string employeeListFilename);
  void displayBankInformation(const Bank& bank);
  void displayCustomerList(const Bank& bank);
  void displayEmployeeList(const Bank& bank);
};

#endif

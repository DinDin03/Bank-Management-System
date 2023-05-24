#ifndef BANK_H
#define BANK_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Customer.h"
#include "Employee.h"
#include "Manager.h"

class Bank {
 protected:
  std::string bankName;
  std::string bankAddress;
  std::string bankPhone;
  std::string bankEmail;
  Customer* customer;
  Employee* employee;
  Manager* manager;
  std::string customerListFilename;
  std::string employeeListFilename;
  std::string managerListFilename;

 public:
  Bank(const std::string& bankName, const std::string& bankAddress,
       const std::string& bankPhone, const std::string& bankEmail,
       const std::string& customerListFilename,
       const std::string& employeeListFilename,
       const std::string& managerListFilename);
  ~Bank();
  void addCustomer(Customer* customer);
  void removeCustomer(Customer* customer);
  void addEmployee(Employee* employee);
  void removeEmployee(Employee* employee);
  void addManager(Manager* manager);
  void removeManager(Manager* manager);
  std::string getBankName() const;
  std::string getBankAddress() const;
  std::string getBankPhone() const;
  std::string getBankEmail() const;
  void saveCustomerList(const std::string& customerListFilename) const;
  void loadCustomerList(std::string customerListFilename);
  void saveEmployeeList(const std::string& employeeListFilename) const;
  void loadEmployeeList(std::string employeeListFilename);
  void saveManagerList(const std::string& managerListFilename) const;
  void loadManagerList(std::string managerListFilename);
  void displayBankInformation(const Bank& bank);
  void displayCustomerList(const Bank& bank);
  void displayEmployeeList(const Bank& bank);
  void displayManagerList(const Bank& bank);
};

#endif

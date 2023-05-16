#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Customer.h"

class Bank : public Customer{
private:
    std::string bankName;
    std::string bankAddress;
    std::string bankPhone;
    std::string bankEmail;
    std::vector<Customer*> customers;
    std::string customerListFilename; // Filename for customer list

public:
    Bank(const std::string& bankName, const std::string& bankAddress, const std::string& bankPhone, const std::string& bankEmail, const std::string& customerListFile);
    ~Bank();
    void addCustomer(Customer* customer);
    void removeCustomer(Customer* customer);
    std::string getBankName() const;
    std::string getBankAddress() const;
    std::string getBankPhone() const;
    std::string getBankEmail() const;
    std::vector<Customer*> getCustomers() const;
    void saveCustomerList(std::string customerListFilename) const;
    void loadCustomerList(std::string customerListFilename);
    void displayBankInformation(const Bank& bank);
    void displayCustomerList(const Bank& bank);
};

#endif

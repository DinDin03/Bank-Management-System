#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "Customer.h"
#include "Employee.h"

class Bank {
private:
    std::string bankName;
    std::string bankAddress;
    std::string bankPhone;
    std::string bankEmail;
    std::vector<Customer> customers;
public:
    Bank(std::string name, std::string address, std::string phone, std::string email);
    void addCustomer(const Customer& customer);
    void removeCustomer(const Customer& customer);
    std::string getBankName() const;
    std::string getBankAddress() const;
    std::string getBankPhone() const;
    std::string getBankEmail() const;
    std::vector<Customer> getCustomers() const;
};

#endif //BANK_H

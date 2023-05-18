#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include <fstream>
#include "Account.h"

class Customer {
private:
    std::string name;
    std::string address;
    std::string phone;
    std::string email;
    std::string accountsListFilename;
    Account* account;


public:
    Customer();
    Customer(std::string name, std::string address, std::string phone, std::string email, std::string accountListFilename);
    ~Customer();
    std::string getName() const;
    void setName(std::string name);
    std::string getAddress() const;
    void setAddress(std::string address);
    std::string getPhone() const;
    void setPhone(std::string phone);
    std::string getEmail() const;
    void setEmail(std::string email);
    void addAccount(std::string accountNumber, std::string accountName, double balance, std::string transactionHistoryFilename);
    Account* getAccount(std::string accountNumber);
    std::vector<Account*> getAccounts();
    void deleteAccount(std::string accountNumber);

    void saveAccountsList(std::string accountsListFilename);
    void saveCustomerInfo(std::string filename);
    void loadCustomerInfo(std::string filename);
    bool customerLogin(std::string name, std::string phone);
};

#endif

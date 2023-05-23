#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <fstream>
#include "Account.h"
#include "User.h"

class Customer : public User {
protected:
    std::string address;
    std::vector<Account*> accounts;
    Account* account;

public:
    Customer();
    Customer(std::string name, std::string address, std::string phone, std::string email);
    ~Customer();
    std::string getAddress() const;
    void setAddress(std::string address);
    void addAccount(std::string accountNumber, std::string accountName, double balance, std::string transactionHistoryFilename);
    Account* getAccount(std::string accountNumber);
    std::vector<Account*> getAccounts();
    void deleteAccount(std::string accountNumber);

    void saveAccountsList(const std::string& accountsListFilename, std::string accountNumber);
    void loadAccountsList(const std::string& accountsListFilename);
    void saveCustomerInfo(std::string filename);
    void loadCustomerInfo(std::string filename);
    bool customerLogin(std::string name, std::string phone);
};

#endif

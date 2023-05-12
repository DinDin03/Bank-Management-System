#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include "Account.h"

class Customer {
  private:
    std::string name;
    std::string address;
    std::string phone;
    std::string email;
    std::vector<Account*> accounts;

  public:
    Customer(std::string name, std::string address, std::string phone, std::string email);
    ~Customer();
    std::string getName() const;
    void setName(std::string name);
    std::string getAddress() const;
    void setAddress(std::string address);
    std::string getPhone() const;
    void setPhone(std::string phone);
    std::string getEmail() const;
    void setEmail(std::string email);
    void addAccount(std::string accountNumber, std::string accountName, double balance);
    Account* getAccount(std::string accountNumber);
    std::vector<Account*> getAccounts();
};

#endif

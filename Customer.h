#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <fstream>
#include <vector>

#include "Account.h"
#include "User.h"
using namespace std;

class Customer : public User {
 protected:
  string address;
  vector<Account*> accounts;
  Account* account;

 public:
  Customer();
  Customer(string name, string address, string phone, string email);
  ~Customer();
  string getAddress() const;
  void setAddress(string address);
  void addAccount(string accountNumber, string accountName, double balance,
                  string transactionHistoryFilename);
  Account* getAccount(string accountNumber);
  vector<Account*> getAccounts();
  void deleteAccount(string accountNumber);

  bool checkCustomerDetails(string name, string phone);
  void saveAccountsList(const string& accountsListFilename,
                        string accountNumber);
  void loadAccountsList(const string& accountsListFilename);
  void saveCustomerInfo(string filename);
  void loadUserInfo(string filename) override;
  bool customerLogin(string name, string phone);
};

#endif

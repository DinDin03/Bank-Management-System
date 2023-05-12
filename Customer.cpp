#include "Customer.h"

Customer::Customer(std::string name, std::string address, std::string phone, std::string email)
  : name(name), address(address), phone(phone), email(email) {}

Customer::~Customer() {
  for (Account* account : accounts) {
    delete account;
  }
}

std::string Customer::getName() const {
  return name;
}

void Customer::setName(std::string name) {
  this->name = name;
}

std::string Customer::getAddress() const {
  return address;
}

void Customer::setAddress(std::string address) {
  this->address = address;
}

std::string Customer::getPhone() const {
  return phone;
}

void Customer::setPhone(std::string phone) {
  this->phone = phone;
}

std::string Customer::getEmail() const {
  return email;
}

void Customer::setEmail(std::string email) {
  this->email = email;
}

void Customer::addAccount(std::string accountNumber, std::string accountName, double balance) {
    Account* account = new Account(accountNumber, accountName, balance);
    accounts.push_back(account);
}


Account* Customer::getAccount(std::string accountNumber) {
  for (Account* account : accounts) {
    if (account->getAccountNumber() == accountNumber) {
      return account;
    }
  }
  return nullptr;
}

std::vector<Account*> Customer::getAccounts() {
  return accounts;
}

#include "Customer.h"

#include <iostream>

Customer::Customer() {}

Customer::Customer(std::string name, std::string address, std::string phone,
                   std::string email)
    : name(name), address(address), phone(phone), email(email) {}

Customer::~Customer() {
    for (Account* account : accounts) {
        delete account;
    }
    accounts.clear();
}

std::string Customer::getName() const { return name; }

void Customer::setName(std::string name) { this->name = name; }

std::string Customer::getAddress() const { return address; }

void Customer::setAddress(std::string address) { this->address = address; }

std::string Customer::getPhone() const { return phone; }

void Customer::setPhone(std::string phone) { this->phone = phone; }

std::string Customer::getEmail() const { return email; }

void Customer::setEmail(std::string email) { this->email = email; }

void Customer::addAccount(std::string accountNumber, std::string accountName,
                          double balance,
                          std::string transactionHistoryFilename) {
    Account* account = new Account(accountNumber, accountName, balance,
                                   transactionHistoryFilename);
    accounts.push_back(account);
    std::ofstream outFile(accountNumber + ".txt");
    outFile << "Account Holder Name: " << name << std::endl;
    outFile << "Account Number: " << accountNumber << std::endl;
    outFile << "Account Name: " << accountName << std::endl;
    outFile << "Initial Balance: " << balance << std::endl;
    outFile.close();
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
    for (Account* account : accounts) {
        std::cout << account->getAccountNumber() << std::endl;
    }
    return accounts;
}

void Customer::saveCustomerInfo(std::string filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << name << std::endl;
        outFile << address << std::endl;
        outFile << phone << std::endl;
        outFile << email << std::endl;
        for (Account* account : accounts) {
            outFile << account->getAccountNumber() << std::endl;
        }
        outFile.close();
    }
}

void Customer::loadCustomerInfo(std::string filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::getline(inFile, name);
        std::getline(inFile, address);
        std::getline(inFile, phone);
        std::getline(inFile, email);
        inFile.close();
    }
}

bool Customer::customerLogin(std::string name, std::string phone) {
    std::ifstream inFile(name + ".txt");
    if (inFile.is_open()) {
        std::string accountName;
        std::string accountAddress;
        std::string accountPhone;
        std::string accountEmail;
        std::getline(inFile, accountName);
        std::getline(inFile, accountAddress);
        std::getline(inFile, accountPhone);
        std::getline(inFile, accountEmail);
        inFile.close();
        if (accountPhone == phone) {
            return true;
        }
    }
    return false;
}

void Customer::deleteAccount(std::string accountNumber) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->getAccountNumber() == accountNumber) {
            delete (*it);
            accounts.erase(it);
            std::remove((accountNumber + ".txt").c_str());
            return;
        }
    }
}
void Customer::saveAccountsList(const std::string& accountsListFilename, Account* account) {
    std::ofstream file(accountsListFilename, std::ofstream::app);
    if (file.is_open()) {
        file << account->getAccountNumber() << std::endl;
        file.close();
        std::cout << "Account list saved successfully." << std::endl;
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}
void Customer::loadAccountsList(const std::string& accountsListFilename) {
    std::cout << "\nYour accounts are: " << std::endl;
    std::ifstream file(accountsListFilename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
        std::cout << "\nAccount list loaded successfully." << std::endl;
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}





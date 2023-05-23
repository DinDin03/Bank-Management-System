#include "Customer.h"
#include <iostream>
#include <fstream>

Customer::Customer() : User("", "", "") {}

Customer::Customer(std::string name, std::string address, std::string phone, std::string email)
    : User(name, phone, email), address(address) {}

Customer::~Customer() {
    for (Account* account : accounts) {
        delete account;
    }
    accounts.clear();
}

std::string Customer::getAddress() const { return address; }

void Customer::setAddress(std::string address) { this->address = address; }

void Customer::addAccount(std::string accountNumber, std::string accountName, double balance, std::string transactionHistoryFilename) {
    // Create and save the account information
    std::ofstream outFile(accountNumber + ".txt");
    outFile << "Account Holder Name: " << User::getName() << std::endl;
    outFile << "Account Number: " << accountNumber << std::endl;
    outFile << "Initial Balance: " << balance << std::endl;
    outFile.close();
}

Account* Customer::getAccount(std::string accountNumber) {
    std::string transactionHistoryFilename;
    // Check if the account file exists
    std::ifstream accountFile(accountNumber + ".txt");
    if (accountFile.is_open()) {
        // Create and populate the Account object with the information from the file
        std::string line;
        std::getline(accountFile, line);  // Read the account holder name (ignore for now)
        std::getline(accountFile, line);  // Read the account number
        std::string storedAccountNumber = line.substr(line.find(":") + 2);
        std::getline(accountFile, line);  // Read the initial balance
        double balance = std::stod(line.substr(line.find(":") + 2));
        accountFile.close();

        // Create and return the Account object
        return new Account(storedAccountNumber, User::getName(), balance, transactionHistoryFilename);
    }

    return nullptr;  // Account not found
}

void Customer::saveCustomerInfo(std::string filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << User::getName() << std::endl;
        outFile << address << std::endl;
        outFile << User::getPhone() << std::endl;
        outFile << User::getEmail() << std::endl;
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
    // Remove the account file
    std::remove((accountNumber + ".txt").c_str());

    // Remove the account number from the customer's account list file
    std::string accountsListFilename = User::getName() + "_accounts.txt";
    std::ifstream file(accountsListFilename);
    if (file.is_open()) {
        std::string line;
        std::vector<std::string> accountNumbers;
        while (std::getline(file, line)) {
            if (line != accountNumber) {
                accountNumbers.push_back(line);
            }
        }
        file.close();

        // Rewrite the account list file without the deleted account number
        std::ofstream outFile(accountsListFilename);
        if (outFile.is_open()) {
            for (const std::string& account : accountNumbers) {
                outFile << account << std::endl;
            }
            outFile.close();
        } else {
            std::cout << "Unable to open file." << std::endl;
        }
    }
}

void Customer::saveAccountsList(const std::string& accountsListFilename, std::string accountNumber) {
    std::ofstream file(accountsListFilename, std::ofstream::app);
    if (file.is_open()) {
        file << accountNumber << std::endl;
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

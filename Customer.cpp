#include "Customer.h"

#include <fstream>
#include <iostream>
using namespace std;

Customer::Customer() : User("", "", "") {}

Customer::Customer(string name, string address, string phone, string email)
    : User(name, phone, email), address(address) {}

Customer::~Customer() {
  for (Account* account : accounts) {
    delete account;
  }
  accounts.clear();
}

string Customer::getAddress() const { return address; }

void Customer::setAddress(string address) { this->address = address; }

void Customer::addAccount(string accountNumber, string accountName,
                          double balance, string transactionHistoryFilename) {
  // Create and save the account information
  ofstream outFile(accountNumber + ".txt");
  outFile << "Account Holder Name: " << User::getName() << endl;
  outFile << "Account Number: " << accountNumber << endl;
  outFile << "Initial Balance: " << balance << endl;
  outFile.close();
}

Account* Customer::getAccount(string accountNumber) {
  string transactionHistoryFilename;
  // Check if the account file exists
  ifstream accountFile(accountNumber + ".txt");
  if (accountFile.is_open()) {
    // Create and populate the Account object with the information from the file
    string line;
    getline(accountFile,
            line);  // Read the account holder name (ignore for now)
    getline(accountFile, line);  // Read the account number
    string storedAccountNumber = line.substr(line.find(":") + 2);
    getline(accountFile, line);  // Read the initial balance
    double balance = stod(line.substr(line.find(":") + 2));
    accountFile.close();

    // Create and return the Account object
    return new Account(storedAccountNumber, User::getName(), balance,
                       transactionHistoryFilename);
  }

  return nullptr;  // Account not found
}

void Customer::saveCustomerInfo(string filename) {
  ofstream outFile(filename);
  if (outFile.is_open()) {
    outFile << User::getName() << endl;
    outFile << address << endl;
    outFile << User::getPhone() << endl;
    outFile << User::getEmail() << endl;
    for (Account* account : accounts) {
      outFile << account->getAccountNumber() << endl;
    }
    outFile.close();
  }
}

void Customer::loadUserInfo(string filename) {
  ifstream inFile(filename);
  if (inFile.is_open()) {
    getline(inFile, name);
    cout << "New Customer's name: " << name << endl;
    getline(inFile, address);
    cout << "New Customer's address: " << address << endl;
    getline(inFile, phone);
    cout << "New Customer's phone: " << phone << endl;
    getline(inFile, email);
    cout << "New Customer's email: " << email << endl;
    inFile.close();
  }
}

bool Customer::customerLogin(string name, string phone) {
  ifstream inFile(name + ".txt");
  if (inFile.is_open()) {
    string accountName;
    string accountAddress;
    string accountPhone;
    string accountEmail;
    getline(inFile, accountName);
    getline(inFile, accountAddress);
    getline(inFile, accountPhone);
    getline(inFile, accountEmail);
    inFile.close();
    if (accountPhone == phone && accountName == name) {
      return true;
    }
  }
  return false;
}

void Customer::deleteAccount(string accountNumber) {
  // Remove the account file
  remove((accountNumber + ".txt").c_str());

  // Remove the account number from the customer's account list file
  string accountsListFilename = User::getName() + "_accounts.txt";
  ifstream file(accountsListFilename);
  if (file.is_open()) {
    string line;
    vector<string> accountNumbers;
    while (getline(file, line)) {
      if (line != accountNumber) {
        accountNumbers.push_back(line);
      }
    }
    file.close();

    // Rewrite the account list file without the deleted account number
    ofstream outFile(accountsListFilename);
    if (outFile.is_open()) {
      for (const string& account : accountNumbers) {
        outFile << account << endl;
      }
      outFile.close();
    } else {
      cout << "Unable to open file." << endl;
    }
  }
}

void Customer::saveAccountsList(const string& accountsListFilename,
                                string accountNumber) {
  ofstream file(accountsListFilename, ofstream::app);
  if (file.is_open()) {
    file << accountNumber << endl;
    file.close();
    cout << "Account list saved successfully." << endl;
  } else {
    cout << "Unable to open file." << endl;
  }
}

void Customer::loadAccountsList(const string& accountsListFilename) {
  cout << "\nYour accounts are: " << endl;
  ifstream file(accountsListFilename);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      cout << line << endl;
    }
    file.close();
    cout << "\nAccount list loaded successfully." << endl;
  } else {
    cout << "Unable to open file." << endl;
  }
}
bool Customer::checkCustomerDetails(string name, string phone) {
  ifstream inFile(name + ".txt");
  if (inFile.is_open()) {
    string accountName;
    string accountAddress;
    string accountPhone;
    string accountEmail;
    getline(inFile, accountName);
    getline(inFile, accountAddress);
    getline(inFile, accountPhone);
    getline(inFile, accountEmail);
    inFile.close();

    return (accountName == name && accountPhone == phone);
  }

  return false;
}

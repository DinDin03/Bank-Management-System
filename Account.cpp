#include "Account.h"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

Account::Account(string accountNumber, string accountHolderName,
                 double accountBalance, string transactionHistoryFilename)
    : accountNumber(accountNumber),
      accountHolderName(accountHolderName),
      accountBalance(accountBalance),
      transactionHistoryFilename(transactionHistoryFilename) {
  // Load account information from file
  ifstream file(accountNumber + ".txt");
  if (file.is_open()) {
    file >> accountHolderName >> accountBalance;
    file.close();
  }
}

void Account::deposit(string accountHolderName, double amount) {
  accountBalance += amount;
  transactions.emplace_back(
      Transaction(chrono::system_clock::now(), amount, "Deposit"));

  // Save account information to file
  ofstream file(accountNumber + ".txt");
  if (file.is_open()) {
    file << "Account Holder Name: " << accountHolderName << endl;
    file << "Account Number: " << accountNumber << endl;
    file << "Initial Balance: " << accountBalance << endl;
    file.close();
  }
}

bool Account::withdraw(string accountHolderName, double amount) {
  if (accountBalance >= amount) {
    accountBalance -= amount;
    transactions.emplace_back(
        Transaction(chrono::system_clock::now(), -amount, "Withdraw"));

    // Save account information to file
    ofstream file(accountNumber + ".txt");
    if (file.is_open()) {
      file << "Account Holder Name: " << accountHolderName << endl;
      file << "Account Number: " << accountNumber << endl;
      file << "Initial Balance: " << accountBalance << endl;
      file.close();
    }

    return true;
  } else {
    return false;
  }
}

bool Account::transfer(const string& toAccountNumber, double amount) {
  if (accountBalance >= amount) {
    accountBalance -= amount;
    transactions.emplace_back(
        Transaction(chrono::system_clock::now(), -amount, "Transfer"));

    // Save account information to sender's file
    ofstream senderFile(accountNumber + ".txt");
    if (senderFile.is_open()) {
      senderFile << "Account Holder Name: " << accountHolderName << endl;
      senderFile << "Account Number: " << accountNumber << endl;
      senderFile << "Initial Balance: " << accountBalance << endl;
      senderFile.close();
    } else {
      cout << "Unable to open sender's account file." << endl;
      return false;
    }

    // Load recipient's account information from file
    // Load recipient's account information from file
    ifstream recipientFile(toAccountNumber + ".txt");
    if (recipientFile.is_open()) {
      string recipientAccountHolderName;
      string recipientAccountNumber;
      double recipientAccountBalance;

      // Read the account holder name
      getline(recipientFile, recipientAccountHolderName);

      // Read the account number
      getline(recipientFile, recipientAccountNumber);

      // Read the account balance line
      string recipientAccountBalanceLine;
      if (getline(recipientFile, recipientAccountBalanceLine)) {
        // Extract the account balance from the balance line
        string balanceValue = recipientAccountBalanceLine.substr(
            recipientAccountBalanceLine.find(":") + 2);
        recipientAccountBalance = stod(balanceValue);

        // Update recipient's account balance
        recipientAccountBalance += amount;
      } else {
        cout << "Invalid recipient account information." << endl;
        recipientFile.close();
        return false;
      }

      recipientFile.close();

      // Save updated recipient's account information to file
      ofstream updatedRecipientFile(toAccountNumber + ".txt");
      if (updatedRecipientFile.is_open()) {
        updatedRecipientFile << recipientAccountHolderName << endl;
        updatedRecipientFile << "Account Number: " << toAccountNumber << endl;
        updatedRecipientFile << "Initial Balance: " << recipientAccountBalance
                             << endl;
        updatedRecipientFile.close();
      } else {
        cout << "Unable to open recipient's account file." << endl;
        return false;
      }

      return true;
    } else {
      cout << "Recipient's account not found." << endl;
      return false;
    }
  }

  return false;
}

string Account::getAccountNumber() const { return accountNumber; }

string Account::getAccountHolderName() const { return accountHolderName; }

double Account::getAccountBalance() const { return accountBalance; }

void Account::saveTransactionHistory(string transactionHistoryFilename) const {
  ofstream outFile(transactionHistoryFilename);
  if (outFile.is_open()) {
    for (const auto& transaction : transactions) {
      outFile << "Date: " << transaction.getDate() << "\n";
      outFile << "Time: " << transaction.getTime() << "\n";
      outFile << "Amount: " << transaction.getAmount() << "\n";
      outFile << "Type: " << transaction.getType() << "\n\n";
    }
    outFile.close();
  }
}
void Account::saveReciepentTransactionHistory(
    string transactionHistoryFilename) const {
  ofstream outFile(transactionHistoryFilename);
  if (outFile.is_open()) {
    for (const auto& transaction : transactions) {
      outFile << "Date: " << transaction.getDate() << "\n";
      outFile << "Time: " << transaction.getTime() << "\n";
      outFile << "Amount: " << -(transaction.getAmount()) << "\n";
      outFile << "Type: " << transaction.getType() << "\n\n";
    }
    outFile.close();
  }
}

void Account::loadTransactionHistory(string transactionHistoryFilename) {
  ifstream file(transactionHistoryFilename);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      cout << line << endl;
    }
    file.close();
  }
}

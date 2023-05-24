#include "Account.h"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

Account::Account(std::string accountNumber, std::string accountHolderName,
                 double accountBalance, std::string transactionHistoryFilename)
    : accountNumber(accountNumber),
      accountHolderName(accountHolderName),
      accountBalance(accountBalance),
      transactionHistoryFilename(transactionHistoryFilename) {
  // Load account information from file
  std::ifstream file(accountNumber + ".txt");
  if (file.is_open()) {
    file >> accountHolderName >> accountBalance;
    file.close();
  }
}

void Account::deposit(std::string accountHolderName, double amount) {
  accountBalance += amount;
  transactions.emplace_back(
      Transaction(std::chrono::system_clock::now(), amount, "Deposit"));

  // Save account information to file
  std::ofstream file(accountNumber + ".txt");
  if (file.is_open()) {
    file << "Account Holder Name: " << accountHolderName << std::endl;
    file << "Account Number: " << accountNumber << std::endl;
    file << "Initial Balance: " << accountBalance << std::endl;
    file.close();
  }
}

bool Account::withdraw(std::string accountHolderName, double amount) {
  if (accountBalance >= amount) {
    accountBalance -= amount;
    transactions.emplace_back(
        Transaction(std::chrono::system_clock::now(), -amount, "Withdraw"));

    // Save account information to file
    std::ofstream file(accountNumber + ".txt");
    if (file.is_open()) {
      file << "Account Holder Name: " << accountHolderName << std::endl;
      file << "Account Number: " << accountNumber << std::endl;
      file << "Initial Balance: " << accountBalance << std::endl;
      file.close();
    }

    return true;
  } else {
    return false;
  }
}

bool Account::transfer(const std::string& toAccountNumber, double amount) {
  if (accountBalance >= amount) {
    accountBalance -= amount;
    transactions.emplace_back(
        Transaction(std::chrono::system_clock::now(), -amount, "Transfer"));

    // Save account information to sender's file
    std::ofstream senderFile(accountNumber + ".txt");
    if (senderFile.is_open()) {
      senderFile << "Account Holder Name: " << accountHolderName << std::endl;
      senderFile << "Account Number: " << accountNumber << std::endl;
      senderFile << "Initial Balance: " << accountBalance << std::endl;
      senderFile.close();
    } else {
      std::cout << "Unable to open sender's account file." << std::endl;
      return false;
    }

    // Load recipient's account information from file
    // Load recipient's account information from file
    std::ifstream recipientFile(toAccountNumber + ".txt");
    if (recipientFile.is_open()) {
      std::string recipientAccountHolderName;
      std::string recipientAccountNumber;
      double recipientAccountBalance;

      // Read the account holder name
      std::getline(recipientFile, recipientAccountHolderName);

      // Read the account number
      std::getline(recipientFile, recipientAccountNumber);

      // Read the account balance line
      std::string recipientAccountBalanceLine;
      if (std::getline(recipientFile, recipientAccountBalanceLine)) {
        // Extract the account balance from the balance line
        std::string balanceValue = recipientAccountBalanceLine.substr(
            recipientAccountBalanceLine.find(":") + 2);
        recipientAccountBalance = std::stod(balanceValue);

        // Update recipient's account balance
        recipientAccountBalance += amount;
      } else {
        std::cout << "Invalid recipient account information." << std::endl;
        recipientFile.close();
        return false;
      }

      recipientFile.close();

      // Save updated recipient's account information to file
      std::ofstream updatedRecipientFile(toAccountNumber + ".txt");
      if (updatedRecipientFile.is_open()) {
        updatedRecipientFile
            << recipientAccountHolderName
            << std::endl;
        updatedRecipientFile << "Account Number: " << toAccountNumber
                             << std::endl;
        updatedRecipientFile << "Initial Balance: " << recipientAccountBalance
                             << std::endl;
        updatedRecipientFile.close();
      } else {
        std::cout << "Unable to open recipient's account file." << std::endl;
        return false;
      }

      return true;
    } else {
      std::cout << "Recipient's account not found." << std::endl;
      return false;
    }
  }

  return false;
}

std::string Account::getAccountNumber() const { return accountNumber; }

std::string Account::getAccountHolderName() const { return accountHolderName; }

double Account::getAccountBalance() const { return accountBalance; }

void Account::saveTransactionHistory(
    std::string transactionHistoryFilename) const {
  std::ofstream outFile(transactionHistoryFilename);
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
    std::string transactionHistoryFilename) const {
  std::ofstream outFile(transactionHistoryFilename);
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

void Account::loadTransactionHistory(std::string transactionHistoryFilename) {
  std::ifstream file(transactionHistoryFilename);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      std::cout << line << std::endl;
    }
    file.close();
  }
}

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
    std::ifstream recipientFile(toAccountNumber + ".txt");
    if (recipientFile.is_open()) {
      std::string recipientAccountHolderName;
      double recipientAccountBalance;
      recipientFile >> recipientAccountHolderName >> recipientAccountBalance;
      recipientFile.close();

      // Update recipient's account balance
      recipientAccountBalance += amount;

      // Save updated recipient's account information to file
      std::ofstream updatedRecipientFile(toAccountNumber + ".txt");
      if (updatedRecipientFile.is_open()) {
        updatedRecipientFile << "Account Holder Name: " << recipientAccountHolderName << std::endl;
        updatedRecipientFile << "Account Number: " << toAccountNumber << std::endl;
        updatedRecipientFile << "Initial Balance: " << recipientAccountBalance << std::endl;
        updatedRecipientFile.close();
      } else {
        std::cout << "Unable to open recipient's account file." << std::endl;
        return false;
      }
    } else {
      std::cout << "Recipient's account not found." << std::endl;
      return false;
    }

    return true;
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
      outFile << transaction.getDate() << "\n";
      outFile << transaction.getTime() << "\n";
      outFile << transaction.getAmount() << "\n";
      outFile << transaction.getType();
    }
    outFile.close();
  }
}

void Account::loadTransactionHistory(std::string transactionHistoryFilename) {
  std::ifstream file(transactionHistoryFilename);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      std::stringstream iss(line);
      std::string date, time, type, amountStr;
      double amount;
      if (std::getline(iss, date, ',') && std::getline(iss, time, ',') &&
          std::getline(iss, amountStr, ',') && std::getline(iss, type)) {
        // Convert the date and time strings to
        // std::chrono::system_clock::time_point
        std::tm timeInfo = {};
        std::istringstream dateStream(date);
        dateStream >> std::get_time(&timeInfo, "%Y-%m-%d");
        std::chrono::system_clock::time_point dateTime =
            std::chrono::system_clock::from_time_t(std::mktime(&timeInfo));

        std::tm timeInfo2 = {};
        std::istringstream timeStream(time);
        timeStream >> std::get_time(&timeInfo2, "%H:%M:%S");
        std::chrono::system_clock::time_point timePoint =
            std::chrono::system_clock::from_time_t(std::mktime(&timeInfo2));

        // Combine date and time
        std::chrono::system_clock::time_point transactionTime =
            dateTime + (timePoint - std::chrono::system_clock::time_point());

        // Convert the amount string to double
        double amount = std::stod(amountStr);

        // Create a new Transaction object
        Transaction transaction(transactionTime, amount, type);

        // Add the transaction to the transactions vector
        transactions.emplace_back(transaction);
      }
    }
    file.close();
  }
}

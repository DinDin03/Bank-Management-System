#include "Account.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>

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

void Account::deposit(double amount) {
  accountBalance += amount;
  transactions.emplace_back(
      Transaction(std::chrono::system_clock::now(), amount, "Deposit"));

  // Save account information to file
  std::ofstream file(accountNumber + ".txt");
  if (file.is_open()) {
    file << accountHolderName << std::endl;
    file << accountBalance << std::endl;
    file.close();
  }
}

bool Account::withdraw(double amount) {
  if (accountBalance >= amount) {
    accountBalance -= amount;
    transactions.emplace_back(
        Transaction(std::chrono::system_clock::now(), -amount, "Withdraw"));

    // Save account information to file
    std::ofstream file(accountNumber + ".txt");
    if (file.is_open()) {
      file << accountHolderName << std::endl;
      file << accountBalance << std::endl;
      file.close();
    }

    return true;
  } else {
    return false;
  }
}

bool Account::transfer(Account& toAccount, double amount) {
  if (accountBalance >= amount) {
    accountBalance -= amount;
    transactions.emplace_back(
        Transaction(std::chrono::system_clock::now(), -amount, "Transfer"));

    toAccount.accountBalance += amount;
    toAccount.transactions.emplace_back(
        Transaction(std::chrono::system_clock::now(), amount, "Transfer"));

    // Save account information to file
    std::ofstream file(accountNumber + ".txt");
    if (file.is_open()) {
      file << accountHolderName << std::endl;
      file << accountBalance << std::endl;
      file.close();
    }

    // Save recipient account information to file
    std::ofstream recipientFile(toAccount.accountNumber + ".txt");
    if (recipientFile.is_open()) {
      recipientFile << toAccount.accountHolderName << std::endl;
      recipientFile << toAccount.accountBalance << std::endl;
      recipientFile.close();
    }

    return true;
  } else {
    return false;
  }
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
        // Convert the date and time strings to std::chrono::system_clock::time_point
        std::tm timeInfo = {};
        std::istringstream dateStream(date);
        dateStream >> std::get_time(&timeInfo, "%Y-%m-%d");
        std::chrono::system_clock::time_point dateTime = std::chrono::system_clock::from_time_t(std::mktime(&timeInfo));

        std::tm timeInfo2 = {};
        std::istringstream timeStream(time);
        timeStream >> std::get_time(&timeInfo2, "%H:%M:%S");
        std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(std::mktime(&timeInfo2));

        // Combine date and time
        std::chrono::system_clock::time_point transactionTime = dateTime + (timePoint - std::chrono::system_clock::time_point());

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



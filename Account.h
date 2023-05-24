#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "Transaction.h"

class Account {
 public:
  Account(std::string accountNumber, std::string accountHolderName,
          double accountBalance, std::string transactionHistoryFilename);
  void deposit(std::string accountHolderName, double amount);
  bool withdraw(std::string accountHolderName,double amount);
  bool transfer(const std::string& toAccountNumber, double amount);
  std::string getAccountNumber() const;
  std::string getAccountHolderName() const;
  double getAccountBalance() const;
  void saveTransactionHistory(std::string transactionHistoryFilename) const;
  void saveReciepentTransactionHistory(std::string transactionHistoryFilename) const;
  void loadTransactionHistory(std::string transactionHistoryFilename);

 private:
  std::string accountNumber;
  std::string accountHolderName;
  std::string transactionHistoryFilename;
  std::vector<Transaction> transactions;
  double accountBalance;
};

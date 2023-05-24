#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "Transaction.h"

using namespace std;

class Account {
public:
  // Constructor
  Account(string accountNumber, string accountHolderName,
          double accountBalance, string transactionHistoryFilename);

  // Deposit funds into the account
  void deposit(string accountHolderName, double amount);

  // Withdraw funds from the account
  bool withdraw(string accountHolderName, double amount);

  // Transfer funds to another account
  bool transfer(const string& toAccountNumber, double amount);

  // Getters
  string getAccountNumber() const;
  string getAccountHolderName() const;
  double getAccountBalance() const;

  // Save the transaction history to a file
  void saveTransactionHistory(string transactionHistoryFilename) const;

  // Save the recipient's transaction history to a file
  void saveReciepentTransactionHistory(string transactionHistoryFilename) const;

  // Load the transaction history from a file
  void loadTransactionHistory(string transactionHistoryFilename);

private:
  string accountNumber;
  string accountHolderName;
  string transactionHistoryFilename;
  vector<Transaction> transactions;
  double accountBalance;
};

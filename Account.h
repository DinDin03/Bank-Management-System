#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "Transaction.h"

class Account {
public:
    Account(std::string accountNumber, std::string accountHolderName, double accountBalance);
    void deposit(double amount);
    bool withdraw(double amount);
    bool transfer(Account& toAccount, double amount);
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getAccountBalance() const;
    std::vector<Transaction> getTransactionHistory() const;
    void saveData() const;

private:
    std::string m_accountNumber;
    std::string m_accountHolderName;
    double m_accountBalance;
    std::vector<Transaction> m_transactionHistory;
};


#include "Account.h"

Account::Account(std::string accountNumber, std::string accountHolderName, double accountBalance)
    : m_accountNumber(accountNumber), m_accountHolderName(accountHolderName), m_accountBalance(accountBalance)
{
}

void Account::deposit(double amount)
{
    m_accountBalance += amount;
    m_transactionHistory.emplace_back(Transaction(std::chrono::system_clock::now(), amount, "Deposit"));
}

bool Account::withdraw(double amount)
{
    if (m_accountBalance >= amount) {
        m_accountBalance -= amount;
        m_transactionHistory.emplace_back(Transaction(std::chrono::system_clock::now(), -amount, "Withdraw"));
        return true;
    } else {
        return false;
    }
}

bool Account::transfer(Account& toAccount, double amount)
{
    if (m_accountBalance >= amount) {
        m_accountBalance -= amount;
        m_transactionHistory.emplace_back(Transaction(std::chrono::system_clock::now(), -amount, "Transfer"));
        toAccount.m_accountBalance += amount;
        toAccount.m_transactionHistory.emplace_back(Transaction(std::chrono::system_clock::now(), -amount, "Transfer"));
        return true;
    } else {
        return false;
    }
}

std::string Account::getAccountNumber() const
{
    return m_accountNumber;
}

std::string Account::getAccountHolderName() const
{
    return m_accountHolderName;
}

double Account::getAccountBalance() const
{
    return m_accountBalance;
}

std::vector<Transaction> Account::getTransactionHistory() const
{
    return m_transactionHistory;
}

#include "Account.h"
#include <fstream>

Account::Account(std::string accountNumber, std::string accountHolderName, double accountBalance)
    : m_accountNumber(accountNumber), m_accountHolderName(accountHolderName), m_accountBalance(accountBalance)
{
    // Load account information from file
    std::ifstream file(accountNumber + ".txt");
    if (file.is_open()) {
        file >> m_accountHolderName >> m_accountBalance;
        file.close();
    }
}

void Account::deposit(double amount)
{
    m_accountBalance += amount;
    m_transactionHistory.emplace_back(Transaction(std::chrono::system_clock::now(), amount, "Deposit"));

    // Save account information to file
    std::ofstream file(m_accountNumber + ".txt");
    if (file.is_open()) {
        file << m_accountHolderName << std::endl;
        file << m_accountBalance << std::endl;
        file.close();
    }
}

bool Account::withdraw(double amount)
{
    if (m_accountBalance >= amount) {
        m_accountBalance -= amount;
        m_transactionHistory.emplace_back(Transaction(std::chrono::system_clock::now(), -amount, "Withdraw"));

        // Save account information to file
        std::ofstream file(m_accountNumber + ".txt");
        if (file.is_open()) {
            file << m_accountHolderName << std::endl;
            file << m_accountBalance << std::endl;
            file.close();
        }

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
        toAccount.m_transactionHistory.emplace_back(Transaction(std::chrono::system_clock::now(), amount, "Transfer"));

        // Save account information to file
        std::ofstream file(m_accountNumber + ".txt");
        if (file.is_open()) {
            file << m_accountHolderName << std::endl;
            file << m_accountBalance << std::endl;
            file.close();
        }

        // Save recipient account information to file
        std::ofstream recipientFile(toAccount.m_accountNumber + ".txt");
        if (recipientFile.is_open()) {
            recipientFile << toAccount.m_accountHolderName << std::endl;
            recipientFile << toAccount.m_accountBalance << std::endl;
            recipientFile.close();
        }

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

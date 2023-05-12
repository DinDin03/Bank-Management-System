#pragma once

#include <string>
#include <chrono>

class Transaction {
public:
    Transaction(const std::chrono::system_clock::time_point& datetime, double amount, const std::string& type);

    std::string getDate() const;
    std::string getTime() const;
    double getAmount() const;
    std::string getType() const;

private:
    std::chrono::system_clock::time_point datetime_;
    double amount_;
    std::string type_;
};

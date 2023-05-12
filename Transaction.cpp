#include "Transaction.h"
#include <iomanip>

Transaction::Transaction(const std::chrono::system_clock::time_point& datetime, double amount, const std::string& type)
    : datetime_(datetime), amount_(amount), type_(type) {}

std::string Transaction::getDate() const {
    auto time = std::chrono::system_clock::to_time_t(datetime_);
    std::ostringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d");
    return ss.str();
}

std::string Transaction::getTime() const {
    auto time = std::chrono::system_clock::to_time_t(datetime_);
    std::ostringstream ss;
    ss << std::put_time(std::localtime(&time), "%H:%M:%S");
    return ss.str();
}

double Transaction::getAmount() const {
    return amount_;
}

std::string Transaction::getType() const {
    return type_;
}

#include "Transaction.h"

#include <iomanip>
using namespace std;

Transaction::Transaction(const chrono::system_clock::time_point& datetime,
                         double amount, const string& type)
    : datetime_(datetime), amount_(amount), type_(type) {}

string Transaction::getDate() const {
  auto time = chrono::system_clock::to_time_t(datetime_);
  ostringstream ss;
  ss << put_time(localtime(&time), "%Y-%m-%d");
  return ss.str();
}

string Transaction::getTime() const {
  auto time = chrono::system_clock::to_time_t(datetime_);
  ostringstream ss;
  ss << put_time(localtime(&time), "%H:%M:%S");
  return ss.str();
}

double Transaction::getAmount() const { return amount_; }

string Transaction::getType() const { return type_; }

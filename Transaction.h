#pragma once
#include <chrono>
#include <string>
using namespace std;

class Transaction {
 public:
  Transaction(const chrono::system_clock::time_point& datetime, double amount,
              const string& type);

  string getDate() const;
  string getTime() const;
  double getAmount() const;
  string getType() const;

 private:
  chrono::system_clock::time_point datetime_;
  double amount_;
  string type_;
};

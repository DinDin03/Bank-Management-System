#include <iostream>
#include <chrono>
#include "Transaction.h"

int main() {
    // Get current date and time
    auto current_time = std::chrono::system_clock::now();
    std::time_t current_time_t = std::chrono::system_clock::to_time_t(current_time);

    // Create transaction object with current date and time
   auto now = std::chrono::system_clock::now();
   Transaction t(now, 100.50, "debit");


    // Output transaction details
    std::cout << "Transaction Date: " << t.getDate() << std::endl;
    std::cout << "Transaction Time: " << t.getTime() << std::endl;
    std::cout << "Transaction Amount: " << t.getAmount() << std::endl;
    std::cout << "Transaction Type: " << t.getType() << std::endl;

    return 0;
}

#include <iostream>
#include "Transaction.h"
#include "Account.h"
#include "Customer.h"

int main() {
  // Create a customer object
  Customer customer("John Doe", "123 Main St", "555-1234",
                    "johndoe@example.com");
  std::cout << "Customer Name: " << customer.getName() << std::endl;
  std::cout << "Customer Address: " << customer.getAddress() << std::endl;
  std::cout << "Customer Phone: " << customer.getPhone() << std::endl;
  std::cout << "Customer Email: " << customer.getEmail() << std::endl;

  // Add two accounts to the customer
  customer.addAccount("123456", "John Doe", 1000.0);
  customer.addAccount("789012", "John Doe", 2000.0);

  // Print out the account information for the customer
  std::vector<Account*> accounts = customer.getAccounts();
  for (Account* account : accounts) {
    std::cout << "Account number: " << account->getAccountNumber()
              << ", balance: " << account->getAccountBalance() << "\n";
  }

  // Make a withdrawal from one of the accounts
  std::string accountNumber = "123456";
  double withdrawalAmount = 500.0;
  Account* account = customer.getAccount(accountNumber);
  if (account != nullptr) {
    account->withdraw(withdrawalAmount);
    std::cout << "New balance for account " << accountNumber << ": "
              << account->getAccountBalance() << "\n";
  }
  // Print out the updated account information for the customer
  accounts = customer.getAccounts();
  for (auto account : accounts) {
    std::cout << "Account Number: " << account->getAccountNumber() << std::endl;
    std::cout << "Account Balance: $" << account->getAccountBalance()
              << std::endl;
  }

  return 0;
}

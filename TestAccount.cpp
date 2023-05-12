#include <iostream>

#include "Account.h"

int main() {
  // Create a new account with initial balance of 1000
  Account myAccount(123456789, "John Doe", 1000);

  // Print initial account information
  std::cout << "Account Number: " << myAccount.getAccountNumber() << "\n";
  std::cout << "Account Holder Name: " << myAccount.getAccountHolderName()
            << "\n";
  std::cout << "Account Balance: " << myAccount.getAccountBalance() << "\n";

  // Deposit 500 into the account
  myAccount.deposit(500);

  // Print account information after deposit
  std::cout << "Account Balance after deposit: "
            << myAccount.getAccountBalance() << "\n";

  // Withdraw 200 from the account
  myAccount.withdraw(200);

  // Print account information after withdrawal
  std::cout << "Account Balance after withdrawal: "
            << myAccount.getAccountBalance() << "\n";

  // Create a second account
  Account myOtherAccount(987654321, "Jane Smith", 500);

  // Transfer 300 from myAccount to myOtherAccount
  myAccount.transfer(myOtherAccount, 300);

  // Print account information after transfer
  std::cout << "My Account:\n";
  std::cout << "Account Number: " << myAccount.getAccountNumber() << "\n";
  std::cout << "Account Holder Name: " << myAccount.getAccountHolderName()
            << "\n";
  std::cout << "Account Balance: " << myAccount.getAccountBalance() << "\n";

  std::cout << "My Other Account:\n";
  std::cout << "Account Number: " << myOtherAccount.getAccountNumber() << "\n";
  std::cout << "Account Holder Name: " << myOtherAccount.getAccountHolderName()
            << "\n";
  std::cout << "Account Balance: " << myOtherAccount.getAccountBalance()
            << "\n";

  // Print transaction history for myAccount
  std::cout << "Transaction history for My Account:\n";
  for (const auto& transaction : myAccount.getTransactionHistory()) {
    std::cout << "Date: " << transaction.getDate() << "\n";
    std::cout << "Time: " << transaction.getTime() << "\n";
    std::cout << "Type: " << transaction.getType() << "\n";
    std::cout << "Amount: " << transaction.getAmount() << "\n";
  }

  // Print transaction history for myOtherAccount
  std::cout << "Transaction history for My Other Account:\n";
  for (const auto& transaction : myOtherAccount.getTransactionHistory()) {
    std::cout << "Date: " << transaction.getDate() << "\n";
    std::cout << "Time: " << transaction.getTime() << "\n";
    std::cout << "Type: " << transaction.getType() << "\n";
    std::cout << "Amount: " << transaction.getAmount() << "\n";
  }

  return 0;
}

#include <chrono>
#include <iostream>
#include <random>

#include "Account.h"
#include "Customer.h"
#include "Transaction.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<long long> dis(0, 9999999999);

int main() {
  std::cout << "Welcome to the banking system!!!\n" << std::endl;
  bool running = true;
  while (running) {
    std::cout << "Please choose an option\n" << std::endl;
    std::cout << "1. Create a new customer" << std::endl;
    std::cout << "2. Existing customer login" << std::endl;
    std::cout << "3. Quit\n" << std::endl;
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << std::endl;
    switch (choice) {
      case 1: {
        std::string name, address, phone, email;
        std::cout << "Enter customer's name: ";
        std::cin >> name;
        std::cout << "Enter customer's address: ";
        std::cin >> address;
        std::cout << "Enter customer's phone number: ";
        std::cin >> phone;
        std::cout << "Enter customer's email: ";
        std::cin >> email;
        Customer customer(name, address, phone, email);
        customer.saveCustomerInfo(name + ".txt");
        std::cout << "\nNew customer information saved." << std::endl;
        std::cout << "Customer's name: " << customer.getName() << std::endl;
        std::cout << "Customer's address: " << customer.getAddress()
                  << std::endl;
        std::cout << "Customer's phone number: " << customer.getPhone()
                  << std::endl;
        std::cout << "Customer's email: " << customer.getEmail() << std::endl;
        break;
      }
      case 2: {
        std::string name, phone;
        std::cout << "Enter customer's name: ";
        std::cin >> name;
        std::cout << "Enter customer's phone number: ";
        std::cin >> phone;
        Customer customer(name, "", phone, "");
        bool loginSuccessful = customer.customerLogin(name, phone);
        if (loginSuccessful) {
          std::cout << "\nLogin successful!" << std::endl;
          int accountChoice;
          while (true) {
            std::cout << "\nPlease choose an option:" << std::endl;
            std::cout << "1. Create new account" << std::endl;
            std::cout << "2. Log in to existing account" << std::endl;
            std::cout << "3. Delete account" << std::endl;
            std::cout << "4. Logout" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> accountChoice;
            switch (accountChoice) {
              case 1: {
                std::string accountHolderName;
                std::string accountNumber = std::to_string(dis(gen));
                ;
                double initialBalance;
                std::cout << "Enter account holder's name: ";
                std::cin >> accountHolderName;
                std::cout << "Enter initial balance: ";
                std::cin >> initialBalance;
                customer.addAccount(accountNumber, accountHolderName,
                                    initialBalance);
                std::cout << "\nNew account added successfully.\n" << std::endl;
                std::cout << "Account holder's name: " << accountHolderName
                          << std::endl;
                std::cout << "Account Number: "
                          << customer.getAccounts().back()->getAccountNumber()
                          << std::endl;
                std::cout << "Account Balance: "
                          << customer.getAccounts().back()->getAccountBalance()
                          << std::endl;
                break;
              }
              case 2: {
                std::string accountNumber;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << std::endl;
                Account* account = customer.getAccount(accountNumber);
                if (account != nullptr) {
                  std::cout
                      << "Account balance: " << account->getAccountBalance()
                      << std::endl;
                } else {
                  std::cout << "Account not found. Please try again."
                            << std::endl;
                }
                break;
              }
              case 3: {
                std::string accountNumber;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << std::endl;
                Account* account = customer.getAccount(accountNumber);
                if (account != nullptr) {
                  std::cout << "Are you sure you want to delete this account? "
                               "(y/n): ";
                  char confirm;
                  std::cin >> confirm;
                  std::cout << std::endl;
                  if (confirm == 'y') {
                    customer.deleteAccount(accountNumber);
                    std::cout << "Account deleted successfully." << std::endl;
                  }
                } else {
                  std::cout << "Account not found. Please try again."
                            << std::endl;
                }
                break;
              }
              case 4: {
                std::cout << "Logging out..." << std::endl;
                break;
              }
              default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
              }
            }
          }
        }
      }

      case 3: {
        running = false;
        std::cout << "Goodbye!" << std::endl;
        break;
      }
      default: {
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
      }
    }
  }
  return 0;
}

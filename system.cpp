#include <chrono>
#include <iostream>
#include <random>

#include "Account.h"
#include "Bank.h"
#include "Customer.h"
#include "Employee.h"
#include "Transaction.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<long long> dis(0, 9999999999);

int main() {
  Bank bank("Uncommonwealth Bank", "123 Main Street", "123-456-7890",
            "info@uncommonwealthbank.com", "customerList.txt",
            "employeeList.txt");
  std::cout << "Welcome to the banking system!!!\n" << std::endl;
  bool running = true;
  while (running) {
    std::cout << "Please choose an option\n" << std::endl;
    std::cout << "1. Customers" << std::endl;
    std::cout << "2. Employees" << std::endl;
    std::cout << "3. Bank" << std::endl;
    std::cout << "4. Goodbye" << std::endl;
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << std::endl;
    switch (choice) {
      case 1: {
        bool customersRunning = true;
        while (customersRunning) {
          std::cout << "Customers Menu\n" << std::endl;
          std::cout << "1. Create Customer" << std::endl;
          std::cout << "2. Existing Customer Login" << std::endl;
          std::cout << "3. Go Back" << std::endl;
          int customersChoice;
          std::cout << "Enter your choice: ";
          std::cin >> customersChoice;
          std::cout << std::endl;
          switch (customersChoice) {
            case 1: {
              std::string name, address, phone, email;
              std::cout << "Enter customer's name: ";
              std::cin.ignore();
              std::getline(std::cin, name);
              std::cout << "Enter customer's address: ";
              std::getline(std::cin, address);
              std::cout << "Enter customer's phone number: ";
              std::cin >> phone;
              std::cout << "Enter customer's email: ";
              std::cin >> email;
              Customer customer(name, address, phone, email);
              customer.saveCustomerInfo(name + ".txt");
              bank.addCustomer(&customer);
              bank.saveCustomerList("customerList.txt");
              std::cout << "\nNew customer information saved." << std::endl;
              std::cout << "Customer's name: " << customer.getName()
                        << std::endl;
              std::cout << "Customer's address: " << customer.getAddress()
                        << std::endl;
              std::cout << "Customer's phone number: " << customer.getPhone()
                        << std::endl;
              std::cout << "Customer's email: " << customer.getEmail()
                        << std::endl;
              break;
            }

            case 2: {
              std::string name, phone;
              std::cout << "Enter customer's name: ";
              std::cin.ignore();
              std::getline(std::cin, name);
              std::cout << "Enter customer's phone number: ";
              std::getline(std::cin, phone);
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
                      std::string transactionHistoryFilename =
                          accountNumber + "TransactionHistory";
                      double initialBalance;
                      std::cout << "Enter account holder's name: ";
                      std::cin >> accountHolderName;
                      std::cout << "Enter initial balance: ";
                      std::cin >> initialBalance;
                      customer.addAccount(accountNumber, accountHolderName,
                                          initialBalance,
                                          transactionHistoryFilename);
                      std::cout << "\nNew account added successfully.\n"
                                << std::endl;
                      std::cout
                          << "Account holder's name: " << accountHolderName
                          << std::endl;
                      std::cout
                          << "Account Number: "
                          << customer.getAccounts().back()->getAccountNumber()
                          << std::endl;
                      std::cout
                          << "Account Balance: "
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
                        std::cout << "Account balance: "
                                  << account->getAccountBalance() << std::endl;
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
                        std::cout
                            << "Are you sure you want to delete this account? "
                               "(y/n): ";
                        char confirm;
                        std::cin >> confirm;
                        std::cout << std::endl;
                        if (confirm == 'y') {
                          customer.deleteAccount(accountNumber);
                          std::cout << "Account deleted successfully."
                                    << std::endl;
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
                      std::cout << "Invalid choice. Please try again."
                                << std::endl;
                      break;
                    }
                  }
                }
              }
              else{
                std::cout << "Creditientials wrong" << std::endl;
              }
            }
            case 3: {
              customersRunning = false;
              std::cout << "Going back to the main menu..." << std::endl;
              break;
            }
            default: {
              std::cout << "Invalid choice. Please try again." << std::endl;
              break;
            }
          }
        }
        break;
      }
      case 2: {
        bool employeesRunning = true;
        while (employeesRunning) {
          std::cout << "Employees Menu\n" << std::endl;
          std::cout << "1. Create Employee" << std::endl;
          std::cout << "2. Go Back" << std::endl;
          int employeesChoice;
          std::cout << "Enter your choice: ";
          std::cin >> employeesChoice;
          std::cout << std::endl;
          switch (employeesChoice) {
            case 1: {
              break;
            }
            case 2: {
              employeesRunning = false;
              std::cout << "Going back to the main menu..." << std::endl;
              break;
            }
            default: {
              std::cout << "Invalid choice. Please try again." << std::endl;
              break;
            }
          }
        }
        break;
      }
      case 3: {
        bool bankRunning = true;
        while (bankRunning) {
          std::cout << "Bank Menu\n" << std::endl;
          std::cout << "1. Bank Information" << std::endl;
          std::cout << "2. Customer List" << std::endl;
          std::cout << "3. Employee List" << std::endl;
          std::cout << "4. Go Back" << std::endl;
          int bankChoice;
          std::cout << "Enter your choice: ";
          std::cin >> bankChoice;
          std::cout << std::endl;
          switch (bankChoice) {
            case 1: {
              break;
            }
            case 2: {
              break;
            }
            case 3: {
              break;
            }
            case 4: {
              bankRunning = false;
              std::cout << "Going back to the main menu..." << std::endl;
              break;
            }
            default: {
              std::cout << "Invalid choice. Please try again." << std::endl;
              break;
            }
          }
        }
        break;
      }

      case 4: {
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

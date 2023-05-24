#include <chrono>
#include <iostream>
#include <random>

#include "Account.h"
#include "Bank.h"
#include "Customer.h"
#include "Employee.h"
#include "Manager.h"
#include "Transaction.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<long long> number(0, 9999999999);
std::uniform_int_distribution<long long> emplID(0, 999999);
std::uniform_int_distribution<long long> mgrID(0, 99999);

int main() {
  Bank bank("Uncommonwealth Bank", "123 Main Street", "123-456-7890",
            "info@uncommonwealthbank.com", "customerList.txt",
            "employeeList.txt", "managerList.txt");
  std::cout << "Welcome to the bank management system!!!" << std::endl;

  int mainOption;
  int customerOption;
  int employeeOption;
  int bankOption;

  do {
    std::cout << "\n----- Main Menu -----" << std::endl;
    std::cout << "1. Customers" << std::endl;
    std::cout << "2. Employees" << std::endl;
    std::cout << "3. Bank" << std::endl;
    std::cout << "4. Goodbye" << std::endl;

    std::cout << "Select an option: ";
    std::cin >> mainOption;

    switch (mainOption) {
      case 1: {
        do {
          std::cout << "\n----- Customers Menu -----" << std::endl;
          std::cout << "1. Customer Sign up" << std::endl;
          std::cout << "2. Customer Log in" << std::endl;
          std::cout << "3. Remove Customer" << std::endl;
          std::cout << "4. Go back" << std::endl;

          std::cout << "Select an option: ";
          std::cin >> customerOption;

          switch (customerOption) {
            case 1: {
              std::cout << "\n----- Customer Sign up -----" << std::endl;
              std::string name, address, phone, email;
              std::string accountsListFilename = name + "List.txt";
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
              std::cout << "\nNew Customer added" << std::endl;
              customer.loadUserInfo(name + ".txt");
              break;
            }
            case 2: {
              bool choice = true;
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
                while (choice) {
                  std::string accountsListFilename = name + "List.txt";
                  std::cout << "\n----- Customer Log in -----" << std::endl;
                  std::cout << "1. Add a new account" << std::endl;
                  std::cout << "2. Account log in" << std::endl;
                  std::cout << "3. Delete account" << std::endl;
                  std::cout << "4. Show accounts" << std::endl;
                  std::cout << "5. Go back" << std::endl;

                  std::cout << "Select an option: ";
                  std::cin >> customerOption;

                  switch (customerOption) {
                    case 1: {
                      std::string accountHolderName;
                      std::string accountNumber = std::to_string(number(gen));
                      std::string transactionHistoryFilename =
                          accountNumber + "TransactionHistory";
                      double initialBalance;
                      std::cout << "Enter account holder's name: ";
                      std::cin.ignore();
                      std::getline(std::cin, accountHolderName);
                      std::cout << "Enter initial balance: ";
                      std::cin >> initialBalance;
                      customer.addAccount(accountNumber, accountHolderName,
                                          initialBalance,
                                          transactionHistoryFilename);
                      Account* account = customer.getAccount(accountNumber);
                      customer.saveAccountsList(accountsListFilename,
                                                accountNumber);
                      std::cout << "\nNew account added successfully.\n"
                                << std::endl;
                      std::cout
                          << "Account holder's name: " << accountHolderName
                          << std::endl;
                      std::cout << "Account Number: " << accountNumber
                                << std::endl;
                      std::cout << "Account Balance: " << initialBalance
                                << std::endl;
                      break;
                    }
                    case 2: {
                      // Implement Account log in functionality
                      break;
                    }
                    case 3: {
                      // Implement Delete account functionality
                      break;
                    }
                    case 4: {
                      // Implement Show accounts functionality
                      break;
                    }
                    case 5: {
                      choice = false;
                      break;
                    }
                    default: {
                      std::cout << "Invalid option. Please try again."
                                << std::endl;
                      break;
                    }
                  }
                }
              } else {
                std::cout << "Name or Phone number wrong. Unable to Log in"
                          << std::endl;
              }
              break;
            }
            case 3: {
              // Implement Remove Customer functionality
              break;
            }
            case 4: {
              break;
            }
            default: {
              std::cout << "Invalid option. Please try again." << std::endl;
              break;
            }
          }
        } while (customerOption != 4);
        break;
      }
      case 2: {
        do {
          std::cout << "\n----- Employees Menu -----" << std::endl;
          std::cout << "1. Manager log in" << std::endl;
          std::cout << "2. Go back" << std::endl;

          std::cout << "Select an option: ";
          std::cin >> employeeOption;

          switch (employeeOption) {
            case 1: {
              do {
                std::cout << "\n----- Manager Log in -----" << std::endl;
                std::cout << "1. Add Employee" << std::endl;
                std::cout << "2. Remove Employee" << std::endl;
                std::cout << "3. Add Manager" << std::endl;
                std::cout << "4. Remove Manager" << std::endl;
                std::cout << "5. Go back" << std::endl;

                std::cout << "Select an option: ";
                std::cin >> employeeOption;

                switch (employeeOption) {
                  case 1: {
                    // Implement Add Employee functionality
                    break;
                  }
                  case 2: {
                    // Implement Remove Employee functionality
                    break;
                  }
                  case 3: {
                    // Implement Add Manager functionality
                    break;
                  }
                  case 4: {
                    // Implement Remove Manager functionality
                    break;
                  }
                  case 5: {
                    break;
                  }
                  default: {
                    std::cout << "Invalid option. Please try again."
                              << std::endl;
                    break;
                  }
                }
              } while (employeeOption != 5);
              break;
            }
            case 2: {
              break;
            }
            default: {
              std::cout << "Invalid option. Please try again." << std::endl;
              break;
            }
          }
        } while (employeeOption != 2);
        break;
      }
      case 3: {
        do {
          std::cout << "\n----- Bank Menu -----" << std::endl;
          std::cout << "1. Bank information" << std::endl;
          std::cout << "2. Customer list" << std::endl;
          std::cout << "3. Employee list" << std::endl;
          std::cout << "4. Manager list" << std::endl;
          std::cout << "5. Go back" << std::endl;

          std::cout << "Select an option: ";
          std::cin >> bankOption;

          switch (bankOption) {
            case 1: {
              // Implement Bank information functionality
              break;
            }
            case 2: {
              // Implement Customer list functionality
              break;
            }
            case 3: {
              // Implement Employee list functionality
              break;
            }
            case 4: {
              // Implement Manager list functionality
              break;
            }
            case 5: {
              break;
            }
            default: {
              std::cout << "Invalid option. Please try again." << std::endl;
              break;
            }
          }
        } while (bankOption != 5);
        break;
      }
      case 4: {
        std::cout << "Goodbye!" << std::endl;
        return 0;
      }
      default: {
        std::cout << "Invalid option. Please try again." << std::endl;
        break;
      }
    }
  } while (true);

  return 0;
}

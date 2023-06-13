#include <chrono>
#include <iostream>
#include <random>

#include "Account.h"
#include "Bank.h"
#include "Customer.h"
#include "Employee.h"
#include "Manager.h"
#include "Transaction.h"
#include "User.h"
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<long long> number(0, 9999999999);
uniform_int_distribution<long long> emplID(0, 999999);
uniform_int_distribution<long long> mgrID(0, 99999);

int main() {
  Bank bank("Uncommonwealth Bank", "123 Main Street", "123-456-7890",
            "info@uncommonwealthbank.com", "customerList.txt",
            "employeeList.txt", "managerList.txt");
  cout << "Welcome to the bank management system!!!" << endl;

  int mainOption;
  int customerOption;
  int bankOption;

  do {
    cout << "\n----- Main Menu -----" << endl;
    cout << "1. Customers" << endl;
    cout << "2. Employees" << endl;
    cout << "3. Bank" << endl;
    cout << "4. Goodbye" << endl;

    cout << "Select an option: ";
    cin >> mainOption;

    switch (mainOption) {
      case 1: {
        do {
          cout << "\n----- Customers Menu -----" << endl;
          cout << "1. Customer Sign up" << endl;
          cout << "2. Customer Log in" << endl;
          cout << "3. Remove Customer" << endl;
          cout << "4. Go back" << endl;

          cout << "Select an option: ";
          cin >> customerOption;

          switch (customerOption) {
            case 1: {
              cout << "\n----- Customer Sign up -----" << endl;
              string name, address, phone, email;
              string accountsListFilename = name + "_accounts.txt";
              cout << "Enter customer's name: ";
              cin.ignore();
              getline(cin, name);
              cout << "Enter customer's address: ";
              getline(cin, address);
              cout << "Enter customer's phone number: ";
              cin >> phone;
              cout << "Enter customer's email: ";
              cin >> email;
              Customer customer(name, address, phone, email);
              customer.saveCustomerInfo(name + ".txt");
              bank.addCustomer(&customer);
              bank.saveCustomerList("customerList.txt");
              cout << "\nNew Customer added" << endl;
              customer.loadUserInfo(name + ".txt");
              break;
            }
            case 2: {
              bool choice = true;
              string name, phone;
              cout << "Enter customer's name: ";
              cin.ignore();
              getline(cin, name);
              cout << "Enter customer's phone number: ";
              getline(cin, phone);
              Customer customer(name, "", phone, "");
              bool loginSuccessful = customer.customerLogin(name, phone);
              if (loginSuccessful) {
                cout << "\nLogin successful!" << endl;
                while (choice) {
                  string accountsListFilename = name + "_accounts.txt";
                  cout << "\n----- Customer Log in -----" << endl;
                  cout << "1. Add a new account" << endl;
                  cout << "2. Account log in" << endl;
                  cout << "3. Delete account" << endl;
                  cout << "4. Show accounts" << endl;
                  cout << "5. Go back" << endl;

                  cout << "Select an option: ";
                  cin >> customerOption;

                  switch (customerOption) {
                    case 1: {
                      string accountHolderName;
                      string accountNumber = to_string(number(gen));
                      string transactionHistoryFilename =
                          accountNumber + "TransactionHistory";
                      double initialBalance;
                      cout << "Enter account holder's name: ";
                      cin.ignore();
                      getline(cin, accountHolderName);
                      cout << "Enter initial balance: ";
                      cin >> initialBalance;
                      customer.addAccount(accountNumber, accountHolderName,
                                          initialBalance,
                                          transactionHistoryFilename);
                      customer.getAccount(accountNumber);
                      customer.saveAccountsList(accountsListFilename,
                                                accountNumber);
                      cout << "\nNew account added successfully.\n" << endl;
                      cout << "Account holder's name: " << accountHolderName
                           << endl;
                      cout << "Account Number: " << accountNumber << endl;
                      cout << "Account Balance: " << initialBalance << endl;
                      break;
                    }
                    case 2: {
                      string accountNumber;
                      cout << "Enter account number: ";
                      cin >> accountNumber;
                      cout << endl;
                      Account* account = customer.getAccount(accountNumber);
                      string accountHolderName =
                          account->getAccountHolderName();
                      if (account != nullptr) {
                        bool continueLoop = true;
                        while (continueLoop) {
                          string accountsListFilename = name + "_accounts.txt";
                          cout << "\n----- Customer Log in -----" << endl;
                          cout << "1. Deposit" << endl;
                          cout << "2. Withdraw" << endl;
                          cout << "3. Transfer" << endl;
                          cout << "4. Account Information" << endl;
                          cout << "5. Transaction History" << endl;
                          cout << "6. Go back" << endl;

                          cout << "Select an option: ";
                          cin >> customerOption;

                          switch (customerOption) {
                            case 1: {
                              double amount;
                              cout << "Enter the amount to deposit: ";
                              cin >> amount;
                              account->deposit(accountHolderName, amount);
                              account->saveTransactionHistory(
                                  accountNumber + "_TransactionHistory.txt");
                              cout << "Amount deposited successfully." << endl;
                              break;
                            }
                            case 2: {
                              double amount;
                              cout << "Enter the amount to withdraw: ";
                              cin >> amount;
                              if (account->withdraw(accountHolderName,
                                                    amount)) {
                                account->saveTransactionHistory(
                                    accountNumber + "_TransactionHistory.txt");
                                cout << "Amount withdrawn successfully."
                                     << endl;
                              } else {
                                cout << "Insufficient funds. Withdrawal failed."
                                     << endl;
                              }
                              break;
                            }
                            case 3: {
                              string transferToAccountNumber;
                              cout << "Enter the account number to "
                                      "transfer to: ";
                              cin >> transferToAccountNumber;
                              double transferAmount;
                              cout << "Enter the amount to transfer: ";
                              cin >> transferAmount;
                              if (account->transfer(transferToAccountNumber,
                                                    transferAmount)) {
                                cout << "Amount transferred successfully."
                                     << endl;
                                account->saveTransactionHistory(
                                    accountNumber + "_TransactionHistory.txt");
                                account->saveReciepentTransactionHistory(
                                    transferToAccountNumber +
                                    "_TransactionHistory.txt");
                              } else {
                                cout << "Transfer failed. Please check the "
                                        "account numbers and available balance."
                                     << endl;
                              }
                              break;
                            }
                            case 4: {
                              cout << "Account information:\n" << endl;
                              cout << "Account holder's name: "
                                   << account->getAccountHolderName() << endl;
                              cout << "Account number: "
                                   << account->getAccountNumber() << endl;
                              cout << "Account balance: "
                                   << account->getAccountBalance() << endl;
                              break;
                            }
                            case 5: {
                              cout << "\n-----Transaction History for Account "
                                      "NO: "
                                   << accountNumber << "-----\n"
                                   << endl;
                              account->loadTransactionHistory(
                                  accountNumber + "_TransactionHistory.txt");
                              break;
                            }
                            case 6: {
                              continueLoop = false;
                              break;
                            }
                            default: {
                              cout << "Invalid option. Please try again."
                                   << endl;
                              cin.clear();
                              cin.ignore(numeric_limits<streamsize>::max(),
                                         '\n');
                              break;
                            }
                          }
                        }
                      } else {
                        cout << "Account not found. Please try again." << endl;
                      }
                      break;
                    }
                    case 3: {
                      string accountNumber;
                      cout << "Enter account number: ";
                      cin >> accountNumber;
                      cout << endl;
                      Account* account = customer.getAccount(accountNumber);
                      if (account != nullptr) {
                        cout << "Are you sure you want to delete this account? "
                                "(y/n): ";
                        char confirm;
                        cin >> confirm;
                        cout << endl;
                        if (confirm == 'y') {
                          customer.deleteAccount(accountNumber);
                          cout << "Account deleted successfully." << endl;
                        }
                      } else {
                        choice = false;
                        cout << "Going back to the main menu..." << endl;
                      }
                      break;
                    }
                    case 4: {
                      customer.loadAccountsList(accountsListFilename);
                      break;
                    }
                    case 5: {
                      choice = false;
                      break;
                    }
                    default: {
                      cout << "Invalid option. Please try again." << endl;
                      cin.clear();
                      cin.ignore(numeric_limits<streamsize>::max(), '\n');
                      break;
                    }
                  }
                }
              } else {
                cout << "Name or Phone number wrong. Unable to Log in" << endl;
              }
              break;
            }
            case 3: {
              string name, phone;
              cout << "Enter Customer's name: ";
              cin.ignore();
              getline(cin, name);
              cout << "Enter Customer's phone number: ";
              getline(cin, phone);
              Customer customer(name, "", phone, "");
              if (customer.checkCustomerDetails(name, phone) == true) {
                cout << "Are you sure you want to delete this Customer? "
                        "(y/n): ";
                char confirm;
                cin >> confirm;
                cout << endl;
                if (confirm == 'y') {
                  bank.removeCustomer(&customer);
                  cout << "\nCustomer has been successfully removed\n" << endl;
                } else {
                  cout << "Going back to the main menu..." << endl;
                  break;
                }
              } else {
                cout << "Wrong details" << endl;
                break;
              }
              break;
            }
            case 4: {
              cout << "Going back to main menu..." << endl;
              break;
            }
            default: {
              cout << "Invalid option. Please try again." << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              break;
            }
          }
        } while (customerOption != 4);
        break;
      }
      case 2: {
        cout << "\n----- Employees Menu -----" << endl;
        cout << "1. Manager log in" << endl;
        cout << "2. Go back" << endl;
        int employeesChoice;
        cout << "Enter your choice: ";
        cin >> employeesChoice;
        cout << endl;
        switch (employeesChoice) {
          case 1: {
            string name, id;
            cout << "Manager Login\n" << endl;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter your ID: ";
            cin >> id;
            cout << endl;
            Manager manager;
            if (manager.managerLogin(name, id)) {
              bool managerLoggedIn = true;
              while (managerLoggedIn) {
                cout << "\n----- Manager Log in -----" << endl;
                cout << "1. Add Employee" << endl;
                cout << "2. Remove Employee" << endl;
                cout << "3. Add Manager" << endl;
                cout << "4. Remove Manager" << endl;
                cout << "5. Go back" << endl;
                int managerChoice;
                cout << "Enter your choice: ";
                cin >> managerChoice;
                cout << endl;
                switch (managerChoice) {
                  case 1: {
                    string empName, empPhone, empDepartment, empEmail,
                        empId = to_string(emplID(gen));
                    cout << "Enter employee name: ";
                    cin.ignore();
                    getline(cin, empName);
                    cout << "Enter employee phone: ";
                    getline(cin, empPhone);
                    cout << "Enter employee department: ";
                    getline(cin, empDepartment);
                    cout << "Enter employee email: ";
                    getline(cin, empEmail);
                    Employee employee(empName, empId, empDepartment, empEmail,
                                      empPhone);
                    employee.saveEmployeeInfo(empName + ".txt");
                    bank.addEmployee(&employee);
                    bank.saveEmployeeList("employeeList.txt");
                    cout << "\nNew Employee added" << endl;
                    employee.loadUserInfo(empName + ".txt");
                    break;
                  }
                  case 2: {
                    string name, id;
                    cout << "Enter Employee's name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Employee's ID number: ";
                    getline(cin, id);
                    Employee employee(name, id, "", "", "");
                    if (employee.checkEmployeeDetails(name, id) == true) {
                      cout << "Are you sure you want to delete this Employee? "
                              "(y/n): ";
                      char confirm;
                      cin >> confirm;
                      cout << endl;
                      if (confirm == 'y') {
                        bank.removeEmployee(&employee);
                        cout << "\nEmployee has been successfully removed\n"
                             << endl;
                      } else {
                        managerLoggedIn = false;
                        cout << "Going back to the main menu..." << endl;
                      }
                    } else {
                      cout << "Wrong details" << endl;
                      managerLoggedIn = false;
                    }
                    break;
                  }
                  case 3: {
                    // Create Manager
                    string mgrName, mgrPhone, mgrEmail, mgrDepartment,
                        mgrId = to_string(mgrID(gen));
                    cout << "Enter manager name: ";
                    cin.ignore();
                    getline(cin, mgrName);
                    cout << "Enter manager phone: ";
                    getline(cin, mgrPhone);
                    cout << "Enter manager email: ";
                    getline(cin, mgrEmail);
                    cout << "Enter manager department: ";
                    getline(cin, mgrDepartment);
                    Manager newManager(mgrName, mgrId, mgrDepartment, mgrEmail,
                                       mgrPhone);
                    newManager.saveEmployeeInfo(mgrName + ".txt");
                    bank.addManager(&newManager);
                    bank.saveManagerList("managerList.txt");
                    cout << "\nNew Manager added" << endl;
                    newManager.loadUserInfo(mgrName + ".txt");
                    break;
                  }
                  case 4: {
                    string name, id;
                    cout << "Enter Manager's name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Manager's ID number: ";
                    getline(cin, id);
                    Manager manager(name, id, "", "", "");
                    if (manager.checkManagerDetails(name, id) == true) {
                      cout << "Are you sure you want to delete this Manager? "
                              "(y/n): ";
                      char confirm;
                      cin >> confirm;
                      cout << endl;
                      if (confirm == 'y') {
                        bank.removeManager(&manager);
                        cout << "\nManager has been successfully removed\n"
                             << endl;
                      } else {
                        managerLoggedIn = false;
                        cout << "Going back to the main menu..." << endl;
                      }
                    } else {
                      cout << "Wrong details" << endl;
                      managerLoggedIn = false;
                    }

                    break;
                  }
                  case 5: {
                    managerLoggedIn = false;
                    cout << "Going back to the Employees Menu..." << endl;
                    break;
                  }
                  default: {
                    cout << "Invalid choice. Please try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                  }
                }
              }
            } else {
              cout << "Invalid login credentials. Please try again." << endl;
            }
            break;
          }
          case 2: {
            cout << "Going back to the main menu..." << endl;
            break;
          }
          default: {
            cout << "Invalid choice. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
          }
        }
        break;
      }
      case 3: {
        do {
          cout << "\n----- Bank Menu -----" << endl;
          cout << "1. Bank information" << endl;
          cout << "2. Customer list" << endl;
          cout << "3. Employee list" << endl;
          cout << "4. Manager list" << endl;
          cout << "5. Go back" << endl;

          cout << "Select an option: ";
          cin >> bankOption;

          switch (bankOption) {
            case 1: {
              cout << "\n-----Bank Information-----" << endl;
              bank.displayBankInformation(bank);
              break;
            }
            case 2: {
              cout << "\n-----Customer List-----" << endl;
              bank.displayCustomerList(bank);
              break;
            }
            case 3: {
              cout << "\n-----Employee List-----" << endl;
              bank.displayEmployeeList(bank);
              break;
            }
            case 4: {
              cout << "\n-----Manager List-----" << endl;
              bank.displayManagerList(bank);
              break;
            }
            case 5: {
              break;
            }
            default: {
              cout << "Invalid option. Please try again." << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              break;
            }
          }
        } while (bankOption != 5);
        break;
      }
      case 4: {
        cout << "Goodbye!" << endl;
        return 0;
      }
      default: {
        cout << "Invalid option. Please try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
      }
    }
  } while (true);

  return 0;
}

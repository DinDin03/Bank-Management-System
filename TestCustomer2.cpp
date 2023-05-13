#include <iostream>
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"

int main() {
    std::cout << "Welcome to the banking system!" << std::endl;
    bool running = true;
    while (running) {
        std::cout << "Please choose an option:" << std::endl;
        std::cout << "1. Create a new customer" << std::endl;
        std::cout << "2. Quit" << std::endl;
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::string name, address, phone, email;
                std::cout << "Enter customer's name: ";
                std::cin >> name;
                std::cout << std::endl;
                std::cout << "Enter customer's address: ";
                std::cin >> address;
                std::cout << std::endl;
                std::cout << "Enter customer's phone number: ";
                std::cin >> phone;
                std::cout << std::endl;
                std::cout << "Enter customer's email: ";
                std::cin >> email;
                std::cout << std::endl;
                Customer customer(name, address, phone, email);
                customer.saveCustomerInfo(name + ".txt");
                std::cout << "New customer information saved." << std::endl;
                std::cout << "Customer's name: " << customer.getName() << std::endl;
                std::cout << "Customer's address: " << customer.getAddress() << std::endl;
                std::cout << "Customer's phone number: " << customer.getPhone() << std::endl;
                std::cout << "Customer's email: " << customer.getEmail() << std::endl;
                break;
            }
            case 2: {
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

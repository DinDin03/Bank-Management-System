#include <iostream>
#include "Bank.h"
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"
#include "Employee.h"

int main() {
    // Create a Bank object
    Bank bank("MyBank", "123 Main Street", "123-456-7890", "info@mybank.com", "customerListTest.txt","employeeListTest.txt");

    // Create some customer objects
    Customer* customer1 = new Customer("John Doe", "5/14", "046576463", "Dineth.Himash@");
    Customer* customer2 = new Customer("Jane Smith", "5/14", "046576463", "Dineth.Himash@");
    Customer* customer3 = new Customer("David Johnson", "5/14", "046576463", "Dineth.Himash@");

    // Add customers to the bank
    bank.addCustomer(customer1);
    bank.addCustomer(customer2);
    bank.addCustomer(customer3);
    bank.saveCustomerList("customerList.txt");

    int choice;
    do {
        // Display menu
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. View Bank Information" << std::endl;
        std::cout << "2. View Customer List" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                bank.displayBankInformation(bank);
                break;
            case 2:
                bank.displayCustomerList(bank);
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 0);

    // Remove customers and clean up memory
    bank.removeCustomer(customer1);
    bank.removeCustomer(customer2);
    bank.removeCustomer(customer3);
    delete customer1;
    delete customer2;
    delete customer3;

    // Save the customer list to the file
    bank.saveCustomerList("customerListTest.txt");

    return 0;
}
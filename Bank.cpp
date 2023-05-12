#include "Bank.h"
#include <algorithm>

// Adds the specified customer to the list of customers associated with the bank.
void Bank::addCustomer(Customer* customer) {
    customers.push_back(customer);
}

// Removes the specified customer from the list of customers associated with the bank.
void Bank::removeCustomer(Customer* customer) {
    customers.erase(std::remove(customers.begin(), customers.end(), customer), customers.end());
}

// Returns the name of the bank.
std::string Bank::getBankName() const {
    return bankName;
}

// Returns the address of the bank.
std::string Bank::getBankAddress() const {
    return bankAddress;
}

// Returns the phone number of the bank.
std::string Bank::getBankPhone() const {
    return bankPhone;
}

// Returns the email address of the bank.
std::string Bank::getBankEmail() const {
    return bankEmail;
}

// Returns a list of customers associated with the bank.
std::vector<Customer*> Bank::getCustomers() const {
    return customers;
}

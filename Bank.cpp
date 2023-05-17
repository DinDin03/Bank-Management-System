#include "Bank.h"
#include <sstream>

Bank::Bank(const std::string& bankName, const std::string& bankAddress, const std::string& bankPhone, const std::string& bankEmail, const std::string& customerListFilename, const std::string& employeeListFilename)
    : bankName(bankName), bankAddress(bankAddress), bankPhone(bankPhone), bankEmail(bankEmail), customerListFilename(customerListFilename), employeeListFilename(employeeListFilename)
{
    loadCustomerList("customerList.txt");
    loadEmployeeList("employeeList.txt");
}

Bank::~Bank() {
    for (Customer* customer : customers) {
        delete customer;
    }
}

void Bank::addCustomer(Customer* customer) {
    customers.push_back(customer);

    // Update the customer list file
    std::ofstream outFile(customerListFilename, std::ios::app); // Open the file in append mode
    if (outFile.is_open()) {
        outFile << customer->getName() << "\n"; // Add the new customer's name to the file
        outFile.close();
    }
}

void Bank::removeCustomer(Customer* customer) {
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (*it == customer) {
            customers.erase(it);
            delete customer;
            break;
        }
    }

    // Update the customer list file
    std::ofstream outFile(customerListFilename);
    if (outFile.is_open()) {
        for (const auto& customer : customers) {
            outFile << customer->getName() << "\n";
        }
        outFile.close();
    }
}
void Bank::addEmployee(Employee* employee) {
    employees.push_back(employee);

    // Update the customer list file
    std::ofstream outFile(employeeListFilename, std::ios::app); // Open the file in append mode
    if (outFile.is_open()) {
        outFile << employee->getEmployeeName() << "\n"; // Add the new customer's name to the file
        outFile.close();
    }
}

void Bank::removeEmployee(Employee* employee) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (*it == employee) {
            employees.erase(it);
            delete employee;
            break;
        }
    }
    std::ofstream outFile(employeeListFilename);
    if (outFile.is_open()) {
        for (const auto& employee : employees) {
            outFile << employee->getEmployeeName() << "\n";
        }
        outFile.close();
    }
}

std::string Bank::getBankName() const {
    return bankName;
}

std::string Bank::getBankAddress() const {
    return bankAddress;
}

std::string Bank::getBankPhone() const {
    return bankPhone;
}

std::string Bank::getBankEmail() const {
    return bankEmail;
}

std::vector<Customer*> Bank::getCustomers() const {
    return customers;
}

std::vector<Employee*> Bank::getEmployees() const {
    return employees;
}

void Bank::saveCustomerList(std::string customerListFilename) const {
    std::ofstream outFile(customerListFilename);
    if (outFile.is_open()) {
        for (const auto& customer : customers) {
            outFile << customer->getName() << "\n";
        }
        outFile.close();
    }
}

void Bank::loadCustomerList(std::string customerListFilename) {
    std::ifstream file(customerListFilename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream iss(line);
            std::string name, address, phone, email;
            if (std::getline(iss, name, ',') && std::getline(iss, address, ',') &&
                std::getline(iss, phone, ',') && std::getline(iss, email)) {
                Customer* customer = new Customer(name, address, phone, email);
                customers.push_back(customer);
            }
        }
        file.close();
    }
}
void Bank::saveEmployeeList(std::string employeeListFilename) const {
    std::ofstream outFile(employeeListFilename);
    if (outFile.is_open()) {
        for (const auto& employee : employees) {
            outFile << employee->getEmployeeName() << "\n";
        }
        outFile.close();
    }
}

void Bank::loadEmployeeList(std::string employeeListFilename) {
    std::ifstream file(employeeListFilename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream iss(line);
            std::string name, phone, email, id, department;
            if (std::getline(iss, name, ',') && std::getline(iss, id, ',') &&
                std::getline(iss, phone, ',') && std::getline(iss, email) && std::getline(iss, department)) {
                Employee* employee = new Employee(name, id, department, email, phone);
                employees.push_back(employee);
            }
        }
        file.close();
    }
}
void Bank::displayBankInformation(const Bank& bank) {
    std::cout << "Bank Name: " << bank.getBankName() << std::endl;
    std::cout << "Bank Address: " << bank.getBankAddress() << std::endl;
    std::cout << "Bank Phone: " << bank.getBankPhone() << std::endl;
    std::cout << "Bank Email: " << bank.getBankEmail() << std::endl;
}

void Bank::displayCustomerList(const Bank& bank) {
    std::cout << "Customers:" << std::endl;
    std::vector<Customer*> customers = bank.getCustomers();
    for (const auto& customer : customers) {
        std::cout << " - " << customer->getName() << std::endl;
    }
}
void Bank::displayEmployeeList(const Bank& bank) {
    std::cout << "Employees:" << std::endl;
    std::vector<Employee*> employees = bank.getEmployees();
    for (const auto& employee : employees) {
        std::cout << " - " << employee->getEmployeeName() << std::endl;
    }
}



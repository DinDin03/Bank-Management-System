#include <iostream>
#include "Employee.h"

int main() {
    // Create an employee object
    Employee employee("John Doe", "12345", "IT Department", "john.doe@example.com", "1234567890");

    // Get and display employee information
    std::cout << "Employee Name: " << employee.getEmployeeName() << std::endl;
    std::cout << "Employee ID: " << employee.getEmployeeID() << std::endl;
    std::cout << "Department: " << employee.getDepartment() << std::endl;
    std::cout << "Email: " << employee.getEmail() << std::endl;
    std::cout << "Phone: " << employee.getPhone() << std::endl;

    // Update employee information
    employee.setName("Jane Smith");
    employee.setDepartment("HR Department");
    employee.setEmail("jane.smith@example.com");
    employee.setPhone("9876543210");

    // Display updated employee information
    std::cout << "\nUpdated Employee Information:" << std::endl;
    std::cout << "Employee Name: " << employee.getEmployeeName() << std::endl;
    std::cout << "Department: " << employee.getDepartment() << std::endl;
    std::cout << "Email: " << employee.getEmail() << std::endl;
    std::cout << "Phone: " << employee.getPhone() << std::endl;

    // Save employee information to a file
    employee.saveEmployeeInfo("employee_info.txt");
    std::cout << "\nEmployee information saved to file." << std::endl;

    // Load employee information from a file
    Employee loadedEmployee("", "0", "", "", "");  // Create an empty employee object
    loadedEmployee.loadEmployeeInfo("employee_info.txt");
    std::cout << "\nLoaded Employee Information:" << std::endl;
    std::cout << "Employee Name: " << loadedEmployee.getEmployeeName() << std::endl;
    std::cout << "Employee ID: " << loadedEmployee.getEmployeeID() << std::endl;
    std::cout << "Department: " << loadedEmployee.getDepartment() << std::endl;
    std::cout << "Email: " << loadedEmployee.getEmail() << std::endl;
    std::cout << "Phone: " << loadedEmployee.getPhone() << std::endl;

    // Employee login
    std::string name, phone;
    std::cout << "\nEnter employee name: ";
    std::getline(std::cin, name);
    std::cout << "Enter employee phone number: ";
    std::getline(std::cin, phone);
    if (loadedEmployee.employeeLogin(name, phone)) {
        std::cout << "Login successful." << std::endl;
    } else {
        std::cout << "Login failed. Invalid credentials." << std::endl;
    }

    return 0;
}

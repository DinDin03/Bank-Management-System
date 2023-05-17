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
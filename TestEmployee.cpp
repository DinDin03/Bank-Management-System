case 2: {
    std::string name, phone;
    std::cout << "Enter customer's name: ";
    std::cin >> name;
    std::cout << std::endl;
    std::cout << "Enter customer's phone number: ";
    std::cin >> phone;
    std::cout << std::endl;
    Customer customer(name, "", phone, "");
    bool loginSuccessful = customer.customerLogin(name, phone);
    if (loginSuccessful) {
        std::cout << "Login successful!" << std::endl;

        int accountChoice;
        while (true) {
            std::cout << "Please choose an option:" << std::endl;
            std::cout << "1. Create new account" << std::endl;
            std::cout << "2. Log in to existing account" << std::endl;
            std::cout << "3. Delete account" << std::endl;
            std::cout << "4. Logout" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> accountChoice;
            switch (accountChoice) {
                case 1: {
                    std::string accountHolderName;
                    double initialBalance;
                    std::cout << "Enter account holder's name: ";
                    std::cin >> accountHolderName;
                    std::cout << std::endl;
                    std::cout << "Enter initial balance: ";
                    std::cin >> initialBalance;
                    std::cout << std::endl;
                    customer.addAccount(accountHolderName, initialBalance);
                    std::cout << "New account added successfully." << std::endl;
                    std::cout << "Account holder's name: " << accountHolderName << std::endl;
                    std::cout << "Account number: " << customer.getAccounts().back().getAccountNumber() << std::endl;
                    std::cout << "Account balance: " << customer.getAccounts().back().getBalance() << std::endl;
                    break;
                }
                case 2: {
                    std::string accountNumber;
                    std::cout << "Enter account number: ";
                    std::cin >> accountNumber;
                    std::cout << std::endl;
                    Account* account = customer.findAccount(accountNumber);
                    if (account != nullptr) {
                        std::cout << "Account balance: " << account->getBalance() << std::endl;
                    } else {
                        std::cout << "Account not found. Please try again." << std::endl;
                    }
                    break;
                }
                case 3: {
                    std::string accountNumber;
                    std::cout << "Enter account number: ";
                    std::cin >> accountNumber;
                    std::cout << std::endl;
                    Account* account = customer.findAccount(accountNumber);
                    if (account != nullptr) {
                        std::cout << "Are you sure you want to delete this account? (y/n): ";
                        char confirm;
                        std::cin >> confirm;
                        std::cout << std::endl;
                        if (confirm == 'y') {
                            customer.deleteAccount(accountNumber);
                            std::cout << "Account deleted successfully." << std::endl;
                        }
                    } else {
                        std::cout << "Account not found. Please try again." << std::endl;
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

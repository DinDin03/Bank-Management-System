#include "user.h"
#include <iostream>

User::User(const std::string& name, const std::string& phone, const std::string& email)
    : name(name), phone(phone), email(email) {}

std::string User::getName() const {
    return name;
}

std::string User::getPhone() const {
    return phone;
}

std::string User::getEmail() const{
    return email;
}

void User::setName(const std::string& newName) {
    name = newName;
}

void User::setPhone(const std::string& newPhone) {
    phone = newPhone;
}

void User::setEmail(const std::string& newEmail){
    email = newEmail;
}
void User::loadUserInfo(std::string filename){
    std::cout << "User's name is: " << name << std::endl;
    std::cout << "User's phone is: " << phone << std::endl;
    std::cout << "User's email is: " << email << std::endl;
}
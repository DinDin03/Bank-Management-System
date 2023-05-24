#include "user.h"

#include <iostream>
using namespace std;

User::User(const string& name, const string& phone, const string& email)
    : name(name), phone(phone), email(email) {}

string User::getName() const { return name; }

string User::getPhone() const { return phone; }

string User::getEmail() const { return email; }

void User::setName(const string& newName) { name = newName; }

void User::setPhone(const string& newPhone) { phone = newPhone; }

void User::setEmail(const string& newEmail) { email = newEmail; }
void User::loadUserInfo(string filename) {
  cout << "User's name is: " << name << endl;
  cout << "User's phone is: " << phone << endl;
  cout << "User's email is: " << email << endl;
}
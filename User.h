#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string name;
    std::string phone;
    std::string email;
    std::string filename;

public:
    User(const std::string& name, const std::string& phone, const std::string& email);
    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    void setName(const std::string& newName);
    void setPhone(const std::string& newPhone);
    void setEmail(const std::string& newEmail);
    virtual void loadUserInfo(std::string filename);
};

#endif  // USER_H

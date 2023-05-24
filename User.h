#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
 protected:
  string name;
  string phone;
  string email;
  string filename;

 public:
  User(const string& name, const string& phone, const string& email);
  string getName() const;
  string getPhone() const;
  string getEmail() const;
  void setName(const string& newName);
  void setPhone(const string& newPhone);
  void setEmail(const string& newEmail);
  virtual void loadUserInfo(string filename);
};

#endif  // USER_H

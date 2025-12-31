#include <iostream>
#include <vector>
using std::string;

class User_Account {
    string login;
    string password;

public:
    User_Account(string login, string password) : login(login), password(password) {}

    string getLogin() const;

    string getPassword() const;

    void setPassword(const string& password);
};

inline string User_Account::getLogin() const
{
    return login;
}

inline string User_Account::getPassword() const
{
    return password;
}

inline void User_Account::setPassword(const string& password)
{
    this->password = password;
}

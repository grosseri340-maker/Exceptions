#include "User_Account.h"
#include "MyException.h"

class SocialNetwork
{
    vector<User_Account> accounts;

    bool isValidPassword(const string& pass)
    {
        if (pass.length() <= 7)
            throw WrongPasswordLengthException();

        bool hasDigit = false, hasUpper = false, hasLower = false, hasSymbol = false;

        for (char c : pass)
        {
            if (isdigit(c)) hasDigit = true;
            else if (isupper(c)) hasUpper = true;
            else if (islower(c)) hasLower = true;
            else hasSymbol = true;
        }

        if (!(hasDigit and hasUpper and hasLower and hasSymbol))
            throw FormatPasswordException();

        return true;
    }

public:
    void registerUser(const string& login, const string& pass)
    {
        for (const auto& u : accounts)
        {
            if (u.getLogin() == login)
                throw ExistLoginException();
        }

        isValidPassword(pass);

        accounts.emplace_back(login, pass);
        cout << "User registered successfully!\n";
    }

    void loginUser(const string& login, const string& pass)
    {
        for (const auto& u : accounts)
        {
            if (u.getLogin() == login)
            {
                if (u.getPassword() == pass)
                {
                    cout << "Login successful!\n";
                    return;
                }
                else
                    throw InvalidPasswordException();
            }
        }
        throw InvalidLoginException();
    }

    void changePassword(const string& login, const string& newPass)
    {
        for (auto& u : accounts)
        {
            if (u.getLogin() == login)
            {
                isValidPassword(newPass);
                u.setPassword(newPass);
                cout << "Password changed successfully!\n";
                return;
            }
        }
        throw InvalidLoginException();
    }
};
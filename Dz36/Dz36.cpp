#include <iostream>
#include "SocialNetwork.h"

int main()
{
    SocialNetwork sn;

    try
    {
        sn.registerUser("admin", "111AaA1!");
        sn.registerUser("admin", "12345");
    }
    catch (const MyException& e)
    {
        cout << "Registration error: " << e.what() << endl;
    }

    try
    {
        sn.loginUser("admin", "111AaA1!");
        sn.loginUser("admin", "2");
    }
    catch (const MyException& e)
    {
        cout << "Login error: " << e.what() << endl;
    }
}
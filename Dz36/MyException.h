#pragma once
#include<iostream>
using namespace std;

class MyException
{
public:
	MyException(const string& message = "Unknown", const double& value = 0)
		:message(message), value(value)
	{
	}
	virtual const string& what() const
	{
		return message;
	}
	virtual const double& getValue() const
	{
		return value;
	}
private:
	string message;
	double value;
};

class ExistLoginException : public MyException
{
public:
	ExistLoginException()
		: MyException("Login already exists") {
	}
};

class WrongPasswordLengthException : public MyException
{
public:
	WrongPasswordLengthException()
		: MyException("Password length must be more than 7 characters") {
	}
};

class FormatPasswordException : public MyException
{
public:
	FormatPasswordException()
		: MyException("Password must contain digit, upper, lower letter and special symbol") {
	}
};

class InvalidLoginException : public MyException
{
public:
	InvalidLoginException()
		: MyException("Invalid login") {
	}
};

class InvalidPasswordException : public MyException
{
public:
	InvalidPasswordException()
		: MyException("Invalid password") {
	}
};
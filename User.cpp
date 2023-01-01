#include "User.h"
#include <string>
#include <iomanip>

User::User(const std::string& login, const std::string& password, const std::string& name) : login_(login), password_(password), name_(name) {}

void User::setName(const std::string& name)
{
	name_ = name;
}

const std::string& User::getName() const
{
	return name_;
}

void User::setLogin(const std::string& login)
{
	login_ = login;
}

const std::string& User::getLogin() const
{
	return login_;
}

void User::setPassword(const std::string& password)
{
	password_ = password;
}

const std::string& User::getPassword() const
{
	return password_;
}
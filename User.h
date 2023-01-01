#pragma once
#include <string>
#include <fstream>

class User
{
	std::string name_;
	std::string login_;
	std::string password_;
public:
	User(const std::string&, const std::string&, const std::string&);
	User(const std::string&, const std::string&);


	void setName(const std::string&);
	const std::string& getName() const;

	void setLogin(const std::string&);
	const std::string& getLogin() const;

	void setPassword(const std::string&);
	const std::string& getPassword() const;
};
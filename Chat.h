#pragma once
#include "User.h"
#include "Message.h"
#include <vector>
//#include <memory>
#include <iostream>

class Chat
{
	bool isChatWorking_ = false;
	std::vector<User> users_;
	std::vector<Message> messages_;
	std::shared_ptr<User> currUser_ = nullptr;
public:
	void createChat();
	bool isChatWorking();
	void regIn();
	void logIn();
	void chatOptions();
	void userOptions();
	void writeMessage();
	void showMessages();
	std::shared_ptr<User> getUserByName(const std::string&) const;
	std::shared_ptr<User> getUserByLogin(const std::string&) const;
	std::shared_ptr<User> getCurrUser() const;

};


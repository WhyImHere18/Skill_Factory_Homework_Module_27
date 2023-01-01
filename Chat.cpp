#include "Chat.h"
#include "Message.h"
#include "User.h"
#include <vector>
#include <iostream>
#include <map>
#include "Logger.h"
#include <iomanip>

Logger& logger = Logger::instance();


void Chat::createChat()
{
	isChatWorking_ = true;
	logger.getLog_file().seekg(0, std::ios_base::end);
}

bool Chat::isChatWorking()
{
	return isChatWorking_;
}

void Chat::regIn()
{
	std::string login;
	std::string password;
	std::string name;

	std::cout << "Enter login: ";
	std::cin >> login;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (User user : users_)
	{
		while (login == user.getLogin())
		{
			std::cout << std::endl;
			std::cout << "Login is busy. Supported operations: 1 - try another login, 0 - exit" << std::endl;
			std::cout << "Your operation: ";

			const char TRY = '1';
			const char EXIT = '0';

			std::string op;
			while (op != "0" && op != "1")
			{
				std::cin >> op;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl;

				std::map <std::string, char> mapping;
				mapping["1"] = TRY;
				mapping["0"] = EXIT;

				switch (mapping[op])
				{
				case TRY:
					std::cout << "Enter login: ";
					std::cin >> login;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				case EXIT:
					isChatWorking_ = false;
					std::cout << "Bye, see you later =) " << std::endl;
					//logger.getLog_file().clear();
					//logger.getLog_file().close();
					return;
				default:
					std::cout << "Wrong operation. Supported operations: 1 - try another login, 0 - exit" << std::endl;
					std::cout << "Your operation: ";
					break;
				}
			}
		}
	}

	std::cout << "Enter Password: ";
	std::cin >> password;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter Name: ";
	std::cin >> name;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (User user : users_)
	{
		while (name == user.getName())
		{
			std::cout << std::endl;
			std::cout << "Name is busy. Supported operations: 1 - try another name, 0 - exit" << std::endl;
			std::cout << "Your operation: ";

			std::string op;

			const char TRY = '1';
			const char EXIT = '0';

			while (op != "0" && op != "1")
			{
				std::cin >> op;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl;

				std::map <std::string, char> mapping;
				mapping["1"] = TRY;
				mapping["0"] = EXIT;

				switch (mapping[op])
				{
				case TRY:
					std::cout << "Enter Name: ";
					std::cin >> name;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				case EXIT:
					isChatWorking_ = false;
					std::cout << std::endl;
					std::cout << "Bye, see you later =) " << std::endl;
					//logger.getLog_file().clear();
					//logger.getLog_file().close();

					return;
				default:
					std::cout << "Wrong operation. Supported operations: 1 - try another name, 0 - exit" << std::endl;
					std::cout << "Your operation: ";
					break;
				}
			}
		}
	}
	User user = User(login, password, name);
	users_.push_back(user);
	currUser_ = std::make_shared<User>(user);
	std::cout << std::endl;
	std::cout << "Hey " << currUser_->getName() << "! Welcome to the chat =) " << std::endl << std::endl;
}

void Chat::logIn()
{
	std::string login;
	std::string password;
	std::string op;

	std::cout << "Enter login: ";
	std::cin >> login;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	currUser_ = getUserByLogin(login);

	if (!currUser_)
	{
		while (!currUser_)
		{
			const char TRY = '1';
			const char REGIN = '2';
			const char EXIT = '0';

			std::cout << std::endl;
			std::cout << "There is no user with this login. Supported operations: 1 - try another login, 2 - register to chat, 0 - exit" << std::endl;
			std::cout << "Your operation: ";

			while (op != "1" && op != "2" && op != "0")
			{
				std::cin >> op;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl;

				std::map <std::string, char> mapping;
				mapping["1"] = TRY;
				mapping["2"] = REGIN;
				mapping["0"] = EXIT;

				switch (mapping[op])
				{
				case TRY:
					logIn();
					break;
				case REGIN:
					regIn();
					break;
				case EXIT:
					isChatWorking_ = false;
					std::cout << std::endl;
					std::cout << "Bye, see you later =) " << std::endl;
					//logger.getLog_file().clear();
					//logger.getLog_file().close();

					return;
				default:
					std::cout << "Wrong operation. Supported operations: 1 - try another login, 2 - register to chat, 0 - exit" << std::endl;
					std::cout << "Your operation: ";
					break;
				}
			}
		}
	}
	else
	{
		std::cout << "Enter password: ";
		std::cin >> password;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;

		while (password != currUser_->getPassword())
		{
			std::cout << "Wrong password. Supported operations: 1 - try another password, 0 - exit" << std::endl;
			std::cout << "Your operation: ";

			std::string op;

			const char TRY = '1';
			const char EXIT = '0';

			while (op != "1" && op != "0")
			{
				std::cin >> op;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl;

				std::map <std::string, char> mapping;
				mapping["1"] = TRY;
				mapping["0"] = EXIT;

				switch (mapping[op])
				{
				case TRY:
					std::cout << "Enter password: ";
					std::cin >> password;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << std::endl;
					break;
				case EXIT:
					isChatWorking_ = false;
					std::cout << std::endl;
					std::cout << "Bye, see you later =) " << std::endl;
					//logger.getLog_file().clear();
					//logger.getLog_file().close();

					return;
				default:
					std::cout << "Wrong operation. Supported operations: 1 - try another login, 0 - exit" << std::endl;
					std::cout << "Your operation: ";
					break;
				}
			}
		}
		std::cout << "Hey " << currUser_->getName() << "! Welcome back to the chat =) " << std::endl << std::endl;
	}
}

void Chat::chatOptions()
{
	std::string op;
	std::cout << "Supported operations: 1 - register in chat, 2 - login, 0 - exit" << std::endl;
	std::cout << "Your operation: ";

	const char REGIN = '1';
	const char LOGIN = '2';
	const char EXIT = '0';

	while (op != "1" && op != "2" && op != "0" && isChatWorking_)
	{
		std::cin >> op;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;

		std::map <std::string, char> mapping;
		mapping["1"] = REGIN;
		mapping["2"] = LOGIN;
		mapping["0"] = EXIT;

		switch (mapping[op])
		{
		case REGIN:
			regIn();
			break;
		case LOGIN:
			logIn();
			break;
		case EXIT:
			std::cout << "Bye, see you later =) " << std::endl;
			isChatWorking_ = false;
			//logger.getLog_file().clear();
			//logger.getLog_file().close();

			return;
		default:
			std::cout << "Wrong operation. Supported operations: 1 - register in chat, 2 - login, 0 - exit" << std::endl;
			std::cout << "Your operation: ";
			break;
		}
	}
}

void Chat::userOptions()
{
	const char WRITE = '1';
	const char SHOW = '2';
	const char LOGOUT = '0';

	while (currUser_)
	{
		std::cout << "Supported operations: 1 - write message, 2 - show messages, 0 - logout" << std::endl;
		std::cout << "Your operation: ";

		std::string op;
		while (op != "1" && op != "2" && op != "0")
		{
			std::cin >> op;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl;

			std::map <std::string, char> mapping;
			mapping["1"] = WRITE;
			mapping["2"] = SHOW;
			mapping["0"] = LOGOUT;

			switch (mapping[op])
			{
			case WRITE:
				writeMessage();
				break;
			case SHOW:
				showMessages();
				break;
			case LOGOUT:
				std::cout << currUser_->getName() << " is logged out! " << std::endl << std::endl;
				currUser_ = nullptr;
				break;
			default:
				std::cout << "Wrong operation. Supported operations: 1 - write message, 2 - show messages, 0 - logout" << std::endl;
				std::cout << "Your operation: ";
				break;
			}
		}
	}
}

void Chat::writeMessage()
{
	std::string text;
	unsigned short i = 1, userNum = 1;

	std::cout << "Message body: ";
	std::getline(std::cin, text);
	std::cout << std::endl;

	for (User& user : users_)
	{
		std::cout << user.getName() << " - " << i << std::endl;
		i++;
	}

	std::cout << "Everyone in the chat - " << i << std::endl << std::endl;
	std::cout << "Enter number : ";

	std::cout << std::endl;

	while (!(std::cin >> userNum))
	{
		std::cout << std::endl;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Input is incorrect. Try again!" << std::endl;
		std::cout << "User number: ";
	}
	std::cout << std::endl;

	while (!userNum || userNum > i)
	{
		std::cout << "There is no user with this number. Try again!" << std::endl;
		std::cout << "User number: ";
		std::cin >> userNum;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;
	}

	if (userNum == i)
	{
		for (User& user : users_)
		{
			Message message = Message(currUser_->getName(), user.getName(), text);
			messages_.push_back(message);
			logger.getLog_file() << message << std::endl;
			logger.getLog_file().clear();

		}
		std::cout << "The message is sent from " << currUser_->getName() << " to everyone in the chat..." << std::endl << std::endl;
	}
	else if (userNum > 0 && userNum < i)
	{
		Message message = Message(currUser_->getName(), users_.at(userNum - 1).getName(), text);
		messages_.push_back(message);
		std::cout << "The message is sent from " << currUser_->getName() << " to " << users_.at(userNum - 1).getName() << "..." << std::endl << std::endl;
		logger.getLog_file() << message << std::endl;
		logger.getLog_file().clear();

	}
}

void Chat::showMessages()
{
	int count = 0;

	for (Message& message : messages_)
	{
		if (currUser_->getName() == message.getReceiver())
		{
			count++;
			std::cout << "You've got message from " << message.getSender() << ": " << message.getMessage() << std::endl;
		}
	}

	if (count != 0)
	{
		std::cout << std::endl;
	}

	if (count == 0)
	{
		std::cout << "You've got no messages yet..." << std::endl << std::endl;
	}
}

std::shared_ptr<User> Chat::getUserByName(const std::string& name) const
{
	for (User user : users_)
	{
		if (name == user.getName())
		{
			return std::make_shared<User>(user);
		}
	}
	return nullptr;
}

std::shared_ptr<User> Chat::getUserByLogin(const std::string& login) const
{
	for (User user : users_)
	{
		if (login == user.getLogin())
		{
			return std::make_shared<User>(user);
		}
	}
	return nullptr;
}

std::shared_ptr<User> Chat::getCurrUser() const
{
	return currUser_;
}






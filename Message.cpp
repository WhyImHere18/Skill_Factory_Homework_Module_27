#include "Message.h"
#include <string>
#include <iomanip>

//Message::Message(User& sender, User& receiver, const std::string& message) : sender_(sender), receiver_(receiver), message_(message) {}

Message::Message(const std::string& sender, const std::string& receiver, const std::string& message) : sender_(sender), receiver_(receiver), message_(message) {}

const std::string& Message::getSender() const
{
	return sender_;
}

const std::string& Message::getReceiver() const
{
	return receiver_;
}

const std::string& Message::getMessage() const
{
	return message_;
}

std::ostream& operator <<(std::ostream& os, const Message& obj)
{
	std::shared_mutex shared_mutex;
	shared_mutex.lock();
	os << "sender = ";
	os << std::left << std::setw(8) << obj.getSender();
	os << " receiver = ";
	os << std::left << std::setw(8) << obj.getReceiver();
	os << " text = ";
	os << std::left << obj.getMessage();
	shared_mutex.unlock();
	return os;
}
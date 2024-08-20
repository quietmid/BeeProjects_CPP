
#include "contact.hpp"

std::string Contact::get_firstName() const
{
	return (this->firstName);
}

std::string Contact::get_lastName() const
{
	return (this->lastName);	
}

std::string Contact::get_nickName() const
{
	return (this->nickName);
}

std::string Contact::get_pNumber() const
{
	return (this->phoneNum);
}

std::string Contact::get_darkSecret() const
{
	return (this->darkSecret);
}

void	Contact::set_firstName(std::string first)
{
	firstName = first;
}

void	Contact::set_lastName(std::string last)
{
	lastName = last;
}

void	Contact::set_nickName(std::string nick)
{
	nickName = nick;
}

void	Contact::set_pNumber(std::string phone)
{
	phoneNum = phone;
}

void	Contact::set_darkSecret(std::string secret)
{
	darkSecret = secret;
}

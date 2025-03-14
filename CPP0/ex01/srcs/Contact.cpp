
#include "main.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

void	Contact::set_infos(std::string first_name, std::string last_name,
	std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}


std::string Contact::get_first_name(unsigned int size)
{
    if (size > 0 && this->first_name.length() > size) {
        std::string first_name2;
        first_name2 = this->first_name.substr(0 , size - 1);
        first_name2.push_back('.');
        return first_name2;
    }
    return this->first_name;
}

std::string Contact::get_last_name(unsigned int size)
{
    if (size > 0 && this->last_name.length() > size) {
        std::string last_name2;
        last_name2 = this->last_name.substr(0 , size - 1);
        last_name2.push_back('.');
        return last_name2;
    }
    return this->last_name;
}

std::string Contact::get_nickname(unsigned int size)
{
    if (size > 0 && this->nickname.length() > size) {
        std::string nickname2;
        nickname2 = this->nickname.substr(0 , size - 1);
        nickname2.push_back('.');
        return nickname2;
    }
    return this->nickname;
}

std::string Contact::get_phone_number(void)
{
    return this->phone_number;
}

std::string Contact::get_darkest_secret(void)
{
    return this->darkest_secret;
}

void Contact::show_contact(void)
{
    std::cout << "First Name : " << this->first_name << std::endl;
    std::cout << "Last Name : " << this->last_name << std::endl;
    std::cout << "Nickname : " << this->nickname << std::endl;
    std::cout << "Phone Number : " << this->phone_number << std::endl;
    std::cout << "Darkest Secret : " << this->darkest_secret << std::endl;
}

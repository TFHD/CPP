
#include "main.hpp"

PhoneBook::PhoneBook(void)
{
    this->size = 0;
    this->contacts = new Contact[8];
    return;
}

PhoneBook::~PhoneBook(void)
{
    delete[] this->contacts;
    return;
}

void PhoneBook::add_contact(void)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    readline(first_name, "First Name : ");
    readline(last_name, "Last Name : ");
    readline(nickname, "Nickname : ");
    readline(phone_number, "Phone Number : ");
    readline(darkest_secret, "Darkest secret : ");
    
    if (size >= 8) {
        this->size--;

        for (int i = 0; i < this->size; i++) {
            this->contacts[i].set_infos(
                this->contacts[i + 1].get_first_name(-1),
                this->contacts[i + 1].get_last_name(-1),
                this->contacts[i + 1].get_nickname(-1),
                this->contacts[i + 1].get_phone_number(),
                this->contacts[i + 1].get_darkest_secret()
            );
        }
    }
    contacts[this->size].set_infos(first_name, last_name, nickname, phone_number, darkest_secret);
    if (this->size < 8)
        this->size++;
}

void    PhoneBook::list_contacts(void)
{
    std::cout << "|---INDEX--|FIRST NAME|LAST--NAME|-NICKNAME-|" << std::endl;
    for (int i = 0; i < this->size; i++) {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << this->contacts[i].get_first_name(10);
        std::cout << "|" << std::setw(10) << this->contacts[i].get_last_name(10);
        std::cout << "|" << std::setw(10) << this->contacts[i].get_nickname(10);
        std::cout << "|" << std::endl;
    }
    std::cout << "-------------------------------------------------" << std::endl;
}

void    PhoneBook::display_contact(int i) {
    if (i >= 0 && i < this->size)
        this->contacts[i].show_contact();
    else
        std::cerr << "It's not a index between 0 and " << this->size - 1 << std::endl;
}

int     PhoneBook::get_size(void) {
    return this->size;
}
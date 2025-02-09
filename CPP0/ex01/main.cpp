#include "main.hpp"

bool	str_isnum(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return false;
	return true;
}

void    readline(std::string &str, std::string prompt) {

    str.clear();
    while (str.empty()) {
        std::cout << prompt;
        std::getline(std::cin, str);
        if (std::cin.eof()) {
            std::cout << std::endl;
            exit(0);
        }
    }
}

int main(void) {

    PhoneBook phonebook;
    bool    run;

    run = true;
    while(run) {
        std::string text;
        readline(text, "$> ");
        if (!text.compare("ADD"))
            phonebook.add_contact();
        else if (!text.compare("EXIT"))
            run = false; 
        else if (!text.compare("SEARCH")) {
            if (phonebook.get_size() > 0) {

                std::string index;
                phonebook.list_contacts();
                readline(index, "Enter the index of the contact to display all informations : ");
                std::cout << std::endl;
                if (str_isnum(index))
                    phonebook.display_contact(atoi(index.c_str()));
                else
                    std::cout << "Please write a number !" << std::endl;
                std::cout << std::endl;
            }
            else
                std::cout << "There is nothing here :/" << std::endl;
        }
        else if (text.length() > 0)
            std::cerr << "ERROR : You can just write : ADD , EXIT or SEARCH !" << std::endl;
    }

}
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        Contact();
        ~Contact(void);
        void    set_infos(std::string first_name, std::string last_name,
	        std::string nickname, std::string phone_number, std::string darkest_secret);
        std::string get_first_name(unsigned int size);
        std::string get_last_name(unsigned int size);
        std::string get_nickname(unsigned int size);
        std::string get_phone_number(void);
        std::string get_darkest_secret(void);
        void        show_contact(void);
};

#endif
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"
# include "Contact.hpp"

class PhoneBook {

    private:
	    int size;
        Contact contacts[8];

    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    add_contact(int i);
        void    list_contacts(void);
        void    display_contact(int i);
        int     get_size(void);
};

#endif
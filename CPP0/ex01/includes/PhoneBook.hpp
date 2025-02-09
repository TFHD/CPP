#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"
# include "Contact.hpp"

class PhoneBook {

    private:
	    int size;
        Contact *contacts;

    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    add_contact(void);
        void    list_contacts(void);
        void    display_contact(int i);
        int     get_size(void);
};

#endif
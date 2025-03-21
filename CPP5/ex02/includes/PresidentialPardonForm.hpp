#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    private:
        std::string target;

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        virtual ~PresidentialPardonForm(void);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
        PresidentialPardonForm(const PresidentialPardonForm &cpy);

        std::string getTarget(void) const;
        void executeAction(void) const;
};

#endif
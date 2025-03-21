#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <fstream>
# include <iostream>

class ShrubberyCreationForm : public AForm {

    private:
        std::string target;

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        virtual ~ShrubberyCreationForm(void);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
        ShrubberyCreationForm(const ShrubberyCreationForm &cpy);

        std::string getTarget(void) const;
        void executeAction(void) const;
};

#endif
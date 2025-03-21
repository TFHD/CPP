#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern {

    public:
        Intern(void);
        ~Intern(void);
        Intern &operator=(const Intern &src);
        Intern(const Intern &cpy);
        AForm *makeForm(std::string &formName, std::string &target) const;
        AForm *createShrubbery(std::string &target) const;
        AForm *createPresidential(std::string &target) const;
        AForm *createRobotomy(std::string &target) const;
};

#endif
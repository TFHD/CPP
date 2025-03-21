#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
    if (LOG)
        std::cout << "\e[32mThe Intern\e[0m default was created !" << std::endl;
}

Intern::~Intern(void)
{
    if (LOG)
        std::cout << "\e[32mThe Intern\e[0m was destroyed !" << std::endl;
}

Intern::Intern(const Intern &cpy)
{
    if (LOG)
        std::cout << "\e[32mThe Intern\e[0m was copied !" << std::endl;
   *this = cpy;
}

Intern	&Intern::operator=(const Intern &src)
{
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe Intern\e[0m Assignation operator called" << std::endl; }
	return *this;
}

AForm *Intern::makeForm(std::string &formName, std::string &target) const
{
    if (target.empty())
    {
		std::cout << "Error: Target must be specified ''" << target << " is not recognized." << std::endl;
        throw std::invalid_argument("Error: Target must be specified and cannot be empty.");
    }
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*formCreators[3])(std::string&) const = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            AForm* form = (this->*formCreators[i])(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    std::cout << "Error: Form name '" << formName << "' is not recognized." << std::endl;
    return NULL;
}

AForm *Intern::createShrubbery(std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(std::string &target) const
{
    return new PresidentialPardonForm(target);
}
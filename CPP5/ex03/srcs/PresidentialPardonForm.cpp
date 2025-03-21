#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5) , target("default")
{
    if (LOG)
        std::cout << "\e[32mThe PresidentialPardonForm\e[0m default was created !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    if (LOG)
        std::cout << "\e[32mThe PresidentialPardonForm\e[0m was destroyed !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy)
{
    if (LOG)
        std::cout << "\e[32mThe PresidentialPardonForm\e[0m was copied !" << std::endl;
   *this = cpy;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    this->target = src.getTarget();
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe PresidentialPardonForm\e[0m Assignation operator called" << std::endl; }
	return *this;
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return this->target;
}

void PresidentialPardonForm::executeAction(void) const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
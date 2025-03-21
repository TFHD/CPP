#include "../includes/RobotomyRequestForm.hpp"
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("default")
{
    if (LOG)
        std::cout << "\e[32mThe RobotomyRequestForm\e[0m default was created !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    if (LOG)
        std::cout << "\e[32mThe RobotomyRequestForm\e[0m was destroyed !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
{
    if (LOG)
        std::cout << "\e[32mThe RobotomyRequestForm\e[0m was copied !" << std::endl;
   *this = cpy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    this->target = src.getTarget();
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe RobotomyRequestForm\e[0m Assignation operator called" << std::endl; }
	return *this;
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return this->target;
}

void RobotomyRequestForm::executeAction(void) const
{
    srand(time(0));
    if (rand() % 2 == 1)
        std::cout << this->getTarget() << " has been robotimized succesfully" << std::endl;
    else
        std::cout << "The robotomy failed" << std::endl;
}
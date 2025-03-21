#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
    if (LOG)
        std::cout << "\e[32mThe ShrubberyCreationForm\e[0m default was created !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    if (LOG)
        std::cout << "\e[32mThe ShrubberyCreationForm\e[0m was destroyed !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy)
{
    if (LOG)
        std::cout << "\e[32mThe ShrubberyCreationForm\e[0m was copied !" << std::endl;
   *this = cpy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    this->target = src.getTarget();
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe ShrubberyCreationForm\e[0m Assignation operator called" << std::endl; }
	return *this;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return this->target;
}

void ShrubberyCreationForm::executeAction(void) const
{
    std::string name = this->getTarget() + "_shrubbery";
    std::ofstream file(name.c_str());

    if (file.is_open()) {
        file << "               ,@@@@@@@,\n";
        file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
        file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
        file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
        file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'";
        file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'";
        file << "   `&%\\ ` /%&'    |.|        \\ '|8'";
        file << "       |o|        | |         | |";
        file << "       |.|        | |         | |";
        file << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";
        file.close();
        std::cout << "Text has been written to the file." << std::endl;
    } else {
        std::cout << "Failed to create the file." << std::endl;
    }
}
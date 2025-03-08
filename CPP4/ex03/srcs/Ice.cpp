#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice")
{
    if (LOG)
        std::cout << "\e[36mThe Ice\e[0m was created !" << std::endl;
}

Ice::~Ice(void)
{
    if (LOG)
        std::cout << "\e[36mThe Ice\e[0m was destroyed !" << std::endl;
}

Ice::Ice(const Ice &cpy) : AMateria("ice_copy")
{
    if (LOG)
        std::cout << "\e[36mThe Ice\e[0m was copied !" << std::endl;
   *this = cpy;
}

Ice	&Ice::operator=(const Ice &src)
{
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[36mThe Ice\e[0m Assignation operator called" << std::endl; }
	return *this;
}

AMateria *Ice::clone() const
{
    return (new Ice());
}

std::string const &Ice::getType() const
{
    return this->type;
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl; 
}
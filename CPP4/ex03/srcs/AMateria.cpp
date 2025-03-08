#include "AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(std::string const &type)
{
    this->type = type;
    if (LOG)
        std::cout << "\e[32mThe AMateria\e[0m " << this->type << " was created !" << std::endl;
}

AMateria::~AMateria(void)
{
    if (LOG)
        std::cout << "\e[32mThe AMateria\e[0m " << this->type << " was destroyed !" << std::endl;
}

AMateria::AMateria(const AMateria &cpy)
{
    this->type = cpy.type;
    if (LOG)
        std::cout << "\e[32mThe AMateria\e[0m was copied !" << std::endl;
   *this = cpy;
}

AMateria	&AMateria::operator=(const AMateria &src)
{
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe AMateria\e[0m Assignation operator called" << std::endl; }
	return *this;
}

std::string const &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    (void) target;
}
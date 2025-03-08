#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
    if (LOG)
        std::cout << "\e[33mThe Cure\e[0m was created !" << std::endl;
}

Cure::~Cure(void)
{
    if (LOG)
        std::cout << "\e[33mThe Cure\e[0m was destroyed !" << std::endl;
}

Cure::Cure(const Cure &cpy) : AMateria("cure_copy")
{
    if (LOG)
        std::cout << "\e[33mThe Cure\e[0m was copied !" << std::endl;
   *this = cpy;
}

Cure	&Cure::operator=(const Cure &src)
{
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[33mThe Cure\e[0m Assignation operator called" << std::endl; }
	return *this;
}

AMateria *Cure::clone() const
{
    return (new Cure());
}

std::string const &Cure::getType() const
{
    return this->type;
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}
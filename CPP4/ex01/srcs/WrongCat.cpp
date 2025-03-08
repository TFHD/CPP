#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    std::cout << "\e[35mThe WrongCat\e[0m was created !" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "\e[35mThe WrongCat\e[0m was destroyed !" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cpy)
{
    std::cout << "\e[35mThe WrongCat\e[0m was copied !" << std::endl;
   *this = cpy;
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
    if (this == &src)
        return *this;
    std::cout << "\e[35mThe WrongCat\e[0m Assignation operator called" << std::endl;
    this->type = src.type;
	return *this;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Wrooooooong MMMMMmmmmiiiiiiaaaaaaou......" << std::endl; 
}
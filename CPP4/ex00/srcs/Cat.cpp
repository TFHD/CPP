#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "\e[35mThe Cat\e[0m was created !" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "\e[35mThe Cat\e[0m was destroyed !" << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal("Cat")
{
    std::cout << "\e[35mThe Cat\e[0m was copied !" << std::endl;
   *this = cpy;
}

Cat	&Cat::operator=(const Cat &src)
{
    if (this == &src)
        return *this;
    std::cout << "\e[35mThe Cat\e[0m Assignation operator called" << std::endl;
    this->type = src.type;
	return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "\e[32mMMMMMmmmmiiiiiiaaaaaaou......\e[0m" << std::endl;
}
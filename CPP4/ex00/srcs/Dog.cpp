#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "\e[33mThe Dog\e[0m was created !" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "\e[33mThe Dog\e[0m was destroyed !" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal("Dog")
{
    std::cout << "\e[33mThe Dog\e[0m was copied !" << std::endl;
   *this = cpy;
}

Dog	&Dog::operator=(const Dog &src)
{
    if (this == &src)
        return *this;
    std::cout << "\e[33mThe Dog\e[0m Assignation operator called" << std::endl;
    this->type = src.type;
	return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "\e[32mWouaf Wouaf\e[0m" << std::endl;
}
#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
    this->type = "default";
    std::cout << "\e[31mThe Animal\e[0m was created !" << std::endl;
}

Animal::Animal(std::string _type) : type(_type)
{
    std::cout << "\e[31mThe Animal\e[0m was created !" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "\e[31mThe Animal\e[0m was destroyed !" << std::endl;
}

Animal::Animal(const Animal &cpy)
{
    std::cout << "\e[31mThe Animal\e[0m was copied !" << std::endl;
   *this = cpy;
}

Animal	&Animal::operator=(const Animal &src)
{
    if (this == &src)
        return *this;
    std::cout << "\e[31mThe Animal\e[0m Assignation operator called" << std::endl;
    this->type = src.type;
	return *this;
}

std::string    Animal::getType(void) const
{
    return this->type;
}

void Animal::makeSound(void) const
{
    std::cout << "\e[32mgidagidigidagidao\e[0m" << std::endl;
}
#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
{
    this->type = "default";
    std::cout << "\e[35mThe WrongAnimal\e[0m was created !" << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type) : type(_type)
{
    std::cout << "\e[35mThe WrongAnimal\e[0m was created !" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "\e[35mThe WrongAnimal\e[0m was destroyed !" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
    std::cout << "\e[35mThe WrongAnimal\e[0m was copied !" << std::endl;
   *this = cpy;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
    if (this == &src)
        return *this;
    std::cout << "\e[35mThe WrongAnimal\e[0m Assignation operator called" << std::endl;
    this->type = src.type;
	return *this;
}

std::string    WrongAnimal::getType(void) const
{
    return this->type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "\e[32mgidagidigidagidao1\e[0m" << std::endl;
}
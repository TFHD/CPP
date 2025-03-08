#include "Cat.hpp"
#include <iostream>
#include <stdlib.h>

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "\e[35mThe Cat\e[0m was created !" << std::endl;
    this->brain = new Brain();
    if (this->brain == NULL) {
        std::cerr << "There is an error in allocation of Dog Brain !" << std::endl;
        exit(1);
    }
}

Cat::~Cat(void)
{
    delete this->brain;
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
    this->brain = new Brain();
    if (this->brain == NULL) {
        std::cerr << "There is an error in allocation of Dog Brain !" << std::endl;
        exit(1);
    }
    *this->brain = *src.brain;
	return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "MMMMMmmmmiiiiiiaaaaaaou......" << std::endl;
}

void    Cat::setIdea(int i, std::string idea)
{
    if (i > 100) {
        std::cout << "There is max 100 ideas in the Dog Brain" << std::endl;
        return ;
    }
    this->brain->setIdea(i, idea);
}

void Cat::getAllIdeas(int i) 
{
    for (int j = 0; j < i ; j++) {
        if (j < 100)
            std::cout << "Cat think to : " << this->brain->getIdea(j) << std::endl;
        else
            std::cout << "You reach the Cat Brain limit" << std::endl;
    }
}
#include "Dog.hpp"
#include <iostream>
#include <stdlib.h>

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "\e[33mThe Dog\e[0m was created !" << std::endl;
    this->brain = new Brain();
    if (this->brain == NULL) {
        std::cerr << "There is an error in allocation of Dog Brain !" << std::endl;
        exit(1);
    }
}

Dog::~Dog(void)
{
    delete this->brain;
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
    this->brain = new Brain();
    if (this->brain == NULL) {
        std::cerr << "There is an error in allocation of Dog Brain !" << std::endl;
        exit(1);
    }
    *this->brain = *src.brain;
	return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "Wouaf Wouaf" << std::endl;
}

void    Dog::setIdea(int i, std::string idea)
{
    if (i > 100) {
        std::cout << "There is max 100 ideas in the Dog Brain" << std::endl;
        return ;
    }
    this->brain->setIdea(i, idea);
}

void Dog::getAllIdeas(int i) 
{
    for (int j = 0; j < i ; j++) {
        if (j < 100)
            std::cout << "Dog think to : " << this->brain->getIdea(j) << std::endl;
        else
            std::cout << "You reach the Dog Brain limit" << std::endl;
    }
}
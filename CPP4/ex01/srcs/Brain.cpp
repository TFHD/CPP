#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
    std::cout << "\e[36mThe Brain\e[0m was created !" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "\e[36mThe Brain\e[0m was destroyed !" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
    std::cout << "\e[36mThe Brain\e[0m was copied !" << std::endl;
   *this = cpy;
}

Brain	&Brain::operator=(const Brain &src)
{
    if (this == &src)
        return *this;
    std::cout << "\e[36mThe Brain\e[0m Assignation operator called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = src.ideas[i];
    }
	return *this;
}

void    Brain::setIdea(int i, std::string idea)
{
    if (i > 100) {
        std::cout << "There is max 100 ideas in the Dog Brain" << std::endl;
        return ;
    }
    this->ideas[i] = idea;
}

const std::string Brain::getIdea(int i) const
{
    if (i > 100) {
        std::cout << "There is max 100 ideas in the Dog Brain" << std::endl;
        return NULL;
    }
    return this->ideas[i];
}
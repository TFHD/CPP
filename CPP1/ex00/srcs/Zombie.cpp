#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << "The Zombie died." << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}
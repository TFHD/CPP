#include "Zombie.hpp"

Zombie::Zombie(void)
{
    this->name = name;
    return;
}

void Zombie::set_name(std::string name)
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
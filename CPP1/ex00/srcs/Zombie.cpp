#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << "The Zombie\e[31m " << this->name << "\e[0m died." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << "\e[32m" << name << "\e[0m: BraiiiiiiinnnzzzZ..." << std::endl;
}
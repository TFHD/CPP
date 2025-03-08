#include "Zombie.hpp"

Zombie::Zombie(void)
{
    this->name = "default";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::set_name(std::string name)
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
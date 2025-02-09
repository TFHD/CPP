#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL)
{
    this->_name = name;
    return ;
}

HumanB::~HumanB(void)
{
    return ;
}

void    HumanB::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

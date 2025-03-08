#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap("default")
{
    this->name = "default";
    this->hitPoint = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "\e[32mThe FragTrap\e[0m default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    this->hitPoint = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "\e[32mThe FragTrap\e[0m " << this->name << " was created !" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "\e[32mThe FragTrap\e[0m " << this->name << " was destroyed !" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{
    std::cout << "\e[32mThe FragTrap\e[0m was copied !" << std::endl;
   *this = cpy;
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
    std::cout << "\e[32mThe FragTrap\e[0m Assignation operator called" << std::endl;
	this->name = src.name;
    this->hitPoint = src.hitPoint;
    this->energyPoints = src.energyPoints;
    this->attackDamage = src.attackDamage;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High Fives ! We Love you guys !" << std::endl;
}
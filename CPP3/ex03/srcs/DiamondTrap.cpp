#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name")
{
    this->name = "default";
    ClapTrap::name = "default_clap_name";
    this->hitPoint = FragTrap::hitPoint;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "\e[33mThe DiamondTrap\e[0m " << this->name << " was created !" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name")
{
    this->name = _name;
    ClapTrap::name = _name + "_clap_name";
    this->hitPoint = FragTrap::hitPoint;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "\e[33mThe DiamondTrap\e[0m " << this->name << " was created !" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "\e[33mThe DiamondTrap\e[0m " << this->name << " was destroyed !" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy)
{
    std::cout << "\e[33mThe DiamondTrap\e[0m was copied !" << std::endl;
   *this = cpy;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
    std::cout << "\e[33mThe DiamondTrap\e[0m Assignation operator called" << std::endl;
	this->name = src.name;
    this->hitPoint = src.hitPoint;
    this->energyPoints = src.energyPoints;
    this->attackDamage = src.attackDamage;
	return *this;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "\e[33mThe DiamondTrap\e[0m I'm " << this->name << " and my ClapTrap name is : " << ClapTrap::name << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
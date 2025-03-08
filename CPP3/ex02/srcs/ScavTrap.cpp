#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap("default")
{
    this->name = "default";
    this->hitPoint = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "\e[31mThe ScavTrap\e[0m default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    this->hitPoint = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "\e[31mThe ScavTrap\e[0m " << this->name << " was created !" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "\e[31mThe ScavTrap\e[0m " << this->name << " was destroyed !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy)
{
    std::cout << "\e[31mThe ScavTrap\e[0m was copied !" << std::endl;
   *this = cpy;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "\e[31mThe ScavTrap\e[0m Assignation operator called" << std::endl;
	this->name = src.name;
    this->hitPoint = src.hitPoint;
    this->energyPoints = src.energyPoints;
    this->attackDamage = src.attackDamage;
	return *this;
}

void        ScavTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0 && this->hitPoint > 0) {
    std::cout << "\e[31mThe ScavTrap\e[0m " << this->name
    << " attacks " << target
    <<", causing " << this->attackDamage << " points of damage!"
    << std::endl;
    this->energyPoints--;
    } else {
        std::cout << "\e[31mThe ScavTrap\e[0m " << this->name <<" doesn't had any energy or hitPoint" << std::endl; }

}

void ScavTrap::guardGate(void)
{
    std::cout << "\e[31mThe ScavTrap\e[0m is now in Gate keeper mode !" << std::endl;
}
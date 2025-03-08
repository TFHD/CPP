#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(void) : name("default"), hitPoint(10), energyPoints(10), attackDamage(0)
{
    std::cout << "\e[35mThe ClapTrap\e[0m default ClapTrap was created !" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : name(_name), hitPoint(10), energyPoints(10), attackDamage(0)
{
    std::cout << "\e[35mThe ClapTrap\e[0m " << this->name << " was created !" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "\e[35mThe ClapTrap\e[0m " << this->name << " was destroyed !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
    std::cout << "\e[35mThe ClapTrap\e[0m was copied !" << std::endl;
   *this = cpy;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "\e[35mThe ClapTrap\e[0m Assignation operator called" << std::endl;
	this->name = src.name;
    this->hitPoint = src.hitPoint;
    this->energyPoints = src.energyPoints;
    this->attackDamage = src.attackDamage;
	return *this;
}

void        ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0 && this->hitPoint > 0) {
    std::cout << "\e[35mThe ClapTrap\e[0m " << this->name
    << " attacks " << target
    <<", causing " << this->attackDamage << " points of damage!"
    << std::endl;
    this->energyPoints--;
    } else {
        std::cout << "\e[35mThe ClapTrap\e[0m doesn't had any energy or hitPoint" << std::endl; }

}
void        ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoint > (int)amount) { this->hitPoint -= amount; }
    else if (this->hitPoint > 0) {this->hitPoint = 0; }
    else {
        std::cout << "Bro... ClapTrap is already dead" << std::endl;
        return;
    }
    std::cout << "\e[35mThe ClapTrap\e[0m " << this->name
    << " was attacked and lost " << amount
    << " hit points, he has now " << this->hitPoint
    << " hit points. "<< std::endl;
}
void        ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints > 0 && this->hitPoint > 0) {
        this->hitPoint += amount;
        this->energyPoints--;
        std::cout << "\e[35mThe ClapTrap\e[0m " << this->name
        << " repaired itself " << amount
        << ", he has now " << this->hitPoint << " hitPoint and " << this->energyPoints << " energyPoints"
        << std::endl;
    } else {
        std::cout << "\e[35mThe ClapTrap\e[0m " << this->name << "doesn't have any energyPoint to repair itself !" << std::endl;
    }
}

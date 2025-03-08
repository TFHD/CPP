#include "../includes/ClapTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap clapTrap("Donald");

    clapTrap.attack("Saucisse");
	clapTrap.attack("Saucisse");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(10);
    clapTrap.takeDamage(30);
    clapTrap.beRepaired(5);
    clapTrap.takeDamage(30);
    return 0;
}

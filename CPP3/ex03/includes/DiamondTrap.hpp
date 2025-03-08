#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;

    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &cpy);
        ~DiamondTrap(void);
        DiamondTrap &operator=(const DiamondTrap &src);
        void attack(const std::string &target);
        void whoAmI(void);
};

#endif
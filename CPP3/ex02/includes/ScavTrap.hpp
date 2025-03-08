#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ~ScavTrap(void);
        ScavTrap(const ScavTrap &src);
        ScavTrap	&operator=(const ScavTrap &src);
        void        attack(const std::string& target);
        void guardGate(void);
};

#endif
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    private:
        std::string name;
        int hitPoint;
        int energyPoints;
        int attackDamage;
    
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap &src);
        ClapTrap	&operator=(const ClapTrap &src);
        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
};

#endif
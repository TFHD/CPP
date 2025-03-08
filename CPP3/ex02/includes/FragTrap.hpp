#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        ~FragTrap(void);
        FragTrap(const FragTrap &src);
        FragTrap	&operator=(const FragTrap &src);
        void        highFivesGuys(void);
};

#endif
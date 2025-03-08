#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(const Ice &cpy);
        Ice &operator=(const Ice &src);
        ~Ice(void);
        AMateria *clone() const;
        std::string const &getType() const;
        void use(ICharacter &target);
};

#endif
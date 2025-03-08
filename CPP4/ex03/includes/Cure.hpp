#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(const Cure &cpy);
        Cure &operator=(const Cure &src);
        ~Cure(void);
        AMateria *clone() const;
        std::string const &getType() const;
        void use(ICharacter &target);
};

#endif
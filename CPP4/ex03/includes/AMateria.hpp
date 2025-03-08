#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"
# define LOG 0

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(void);
        AMateria(std::string const &type);
        AMateria(const AMateria &cpy);
        AMateria &operator=(const AMateria &src);
        virtual ~AMateria(void);

        std::string const &getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif
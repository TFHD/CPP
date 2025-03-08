#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    *slots[4];
    public:
        MateriaSource(void);
        ~MateriaSource(void);
        MateriaSource(const MateriaSource &cpy);
        MateriaSource &operator=(const MateriaSource &src);

        void learnMateria(AMateria *m);
        AMateria* createMateria(std::string const & type);
};

#endif
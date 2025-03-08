#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        AMateria *slots[4];
        std::string name;
        int last_index_item;

    public:
        Character(void);
        Character(std::string name);
        ~Character(void);
        Character(const Character &cpy);
        Character &operator=(const Character &src);
        std::string const &getName() const;

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void drop(AMateria *m);
};

#endif
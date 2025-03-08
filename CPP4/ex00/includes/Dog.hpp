#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>

class Dog : public Animal
{
    private:
    public:
        Dog(void);
        Dog(std::string name);
        Dog(const Dog &cpy);
        Dog &operator=(const Dog &src);
        ~Dog(void);
        void makeSound(void) const;
};

#endif
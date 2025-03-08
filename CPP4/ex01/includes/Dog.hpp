#ifndef DOG_HPP
# define DOG_HPP

# include "Brain.hpp"
# include "Animal.hpp"
# include <string>

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog(void);
        Dog(std::string name);
        Dog(const Dog &cpy);
        Dog &operator=(const Dog &src);
        ~Dog(void);
        void    makeSound(void) const;
        void    setIdea(int i, std::string);
        void    getAllIdeas(int i);
};

#endif
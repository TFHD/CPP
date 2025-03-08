#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <string>

class Cat : public Animal
{
    private:
    public:
        Cat(void);
        Cat(std::string name);
        Cat(const Cat &cpy);
        Cat &operator=(const Cat &src);
        ~Cat(void);
        void makeSound(void) const;
};

#endif
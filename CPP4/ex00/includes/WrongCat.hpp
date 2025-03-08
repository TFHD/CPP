#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <string>

class WrongCat : public WrongAnimal
{
    private:
    public:
        WrongCat(void);
        WrongCat(std::string name);
        WrongCat(const WrongCat &cpy);
        WrongCat &operator=(const WrongCat &src);
        ~WrongCat(void);
        void makeSound(void) const;
};

#endif
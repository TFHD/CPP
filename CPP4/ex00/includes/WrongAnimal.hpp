#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &cpy);
        WrongAnimal &operator=(const WrongAnimal &src);
        ~WrongAnimal(void);

        std::string     getType(void) const;
        void	makeSound() const;

};

#endif
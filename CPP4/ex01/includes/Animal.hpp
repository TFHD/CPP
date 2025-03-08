#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal(void);
        Animal(std::string type);
        Animal(const Animal &cpy);
        Animal &operator=(const Animal &src);
        virtual ~Animal(void);

        std::string     getType(void) const;
        virtual void	makeSound() const;

};

#endif
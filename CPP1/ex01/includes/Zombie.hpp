#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        Zombie(void);
        ~Zombie(void);
        void    announce(void);
        void    set_name(std::string name);
};  
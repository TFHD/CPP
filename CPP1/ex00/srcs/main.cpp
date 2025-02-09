#include "Zombie.hpp"
Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

int    main(void)
{
    std::cout << "Create a Zombie on heap and announce it" << std::endl;
    Zombie *zombie1 = newZombie("Alfred");
    zombie1->announce();
    delete zombie1;

    std::cout << std::endl;
    std::cout << "Create a Zombie on stack and announce it" << std::endl;
    Zombie zombie2 = Zombie("Antoine daniel");
    zombie2.announce();

    std::cout << std::endl;
    std::cout << "Create and announce with randomChump" << std::endl;
    randomChump("Zidane");
    return 0;
}
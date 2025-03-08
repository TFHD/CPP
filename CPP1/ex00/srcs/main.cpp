#include "Zombie.hpp"
Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

int    main(void)
{
    std::cout << std::endl << "##########Create a Zombie on the heap##########" << std::endl << std::endl;

    Zombie *zombie1 = newZombie("BatMan");
    zombie1->announce();
    Zombie *zombie2 = newZombie("SuperMan");
    zombie2->announce();

    std::cout << std::endl << "##########Create a Zombie on the stack##########" << std::endl << std::endl;

    Zombie zombie3 = Zombie("Picsou");
    zombie3.announce();
    Zombie zombie4 = Zombie("Boubakar");
    zombie4.announce();

    std::cout << std::endl << "##########Create a Zombie with randomChump##########" << std::endl << std::endl;

    randomChump("Zidane");

    std::cout << std::endl << "##########Deconstructors##########" << std::endl << std::endl;

    delete zombie1;
    delete zombie2;
    return 0;
}
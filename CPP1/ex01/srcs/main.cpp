#include "Zombie.hpp"
#include <stdlib.h>
Zombie *zombieHorde(int N, std::string name);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <nb of zombies>" << std::endl;
        return 1;
    }
    int N = std::atoi(argv[1]);
    Zombie *horde = zombieHorde(N, "Bomboclat");
    if (horde == NULL)
        return 1;

    std::cout << std::endl << "##########Create the Zombie(s)##########" << std::endl << std::endl;

    for (int i = 0; i < N; i++)
        horde[i].announce();

    std::cout << std::endl << "##########Deconstructors##########" << std::endl << std::endl;

    delete []horde;
    return 0;
}
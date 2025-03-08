#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cout << "bro seriously... put a valid number please..." << std::endl;
        return NULL;
    }
    Zombie  *zombieHorde = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombieHorde[i].set_name(name);
    return zombieHorde;
}
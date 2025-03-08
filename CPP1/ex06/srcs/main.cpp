#include "../includes/Harl.hpp"

int main(int ac, char **av)
{
    (void)ac;
    Harl harl;

    if (ac != 2) {
        std::cout << "Usage : " << av[0] << " <level_name>" << std::endl;
        return 1;
    }
    if (av[1] != NULL)
        harl.complain(av[1]);
    else
        harl.complain("");
}
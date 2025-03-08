#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void    Harl::debug(void)
{
    std::cout << "[DEBUG]\nRho too busy to create a real debug.\n" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[INFO]\nFlash Info ! no there is no informations\n" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[WARNING]\nWarning Warning !\n" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ERROR]\nBip biip bip biipp there is an error\n" << std::endl;
}

void    Harl::complain(std::string level)
{
    int level_int = -1;
    std::string functions_name[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if(!level.compare(functions_name[i]))
            level_int = i;
    }
    switch(level_int) {
    case 0:
        this->debug();
    case 1:
        this->info();
    case 2:
        this->warning();
    case 3:
        this->error();
        break;
    default :
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
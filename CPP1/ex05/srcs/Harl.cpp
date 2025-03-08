#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void    Harl::debug(void)
{
    std::cout << "Rho too busy to create a real debug." << std::endl;
}

void    Harl::info(void)
{
    std::cout << "Flash Info ! no there is no informations" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "Warning Warning !" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "Bip biip bip biipp there is an error" << std::endl;
}

void    Harl::complain(std::string level)
{
    int find = 0;
    void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string functions_name[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if(!level.compare(functions_name[i])) {
            (this->*functions[i])();
            find = 1;
        }
    }
    if (find == 0)
        std::cout << "Harl don't have any type of this level." << std::endl;
}
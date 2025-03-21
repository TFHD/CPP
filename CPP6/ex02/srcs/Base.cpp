#include "Base.hpp"

Base::~Base(void)
{
    if (LOG)
        std::cout << "\e[32mThe Base\e[0m was destroyed !" << std::endl;
}
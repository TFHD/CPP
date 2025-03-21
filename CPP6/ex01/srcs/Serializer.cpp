#include "Serializer.hpp"

Serializer::Serializer(void)
{
    if (LOG)
        std::cout << "\e[32mThe Serializer\e[0m default was created !" << std::endl;
}

Serializer::~Serializer(void)
{
    if (LOG)
        std::cout << "\e[32mThe Serializer\e[0m was destroyed !" << std::endl;
}

Serializer::Serializer(const Serializer &cpy)
{
    if (LOG)
        std::cout << "\e[32mThe Serializer\e[0m was copied !" << std::endl;
   *this = cpy;
}

Serializer	&Serializer::operator=(const Serializer &src)
{
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe Serializer\e[0m Assignation operator called" << std::endl; }
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data *>(raw));
}
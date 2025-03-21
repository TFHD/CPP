#include <iostream>
#include "../includes/MutantStack.hpp"

template <class T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
    if (LOG)
        std::cout << "\e[32mThe MutantStack\e[0m default was created !" << std::endl;
}

template <class T>
MutantStack<T>::~MutantStack(void)
{
    if (LOG)
        std::cout << "\e[32mThe MutantStack\e[0m was destroyed !" << std::endl;
}

template <class T>
MutantStack<T>::MutantStack(const MutantStack &cpy) : std::stack<T>(cpy)
{
    if (LOG)
        std::cout << "\e[32mThe MutantStack\e[0m copy was created !" << std::endl;
}

template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
    if (LOG)
        std::cout << "\e[32mThe MutantStack\e[0m Assignation operator called" << std::endl;
    if (this != &src)
        std::stack<T>::operator=(src);
    return *this;
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return (std::stack<T>::c.begin());
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return (std::stack<T>::c.end());
}
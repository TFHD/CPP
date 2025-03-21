#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <class T>

void iter(T *adr, int len, void (*func)(T &)) {
    for (int i = 0; i < len; i++)
        func(adr[i]);
}

template <class T>
void print_elem(T &value) {
    std::cout << value << std::endl;
}

#endif
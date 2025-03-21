#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define auto __auto_type

template <class T>

unsigned int easyfind(T &container, int nb) {
    unsigned int i = 0;
    for (__auto_type it = container.begin(); it != container.end(); it++) {
        if (nb == *it)
            return i;
        i++;
    }
    return -1;
}
#endif
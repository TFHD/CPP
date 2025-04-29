#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

template <typename T>
void easyfind(T &container, int nb) {

    typename T::const_iterator it;
    it = std::find(container.begin(), container.end(), nb);
    if (it != container.end())
        std::cout << "Element found : [" << nb << "] at index " << it - container.begin() << std::endl;
    else
        std::cout << "No element found : [" << nb << "]" << std::endl;
}
#endif
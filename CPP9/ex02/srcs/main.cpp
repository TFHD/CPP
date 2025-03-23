#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac <= 1) {
        std::cout << "Usage : /PmergeMe [list_of_positive_numbers]" << std::endl;
        return 1;
    }
    PmergeMe pmergeme;

    try { pmergeme.sort(ac, av); }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; return 1; } 
    return 0;
}
#include "../includes/PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac <= 1) {
        std::cerr << "Error: No input sequence provided." << std::endl;
        return 1;
    }
	PmergeMe pmergeme;
    pmergeme.mergeSort(ac, av);

    return 0;
}
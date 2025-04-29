#include "../includes/PmergeMe.hpp"
#include <deque>

int main(int ac, char **av)
{
    if (ac <= 1) {
        std::cout << "Usage : /PmergeMe [list_of_positive_numbers]" << std::endl;
        return 1;
    }
    PmergeMe<std::vector<int> > pmergemedeque;
    PmergeMe<std::deque<int> > pmergemequeue;
    clock_t start1 = clock();
    pmergemedeque.sort(ac, av, true);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << pmergemedeque.getSizeList() << " elements with std::deque container: " << time1 << " us" << std::endl;
    clock_t start2 = clock();
    pmergemequeue.sort(ac, av, false);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << pmergemequeue.getSizeList() << " elements with std::vector container: " << time2 << " us" << std::endl;
    return 0;
}
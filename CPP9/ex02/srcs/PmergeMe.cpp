#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    if (LOG)
        std::cout << "\e[32mThe PmergeMe\e[0m default was created !" << std::endl;
    
}

PmergeMe::~PmergeMe(void)
{
    if (LOG)
        std::cout << "\e[32mThe PmergeMe\e[0m was destroyed !" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
    if (LOG)
        std::cout << "\e[32mThe PmergeMe\e[0m copy was created !" << std::endl;
    *this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (LOG)
        std::cout << "\e[32mThe PmergeMe\e[0m Assignation operator called" << std::endl;
    if (this != &src) {}
    return *this;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    std::deque<int>::iterator it1, it2, copy_iter;
    for (it1 = arr.begin() + 1; it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        copy_iter = it2;
        while (it2 != arr.begin() && *(--copy_iter) > temp)
        {
            copy_iter = it2;
            *it2 = *(--copy_iter);
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr)
{
    std::list<int>::iterator it1, it2, copy_iter;
    for (it1 = ++arr.begin(); it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        copy_iter = it2;
        while (it2 != arr.begin() && *(--copy_iter) > temp)
        {
            copy_iter = it2;
            *it2 = *(--copy_iter);
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}

template <class T>
void PmergeMe::display(const T &container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::mergeSort(int ac, char **av)
{
    srand(time(NULL));
    for (int i = 1; i < ac; ++i)
    {
        int value = std::atoi(av[i]);
        if (value <= 0)
        {
            std::cerr << "Error: Invalid input value \"" << av[i] << "\". Only positive integers are allowed." << std::endl;
			exit(1);
        }
        this->inputDeque.push_back(value);
        this->inputList.push_back(value);
    }
    std::cout << "Before: ";
    display(this->inputDeque);

    clock_t start1 = clock();
    mergeInsertSortDeque(this->inputDeque);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    clock_t start2 = clock();
    mergeInsertSortList(this->inputList);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    display(this->inputDeque);
    std::cout << "Time to process a range of " << this->inputDeque.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << this->inputList.size() << " elements with std::list container: " << time2 << " us" << std::endl;
    if (this->inputDeque == std::deque<int>(this->inputList.begin(), this->inputList.end()))
        std::cout << "The sorted sequences are equal." << std::endl;
    else
        std::cout << "The sorted sequences are not equal." << std::endl;
}

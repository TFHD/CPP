#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <list>
# include <algorithm>
# include <ctime>
# include <cstdlib>
# define LOG 0

class PmergeMe {

    private:
        std::deque<int> inputDeque;
        std::list<int> inputList;

    public:
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &src);

        template <typename T>
        void display(const T& container);
        void mergeSort(int ac, char **av);
        void mergeInsertSortDeque(std::deque<int>& arr);
        void mergeInsertSortList(std::list<int>& arr);
};

#endif
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <iostream>
# include <iterator>
# include <cstdlib>
# include <sstream>
# include <cstdio>
# include <ctime>
# define LOG 0

class PmergeMe {

    private:
        std::vector<int> vec;
        std::list<int> list;

    public:
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &src);

        void sort(int ac, char **av);
        void execute(std::vector<int> &vector, std::list<int> &list);
        void mergeSort(std::list<int> &list);
        void sort_elem(std::list<int> &left, std::list<int> &right, std::list<int> &list);
        void mergeSort(std::vector<int> &vector);
        void sort_elem(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector);
        template <class T>
        void display(T &container);
};

#endif
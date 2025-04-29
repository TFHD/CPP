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

template <typename T>
class PmergeMe {

    private:
        T pairs;
        int last;

    public:
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &src);

        void sort(int ac, char **av, bool printable);
        void sortPairs(T *pairs, int size);
        void doPending(T *pairs, int pairsSize, std::vector<int> jacob);
        void addPend(int pairsSize, int b, std::vector<int> *pend, std::vector<std::string> *pend_desc, T *pairs);
        void addMain(int pairsSize, int b, std::vector<int> *main, std::vector<std::string> *main_desc, T *pairs);
        void print_value(T pairs);
        T generatePairs(std::vector<int> av);
        int getSizePairs(T *pairs);
        int getSizeList(void) const;
};
# include "PmergeMe.tpp"
#endif
#include "../includes/PmergeMe.hpp"
#include <cmath>
#include <algorithm>

template <typename T>
PmergeMe<T>::PmergeMe(void)
{
    if (LOG)
        std::cout << "\e[32mThe PmergeMe\e[0m default was created !" << std::endl;
}

template <typename T>
PmergeMe<T>::~PmergeMe(void)
{
    if (LOG)
        std::cout << "\e[32mThe PmergeMe\e[0m was destroyed !" << std::endl;
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &cpy)
{
    if (LOG)
        std::cout << "\e[32mThe PmergeMe\e[0m copy was created !" << std::endl;
    *this = cpy;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &src)
{
    if (LOG)
        std::cout << "\e[32mThe PmergeMe\e[0m Assignation operator called" << std::endl;
    if (this != &src) {
        this->last = src.last;
        for (int i = 0; i < src.size(); i++)
            this->pairs[i] = src.pairs[i];
    }
    return *this;
}

template <typename T>
T    PmergeMe<T>::generatePairs(std::vector<int> av)
{
    if (av.size() % 2 != 0) {
        this->last = av.back();
        av.pop_back();
    }

    for (int i = 0; i < (int)av.size(); i += 2) {

        if (av[i] < av[i + 1]) {
            std::swap(av[i], av[i + 1]);
        }

        this->pairs.push_back(av[i + 1]);
        this->pairs.push_back(av[i]);
    }

    return this->pairs;
}

template <typename T>
int PmergeMe<T>::getSizePairs(T *pairs)
{
    int size = 1;
    while (size * 2 < (int)(pairs->size() / 2))
        size *= 2;
    return size;
}

template <typename T>
void PmergeMe<T>::print_value(T pairs)
{
    int j = 0;
    for (int i = 0; i < (int)pairs.size(); i++, j++) {
        std::cout << pairs[i];
        if (i + 1 < (int)pairs.size()) 
            std::cout << ",";
    }
    std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::sortPairs(T *pairs, int i)
{
    if (pairs->size() <= 1)
        return ;
    
    int middle = 1;
    while (middle < (int)(pairs->size() / 2))
        middle *= 2;
    T letfPairs(pairs->begin(), pairs->begin() + middle);
    T rightPairs(pairs->begin() + middle, pairs->end());
    sortPairs(&letfPairs, i + 1);
    sortPairs(&rightPairs, i + 1);
    for(int i = 0; i < (int)letfPairs.size(); i++)
        (*pairs)[i] = letfPairs[i];
    for (int i = 0; i < (int)rightPairs.size(); i++)
        (*pairs)[i + middle] = rightPairs[i];
    if ((*pairs)[(pairs->size() / 2) - 1] > (*pairs)[pairs->size() - 1] && (i || middle == (int)(pairs->size() / 2))) {
        for (int i = 0; i < (int)(pairs->size() / 2); i++) {
            std::swap((*pairs)[i], (*pairs)[pairs->size() / 2 + i]);
        }
    }
}

template <typename T>
void    PmergeMe<T>::addPend(int pairsSize, int b, std::vector<int> *pend, std::vector<std::string> *pend_desc, T *pairs)
{
    int push = 2;
    if (b-- <= 1)
        return;
    for(int i = pairsSize * 2; i <= (int)pairs->size() && b > 0; i++) {
        if ((i - 1)% (pairsSize * 2) == pairsSize && b == 0) {
            std::stringstream tmp_stream;
            std::string desc = "b";
            tmp_stream << desc << push;
            pend_desc->push_back(tmp_stream.str());
            return;
        }
        if (i % (pairsSize * 2) < pairsSize) {
            pend->push_back((*pairs)[i]);
        }
        if (i % (pairsSize * 2) == pairsSize) {
            std::stringstream tmp_stream;
            std::string desc = "b";
            tmp_stream << desc << push;
            pend_desc->push_back(tmp_stream.str());
            push++;
            b--;
        }
    }
}

template <typename T>
void    PmergeMe<T>::addMain(int pairsSize, int a, std::vector<int> *main, std::vector<std::string> *main_desc, T *pairs)
{
    std::string desc = "b1";
    int push = 1;
    for (int i = 0; i < pairsSize; i++)
        main->push_back((*pairs)[i]);
    main_desc->push_back(desc);
    for(int i = pairsSize; i < (int)pairs->size() && a > 0; i++) {
        if (i % (pairsSize * 2) >= pairsSize) {
            main->push_back((*pairs)[i]);
        }
        if (i % (pairsSize * 2) == 0) {
            std::stringstream tmp_stream;
            desc = "a";
            tmp_stream << desc << push;
            main_desc->push_back(tmp_stream.str());
            push++;
            a--;
        }
    }
}

void generatejacobsthalNumbers(std::vector<int> *jacob, int pairsSize)
{
    int next, sum, prev, next_tmp;
    sum = prev = next_tmp = 3;
    next = 5;
    jacob->push_back(prev);
    jacob->push_back(next);
    while (sum < pairsSize) {
        next_tmp = next;
        next = prev * 2 + next;
        jacob->push_back(next);
        prev = next_tmp;
        sum += next;
    }
}

template <typename T>
int PmergeMe<T>::getSizeList(void) const
{
    return this->pairs.size();
}

int getCurrentJacob(std::vector<int> jacob, int currentJacob)
{
    if (!currentJacob)
        return (2);
    return (jacob[currentJacob] - jacob[currentJacob - 1]);
}

int getIndexByJacob(int nb, std::vector<int> pend, std::vector<std::string> *pend_desc, int pairsSize)
{
    int index_under = 1;
    for (int i = 0; i < (int)pend_desc->size(); i++) {
        const char *str = (*pend_desc)[i].c_str();
        char* charPtr = const_cast<char*>(str);
        if (std::strtol(charPtr + 1, 0, 0) < nb)
            index_under = (i + 1) * pairsSize - 1;
        if (std::strtol(charPtr + 1, 0, 0) == nb)
            return ((i + 1) * pairsSize - 1);
    }
    if ((int)pend.size() == pairsSize)
        return (pend.size() - 1);

    return (index_under);
}

int getIndexEndSearch(std::string node, std::vector<std::string> main_desc, std::vector<int> main, int pairsSize)
{
    const char *nodeC = node.c_str();
    char* charPtr = const_cast<char*>(nodeC);
    int nodeMinus = std::strtol(charPtr + 1, 0, 0);
    std::stringstream tmp_stream;
    std::string searchNode = "a";
    tmp_stream << searchNode << nodeMinus;
    if (pairsSize == 0)
        pairsSize++;
    for (int i = 0; i < (int)main_desc.size(); i++) {
        if (main_desc[i] == tmp_stream.str())
            return ((i + 1) * pairsSize - 1);
    }
    return (main.size() - 1);
}

void insertPendToMain(std::vector<int> *main, std::vector<int> *pend, std::vector<std::string> *main_desc, std::vector<std::string> *pend_desc, int index, int end_search, int pairsSize)
{
    int index_to_insert = 0;
    int diff = __INT_MAX__;
    for (int i = pairsSize - 1; i <= end_search; i += pairsSize) {
        if ((*pend)[index] < (*main)[i] && (*main)[i] - (*pend)[index] < diff) {
            index_to_insert = i;
            diff = (*main)[i] - (*pend)[index];
        }
    }
    if ((*pend)[index] > (*main)[main->size() - 1] && diff == __INT_MAX__)
        index_to_insert = main->size();
    else if (index_to_insert)
        index_to_insert -= pairsSize - 1;
    for (int i = 0; i < pairsSize; i++) {
        main->insert(main->begin() + index_to_insert, (*pend)[index - i]);
        pend->erase(pend->begin() + index - i);
    }
    if (pairsSize == 1)
        index_to_insert--;
    main_desc->insert(main_desc->begin() + ((index_to_insert + 1) / pairsSize), (*pend_desc)[((index + 1) / pairsSize) - 1]);
    pend_desc->erase(pend_desc->begin() + ((index + 1) / pairsSize) - 1);
}


template <typename T>
void PmergeMe<T>::doPending(T *pairs, int pairsSize, std::vector<int> jacobsthalNumbers)
{
    std::vector<int> main;
    std::vector<int> pend;
    std::vector<std::string> main_desc;
    std::vector<std::string> pend_desc;
    int a, b;
    if (pairsSize == 0)
        return;
    int numPairs = pairs->size() / pairsSize;
    a = b = numPairs / 2;
    if (numPairs & 1)
        b++;
    addPend(pairsSize, b, &pend, &pend_desc, pairs);
    addMain(pairsSize, a, &main, &main_desc, pairs);
    int push = 1;
    int currentJacob = 0;
    while (pend.size())
    {
        if (pend_desc.size()) {
            int index = getIndexByJacob(jacobsthalNumbers[currentJacob], pend, &pend_desc, pairsSize);
            int end_search = getIndexEndSearch(pend_desc[((index + 1) / pairsSize) - 1], main_desc, main, pairsSize);
            insertPendToMain(&main, &pend, &main_desc, &pend_desc, index, end_search, pairsSize);
            if (++push > getCurrentJacob(jacobsthalNumbers, currentJacob)) {currentJacob++ ; push = 1; }
        }
    }
    for (int i = 0; i < (int)main.size(); i++)
        (*pairs)[i] = main[i];
    if (pairsSize == 1)
        doPending(pairs, 0, jacobsthalNumbers);
    else
        doPending(pairs, pairsSize / 2, jacobsthalNumbers);

}

template <typename T>
void PmergeMe<T>::sort(int ac, char **av, bool printable)
{
    std::vector<int> data;
    std::vector<int> jacobsthalNumbers;
    this->last = std::strtol(av[ac - 1], 0, 0);
    for (int i = 1; i < ac; i++) {
        int push = std::strtol(av[i], 0, 0);
        if (push < 0 || !(std::istringstream(av[i]) >> push)) {
            std::cerr << "\e[31mOnly positive numbers ! \e[0m" << std::endl;
            return;
        }
        if (std::find(data.begin(), data.end(), push) != data.end()) {
            std::cerr << "\e[31mDuplicates numbers are unautorized in this code ! Sorry :{ \e[0m" << std::endl;
            return;
        }
        data.push_back(push);
    }
    if (printable) {
        std::cout << "Before : ";
        for (int i = 0; i < (int)data.size(); i++) {
            std::cout << data[i];
            if (i + 1 < (int)data.size()) 
                std::cout << ",";
        }
        std::cout <<std::endl;
    }
    if (data.size() > 1) {
        T   pairs = generatePairs(data);
        sortPairs(&pairs, 0);
        generatejacobsthalNumbers(&jacobsthalNumbers, pairs.size());
        doPending(&pairs, this->getSizePairs(&pairs), jacobsthalNumbers);
        if ((ac - 1) & 1) {
            typename T::iterator it = std::lower_bound(pairs.begin(), pairs.end(), this->last);
            pairs.insert(it, this->last);
        }
        if (printable) {
            std::cout << "After : ";
            print_value(pairs);
        }
    }
    else {
        T pairs;
        pairs.push_back(data[0]);
        if (printable) {
            std::cout << "After : ";
            print_value(pairs);
        }
    }
}
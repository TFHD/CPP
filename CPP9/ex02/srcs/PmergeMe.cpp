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

void PmergeMe::sort(int ac, char **av)
{
    std::list<int> list;
    std::vector<int> vector;
    for (int i = 1; i < ac; ++i){
        if (av[i] != 0 && *av[i] != 0) {
            std::istringstream is(av[i]);
            int value;
            is >> value;
            if (value < 0 || !is.eof())
                throw std::runtime_error("Error: Invalid input");
            list.push_back(value);
            vector.push_back(value);
            }
        }
    execute(vector, list); 
}

void PmergeMe::execute(std::vector<int> &vector, std::list<int> &list)
{
    std::cout << "Before :  ";
    this->display(list);
    std::clock_t begin_l = std::clock();
    mergeSort(list);
    std::clock_t end_l = std::clock();
    double time_l = static_cast<double>(end_l - begin_l) / CLOCKS_PER_SEC * 1000;
    std::clock_t begin_v = std::clock();
    mergeSort(vector);
    std::clock_t end_v = std::clock();
    double time_v = static_cast<double>(end_v - begin_v) / CLOCKS_PER_SEC * 1000;
    std::cout << "After :   ";
    this->display(vector);
    std::cout << "Time to process a range of " << this->list.size() << " elements with std::list : " << time_l << " us" << std::endl;
    std::cout << "Time to process a range of " << this->list.size() << " elements with std::vector : " << time_v << " us" << std::endl;
}

template <class T>
void PmergeMe::display(T &container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::mergeSort(std::vector<int> &vector)
{
    if (vector.size() < 2)
        return ;

    int mid = vector.size() / 2;
    std::vector<int> left(vector.begin(), vector.begin() + mid);
    std::vector<int> right(vector.begin() + mid, vector.end());
    
    mergeSort(left);
    mergeSort(right);
    sort_elem(left, right, vector);
    this->vec = vector;
}

void PmergeMe::sort_elem(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector)
{
    int i = 0;
    while (!left.empty() && !right.empty()) {
        if (*left.begin() < *right.begin()) {
            vector[i++] = left.front();
            left.erase(left.begin());
        } else {
            vector[i++] = right.front();
            right.erase(right.begin());
        }
    }

    while (!left.empty()) {
        vector[i++] = left.front();
        left.erase(left.begin());
    }
    while (!right.empty()) {
        vector[i++] = right.front();
        right.erase(right.begin());
    }
}

void PmergeMe::mergeSort(std::list<int> &list)
{
    if (list.size() < 2)
        return ;
    std::list<int> left;
    std::list<int> right;
    std::list<int>::iterator it = list.begin();
    
    int mid = list.size() / 2;
    for (int i = 0; i < mid; ++i)
        left.push_back(*it++);
    for (unsigned long i = mid; i < list.size(); ++i)
        right.push_back(*it++);
    mergeSort(left);
    mergeSort(right);
    sort_elem(left, right, list);
    this->list = list;
}

void PmergeMe::sort_elem(std::list<int> &left, std::list<int> &right, std::list<int> &list)
{
    std::list<int>::iterator it = list.begin();
    while (!left.empty() && !right.empty()) {
        if (*left.begin() < *right.begin()) {
            *it++ = left.front();
            left.erase(left.begin());
        } else {
            *it++ = right.front();
            right.erase(right.begin());
        }
    }

    while (!left.empty()) {
        *it++ = left.front();
        left.erase(left.begin());
    }
    while (!right.empty()) {
        *it++ = right.front();
        right.erase(right.begin());
    }
}

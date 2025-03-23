#include "MutantStack.hpp"
#include <iostream>
#include <list>

//------------------------------FUNCTIONS FOR LIST LIKE MUTANTSTACK DISPLAY------------------------------------//

template <class T>
void showValuesLikeStackList(std::list<T> &list)
{
    typename std::list<T>::iterator ite = list.end();
    unsigned int size = list.size();
    unsigned int i = 0; 

    --ite;
    while (i < size)
    {
        std::cout<< "|  " << *ite << "  |" << std::endl;
        --ite;
        i++;
    }
    std::cout << "|_____|" <<std::endl;
}

template <class T>
void showValuesList(std::list<T> &list)
{
    typename std::list<T>::iterator it = list.begin();
    typename std::list<T>::iterator ite = list.end();

    std::cout << "{"; 
    while (list.size() >= 1 && it != ite)
    {
        std::cout << *it;
        ++it;
        if (it != ite)
            std::cout << ", "; 
    }
    std::cout << "}" <<std::endl;
}

template <class T>
void addList(std::list<T> &list, T value)
{
    list.push_back(value);
    typename std::list<T>::iterator ite = list.end();
    ite--;
    std::cout << "Push : " << *ite << "  ";
    showValuesList(list);
    
}

template <class T>
void removeList(std::list<T> &list)
{
    std::cout << "Pop : " << *list.begin() << "  ";
    list.pop_back();
    showValuesList(list);
}

//------------------------------FUNCTIONS FOR MUTATIONTSTACK DISPLAY------------------------------------//

template <class T>
void showValuesLikeStack(MutantStack<T> &stack)
{
    typename MutantStack<T>::iterator ite = stack.end();
    unsigned int size = stack.size();
    unsigned int i = 0; 

    --ite;
    while (i < size)
    {
        std::cout<< "|  " << *ite << "  |" << std::endl;
        --ite;
        i++;
    }
    std::cout << "|_____|" <<std::endl;
}

template <class T>
void showValues(MutantStack<T> &stack)
{
    typename MutantStack<T>::iterator it = stack.begin();
    typename MutantStack<T>::iterator ite = stack.end();

    std::cout << "{"; 
    while (stack.size() >= 1 && it != ite)
    {
        std::cout << *it;
        ++it;
        if (it != ite)
            std::cout << ", "; 
    }
    std::cout << "}" <<std::endl;
}

template <class T>
void add(MutantStack<T> &stack, T value)
{
    stack.push(value);
    std::cout << "Push : " << stack.top() << "  ";
    showValues(stack);
    
}

template <class T>
void remove(MutantStack<T> &stack)
{
    std::cout << "Pop : " << stack.top() << "  ";
    stack.pop();
    showValues(stack);
}

//------------------------------MAIN FOR MUTANTSTACK------------------------------------//

void MutantStackTests(void)
{
    MutantStack<int> stack;

    add(stack, 5);
    add(stack, 17);
    remove(stack);
    add(stack, 3);
    add(stack, 5);
    add(stack, 4);
    add(stack, 1);

    std::cout << "Values in the MutantStack : " << std::endl;
    showValuesLikeStack(stack);

    MutantStack<int> stack_copy(stack);
    std::cout << "Values in the MutantStack_copy : " << std::endl;
    showValuesLikeStack(stack_copy);

    MutantStack<int> stack_copy_1;
    
    add(stack_copy_1, 100);
    add(stack_copy_1, 42);
    stack_copy_1 = stack;
    std::cout << "Values in the MutantStack_copy_1 : " << std::endl;
    showValuesLikeStack(stack_copy_1);
}

//-----------------------------------MAIN FOR LIST--------------------------------------//

void listTestLikeMutantStack(void)
{
    std::list<int> list;

    addList(list, 5);
    addList(list, 17);
    removeList(list);
    addList(list, 3);
    addList(list, 5);
    addList(list, 4);
    addList(list, 1);

    std::cout << "Values in the MutantStack : " << std::endl;
    showValuesLikeStackList(list);
}

//-----------------------------------SUBJECT MAIN---------------------------------------//

void subjectMain(void)
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

int main(void)
{
    std::cout << std::endl << "\e[31mTESTS FOR MUTANTSTACK\e[0m" << std::endl << std::endl;
    MutantStackTests();
    std::cout << std::endl << "\e[31mTESTS FOR LIST TO PROVE IT'S SAME BEHAVOUR THAN MUTANTSTACK\e[0m" << std::endl << std::endl;
    listTestLikeMutantStack();
    std::cout << std::endl << "\e[31mTESTS SUBJECT MAIN\e[0m" << std::endl << std::endl;
    subjectMain();
}
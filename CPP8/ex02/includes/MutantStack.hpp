#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# define LOG 0

template <class T>
class MutantStack : public std::stack<T> {

    private:

    public:
        MutantStack(void);
        ~MutantStack(void);
        MutantStack(const MutantStack &cpy);
        MutantStack &operator=(const MutantStack &src);

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

# include "MutantStack.tpp"
#endif

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
# include <stdexcept>
# define LOG 1
# define auto __auto_type

class Span {

    private:
        std::vector<int> span;
        unsigned int size;
        unsigned int current_size;

    public:
        Span(void);
        Span(unsigned int N);
        ~Span(void);
        Span(const Span &cpy);
        Span &operator=(const Span &src);

        int shortestSpan(void);
        int longestSpan(void);
        int getMin(void) const;
        int getMax(void) const;
        int getIndex(unsigned int index) const;
        void addNumber(int number);
        void addNumberList(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        class NotEnoughValues : public std::exception {
            
            public:
                virtual const char *what() const throw();
        };

        class TooMuchValue : public std::exception {
            
            public:
                virtual const char *what() const throw();
        };
};

#endif
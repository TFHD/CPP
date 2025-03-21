#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <string>
# include <sstream>
# define LOG 0

class RPN {

    private:
        std::stack<int> stack;

    public:
        RPN(void);
        ~RPN(void);
        RPN(const RPN &cpy);
        RPN &operator=(const RPN &src);

        std::string solveRPN(std::stack<char> &stack);

};

#endif
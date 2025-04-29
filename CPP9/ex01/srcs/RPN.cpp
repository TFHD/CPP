#include "RPN.hpp"

RPN::RPN(void)
{
    if (LOG)
        std::cout << "\e[32mThe RPN\e[0m default was created !" << std::endl;
}

RPN::~RPN(void)
{
    if (LOG)
        std::cout << "\e[32mThe RPN\e[0m was destroyed !" << std::endl;
}

RPN::RPN(const RPN &cpy)
{
    if (LOG)
        std::cout << "\e[32mThe RPN\e[0m was copied !" << std::endl;
   *this = cpy;
}

RPN	&RPN::operator=(const RPN &src)
{
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe Span\e[0m Assignation operator called" << std::endl; }
	return *this;
}

std::string RPN::solveRPN(std::stack<char> &stack)
{
    std::stack<long long> rpn;
    long long x = 0;
    long long y = 0;

    for (int i = 0; stack.size() != 0; i++) {
        if (stack.top() == '+' || stack.top() == '*' || stack.top() == '-' || stack.top() == '/') {
            if (rpn.size() <= 1) throw std::runtime_error("Error");
            x = rpn.top();
            rpn.pop();
            y = rpn.top();
            rpn.pop();
            if (stack.top() == '+') rpn.push(y + x);
            if (stack.top() == '*') rpn.push(y * x);
            if (stack.top() == '/') {
                if (x == 0) throw std::runtime_error("Error : division by 0 is forbidden");
                rpn.push(y / x);
            }
            if (stack.top() == '-') rpn.push(y - x);
        }
        else rpn.push(stack.top() - '0');
        stack.pop();
    }
    if (rpn.size() != 1) throw std::runtime_error("Error");
    if (rpn.top() > __INT_MAX__) return "+inf";
    if (rpn.top() < -__INT_MAX__ + 1) return "-inf";
    std::ostringstream oss;
    oss << rpn.top();
    std::string str = oss.str();
    return str;
}
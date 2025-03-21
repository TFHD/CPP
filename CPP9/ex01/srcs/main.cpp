#include "RPN.hpp"
#include <cstdlib>

std::string parse_zero(std::string expression)
{
    std::string expr_final;
    for (int i = 0; expression[i]; i++) {
        int j = 0;
        int k = 0;
        if (expression[i] == '0') {
            int sum = std::atoi(expression.substr(i, expression.length()).c_str());
            if (sum > 9)
                return "";
            while (expression[i + j] == '0') { j++; }
            if (!std::isdigit(expression[i + j]) && expression[i + j] != ' ')
                return "";
            if (expression[i + j] == ' ')
                j--;
        }
        expr_final.insert(k, 1 , expression[i + j]);
        k++;
        i += j;
    }
    return expr_final;
}

int main(int ac, char **av)
{
    RPN rpn;
    std::string expression;
    std::stack<char> stack;

    if (ac != 2) {
        std::cerr << "Usage : /RPN <mathematical_expression>" << std::endl;
        return 1;
    }
    expression = parse_zero(av[ac - 1]);
    if (expression.empty()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    for (int i = 0; i < (int)expression.length(); i++) {
        if (i % 2 == 0 && (std::isdigit(expression[i]) || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')) {
            stack.push(expression[i]);
        }
        else {
            if (expression[i] != ' ') {
                std::cout << "Error" << std::endl;
                return 1;
            }
        }
    }
    try { std::cout << rpn.solveRPN(stack) << std::endl; }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; return 1; }
}
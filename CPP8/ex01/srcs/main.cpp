#include "Span.hpp"
#include <iostream>

int main(void)
{

    //------------------SPAN ADDNUMBER---------------------//

    std::cout << "SPAN ADDNUMBER" << std::endl << std::endl;
    Span sp = Span(5);
    try
    {   
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    }
    catch(const Span::TooMuchValue &e) { std::cout << e.what() << std::endl; }
    try
    {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const Span::NotEnoughValues &e) { std::cout << e.what() << std::endl; }
    std::cout << std::endl;

    //------------------SPAN COPY ASSIGNEMENT---------------------//

    std::cout << std::endl << "SPAN COPY ASSIGNEMENT" << std::endl << std::endl;
    Span sp_copy(4);
    
    try{ sp_copy = sp; }
    catch(const Span::TooMuchValue &e) { std::cout << e.what() << std::endl; }
    try
    {
        std::cout << sp_copy.shortestSpan() << std::endl;
        std::cout << sp_copy.longestSpan() << std::endl;
    }
    catch(const Span::NotEnoughValues &e) { std::cout << e.what() << std::endl; }
    std::cout << std::endl;

    //------------------SPAN COPY BY CONSTRUCTOR---------------------//

    std::cout << std::endl << "SPAN COPY BY CONSTRUCTOR" << std::endl << std::endl;
    Span sp_copy2(sp);
    try
    {
        std::cout << sp_copy2.shortestSpan() << std::endl;
        std::cout << sp_copy2.longestSpan() << std::endl;
    }
    catch(const Span::NotEnoughValues &e) { std::cout << e.what() << std::endl; }
    std::cout << std::endl;

    //------------------SPAN ADDNUMBERLIST---------------------//

    std::cout << std::endl << "SPAN ADDNUMBERLIST" << std::endl << std::endl;
    Span sp2 = Span(5);
    std::vector<int> array;
    array.push_back(6);
    array.push_back(3);
    array.push_back(17);
    array.push_back(9);
    array.push_back(11);
    try
    { sp2.addNumberList(array.begin(), array.end()); }
    catch(const Span::TooMuchValue &e) { std::cout << e.what() << std::endl; }
    try
    {
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch(const Span::NotEnoughValues &e) { std::cout << e.what() << std::endl; }
    std::cout << std::endl;
    return 0;
}
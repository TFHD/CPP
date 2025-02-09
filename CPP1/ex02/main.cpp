#include <iostream>
#include <string>

int main(void)
{
    std::string var = "HI THIS IS BRAIN";
    std::string &stringREF = var;
    std::string *stringPTR = &var;

    std::cout << "{   var   } address : " << &var << " value : " << var << std::endl;
    std::cout << "{stringREF} address : " << &stringREF << " value : " << stringREF << std::endl;
    std::cout << "{stringPTR} address : " << stringPTR << " value : " << *stringPTR << std::endl;
    return 0;
}
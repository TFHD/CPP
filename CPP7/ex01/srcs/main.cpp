#include "iter.hpp"

int main(void) {

    int len = 5;
    int arr1[] = { 1, 2, 3, 4, 5 };

    std::cout << "array 1: " << std::endl;
    ::iter(arr1, len, &print_elem);

    double arr2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    std::cout << std::endl << "array 2: " << std::endl;
    ::iter(arr2, len, &print_elem);

    char arr3[] = { 'a', 'b', 'c', 'd', 'e' };

    std::cout << std::endl << "array 3: " << std::endl;
    ::iter(arr3, len, &print_elem);

    std::string arr4[] = { "one", "two", "three", "four", "five" };

    std::cout << std::endl << "array 4: " << std::endl;
    ::iter(arr4, len, &print_elem);

    return 0;
}
#include <iostream>
#include "Fixed.hpp"
#include <cmath>


int main(void) {

	Fixed a;
	Fixed b( 5.05f );
	Fixed c( 2 );

	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	std::cout << "b + c = " << (b + c) << std::endl;
	std::cout << "b - c = " << (b - c) << std::endl;
	std::cout << "c - b = " << (c - b) << std::endl;
	std::cout << "b * c = " << (b * c) << std::endl;
	std::cout << "b / c = " << (b / c) << std::endl;
	std::cout << "c / b = " << (c / b) << std::endl;

    std::cout << "c > b = " << ( c > b ) << std::endl;
    std::cout << "c < b = " << ( c < b ) << std::endl;
    std::cout << "c >= b = " << ( c >= b ) << std::endl;
    std::cout << "c <= b = " << ( c <= b ) << std::endl;
    std::cout << "c == b = " << ( c == b ) << std::endl;
    std::cout << "c != b = " << ( c != b ) << std::endl;

	std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl;
	std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;

    const Fixed d(b);
    const Fixed e(c);
    std::cout << "const max(b, c) = " << Fixed::max(d, e) << std::endl;
	std::cout << "const min(b, c) = " << Fixed::min(d, e) << std::endl;

    return 0;
}
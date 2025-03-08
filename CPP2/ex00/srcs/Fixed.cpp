#include "Fixed.hpp"

Fixed::Fixed(void) : coma(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &src)
		this->coma = src.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->coma;
}

void	Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->coma = raw;
}

#include "Fixed.hpp"

Fixed::Fixed(void) : coma(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->coma = number << this->bit;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->coma = roundf(number * (1 << this->bit));
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
    return this->coma;
}

void	Fixed::setRawBits(const int raw)
{
    this->coma = raw;
}

float   Fixed::toFloat(void) const
{
	return (this->coma / (float)(1 << this->bit));
}

int   Fixed::toInt(void) const
{
	return (this->coma >> this->bit);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

#include "Fixed.hpp"

Fixed::Fixed(void) : coma(0) {}

Fixed::Fixed(const int number)
{
	this->coma = number << this->bit;
}

Fixed::Fixed(const float number)
{
	this->coma = roundf(number * (1 << this->bit));
}

Fixed::~Fixed(void) {}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &src)
{
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

bool	Fixed::operator>(const Fixed &fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed &fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++(void)
{
	this->coma++;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->coma--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed fixed_tmp = *this;

	++this->coma;
	return (fixed_tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed fixed_tmp = *this;

	--this->coma;
	return (fixed_tmp);
}

Fixed   Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return (fixed1);
	return (fixed2);
}

Fixed   Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return (fixed1);
	return (fixed2);
}

Fixed   Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return (fixed1);
	return (fixed2);
}

Fixed   Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return (fixed1);
	return (fixed2);
}

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const float _x, const float _y) : x(_x) , y(_y) {}

Point::~Point(void) {}

Point::Point(Point const &copy) : x(copy.getX()), y(copy.getY()) {}

Point	&Point::operator=(Point const &src)
{
    (void)src;
	return *this;
}

const Fixed   &Point::getX(void) const
{
    return this->x;
}

const Fixed   &Point::getY(void) const
{
    return this->y;
}
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        ~Point(void);
	    Point(const Point &src);
        Point(float _x, float _y);
        Point	    &operator=(const Point &src);
        const Fixed &getX(void) const;
        const Fixed &getY(void) const;
};

#endif
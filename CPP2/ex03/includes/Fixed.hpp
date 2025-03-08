#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

    private:
        int                 coma;
        const static int    bit = 8;

    public:
    	Fixed(void);
        Fixed(const int number);
        Fixed(const float number);
        ~Fixed(void);
	    Fixed(const Fixed &src);
        Fixed	&operator=(const Fixed &src);
        bool	operator<(const Fixed &fixed);
        bool	operator>(const Fixed &fixed);
        bool	operator<=(const Fixed &fixed);
        bool	operator>=(const Fixed &fixed);
        bool	operator!=(const Fixed &fixed);
        bool	operator==(const Fixed &fixed);
        float	operator+(Fixed fixed) const;
        float	operator-(Fixed fixed) const;
        float	operator*(Fixed fixed) const;
        float	operator/(Fixed fixed) const;
        Fixed	operator++();
        Fixed	operator--();
        Fixed	operator++(int);
        Fixed	operator--(int);
        Fixed   static min(Fixed &fixed1, Fixed &fixed2);
        Fixed   static min(const Fixed &fixed1, const Fixed &fixed2);
        Fixed   static max(Fixed &fixed1, Fixed &fixed2);
        Fixed   static max(const Fixed &fixed1, const Fixed &fixed2);

        int		getRawBits(void) const;
        void	setRawBits(const int raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
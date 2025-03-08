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

        int		getRawBits(void) const;
        void	setRawBits(const int raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif

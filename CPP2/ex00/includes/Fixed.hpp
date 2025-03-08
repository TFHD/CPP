#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

    private:
        int                 coma;
        const static int    bit = 8;

    public:
    	Fixed(void);
        ~Fixed(void);
	    Fixed(const Fixed &src);
        Fixed	&operator=(const Fixed &src);

        int		getRawBits(void) const;
        void	setRawBits(const int raw);
};

#endif

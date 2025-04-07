#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <cstdlib>
# include <cctype>
# include <cerrno>
# include <climits>
# include <cfloat>
# include <cmath>
# include <iomanip>
# define LOG 1

class ScalarConverter {

    private:
        ScalarConverter(void);

    public:
        virtual ~ScalarConverter(void) = 0;
        ScalarConverter(const ScalarConverter &cpy);
        ScalarConverter &operator=(const ScalarConverter &src);

        static void convert(std::string convert);
};

#endif
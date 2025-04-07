#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    if (LOG)
        std::cout << "\e[32mThe ScalarConverter\e[0m default was created !" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
    if (LOG)
        std::cout << "\e[32mThe ScalarConverter\e[0m was destroyed !" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
    if (LOG)
        std::cout << "\e[32mThe ScalarConverter\e[0m was copied !" << std::endl;
   *this = cpy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe ScalarConverter\e[0m Assignation operator called" << std::endl; }
	return *this;
}

void ScalarConverter::convert(std::string convert)
{
	char *end;
    int len_convert;
    for (len_convert = 0; convert[len_convert] != '\0'; len_convert++);

	if (convert == "nan" || convert == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (convert == "+inf" || convert == "+inff" || convert == "inf" || convert == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}

	if (convert == "-inf" || convert == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}
	if (len_convert == 1 && (convert[0] >= 32 && convert[0] <= 126) && !(convert[0] >= 48 && convert[0] <= 57)) {
		char c = convert[0];
		std::cout << "char: \'" << c << "\'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return;
	}
	long int i = std::strtol(convert.c_str(), &end, 10);
	if (*end == '\0' && i >= INT_MIN && i <= INT_MAX) {
		if (i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else if (i < 32 || i > 126)
			std::cout << "char: Non displayable" << std::endl;
		else 
            std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
		return;
	}

    bool point_before_f = false;
    bool is_f = false;
    float f = std::strtof(convert.c_str(), &end);
    for (int i = 0; i < len_convert; i++)
    {
        if (convert[i] == '.')
            point_before_f = true;
        if (convert[i] == 'f' && point_before_f)
            is_f = true;
    }
    if ((*end == 'f' || *end == 'F') && *(end + 1) == '\0' && (is_f || f != f)) {
        std::cout << "char: ";
        if (f >= 0 && f <= 127 && (static_cast<int>(f) >= 32 && static_cast<int>(f) <= 126))
            std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
        else if (f < 0 || f > 127)
            std::cout << "impossible" << std::endl;
        else if (f < ' ' || f > '~')
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;

        std::cout << "int: ";
        if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX))
            std::cout << static_cast<int>(f) << std::endl;
        else
            std::cout << "impossible" << std::endl;

        std::cout << "float: ";
        if (f > FLT_MAX || f < -FLT_MAX)
            std::cout << "impossible" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

        std::cout << "double: ";
        if (f > DBL_MAX || f < -DBL_MAX)
            std::cout << "impossible" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
        return;  
    }

    double d = std::strtod(convert.c_str(), &end);
    errno = 0;
    if (*end == '\0') {
        std::cout << "char: ";
        if (d >= 0 && d <= 127 && (static_cast<int>(d) >= 32 && static_cast<int>(d) <= 126))
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else {
			if (d < 0 || d > 127)
				std::cout << "impossible" << std::endl;
			else if (d < ' ' || d > '~')
				std::cout << "Non displayable" << std::endl;
            else if (d != d)
                std::cout << "impossible" << std::endl;
        }

        std::cout << "int: ";
        if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX))
            std::cout << static_cast<int>(d) << std::endl;
        else
            std::cout << "impossible" << std::endl;

        std::cout << "float: ";
		if (d > FLT_MAX)
			std::cout << "+inf" << "f" << std::endl;
        else if (d < -FLT_MAX)
			std::cout << "-inf" << "f" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;

        std::cout << "double: ";
        if (d > DBL_MAX || d < -DBL_MAX)
            std::cout << "inf" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << d << std::endl;
		return;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
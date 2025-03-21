#include "../includes/Span.hpp"

Span::Span(void) : size(1), current_size(0)
{
    if (LOG)
        std::cout << "\e[32mThe Span\e[0m default was created !" << std::endl;
}

Span::Span(unsigned int N) : size(N), current_size(0)
{
    this->span.reserve(N);
    if (LOG)
        std::cout << "\e[32mThe Span\e[0m default was created !" << std::endl;
}

Span::~Span(void)
{
    if (LOG)
        std::cout << "\e[32mThe Span\e[0m was destroyed !" << std::endl;
}

Span::Span(const Span &cpy) : current_size(0)
{
    if (LOG)
        std::cout << "\e[32mThe Span\e[0m was copied !" << std::endl;
   *this = cpy;
}

Span	&Span::operator=(const Span &src)
{
    if (this == &src)
        return *this;
    this->span.reserve(src.size);
    this->size = src.size;
    for (unsigned int i = 0; i < src.size ; i++)
        this->addNumber(src.span[i]);
    this->current_size = src.current_size;
    if (LOG) { std::cout << "\e[32mThe Span\e[0m Assignation operator called" << std::endl; }
	return *this;
}

void Span::addNumber(int number)
{
    if (this->current_size < this->size)
    {
        this->span.push_back(number);
        this->current_size++;
    }
    else
        throw Span::TooMuchValue();
}

int Span::getIndex(unsigned int index) const
{
    return this->span[index];
}

int Span::longestSpan(void)
{
    if (this->span.size() <= 1)
        throw Span::NotEnoughValues();
    std::vector<int> tmp = this->span;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

int Span::shortestSpan(void)
{
    if (this->span.size() <= 1)
        throw Span::NotEnoughValues();
    std::vector<int> tmp = this->span;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size(); i++) {
        int tmp_span = tmp[i] - tmp[i - 1];
        if (tmp_span < min)
            min = tmp_span;
    }
    return min;
}

void	Span::addNumberList(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->span.size() + std::distance(begin, end) > this->size)
		throw Span::TooMuchValue();
	this->span.insert(this->span.end(), begin, end);
}


const char *Span::TooMuchValue::what() const throw() { return ("Too much values !"); }
const char *Span::NotEnoughValues::what() const throw() { return ("Not Enough values !"); }
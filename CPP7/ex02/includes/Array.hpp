#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T>
class Array {

    private:
        T *array;
        unsigned int _size;

    public:
        Array(void) : array(new T()), _size(0) {};
        Array(unsigned int n) : array(new T[n]), _size(n) {};
        ~Array(void) {
            if (_size != 0)
                delete []array;
            else
                delete array;
        };

        Array(const Array &src) : array(new T[src._size]), _size(src._size) {
            for (unsigned int i = 0; i < src._size; i++)
                array[i] = src.array[i];
        };
        Array &operator=(const Array &cpy) {
            if (this != &cpy) {
                if (_size != 0)
                    delete []array;
                else
                    delete array;
                array = new T[cpy._size];
                _size = cpy._size;
                for (unsigned int i = 0; i < _size; i++)
                    array[i] = cpy.array[i];
            }
            return *this;
        };
        T &operator[](unsigned int i) {
            if (i < 0 || i >= _size)
                throw Array::OutOfBoundsException();
            return array[i];
        };

        unsigned int size(void) const { return _size; };

        class OutOfBoundsException : public std::exception {

            public:
                virtual const char *what() const throw() {
                    return ("Index out of bounds !");
                }
        };
};

#endif
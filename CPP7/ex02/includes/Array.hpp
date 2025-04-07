#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {

    private:
        T *array;
        unsigned int _size;

    public:
        Array(void) : array(new T()), _size(0) {};
        Array(unsigned int n) : array(new T[n]), _size(n) { fill(0); };
        ~Array(void) {
            if (this->_size != 0)
                delete []this->array;
            else
                delete this->array;
        };

        Array(const Array &src) : array(new T[src._size]), _size(src._size) {
            for (unsigned int i = 0; i < src._size; i++)
                array[i] = src.array[i];
        };

        Array &operator=(const Array &cpy) {
            if (this != &cpy) {
                if (this->_size != 0)
                    delete []this->array;
                else
                    delete this->array;
                if (cpy._size == 0) {
                    this->array = new T();
                    return *this;
                }
                this->array = new T[cpy._size];
                this->_size = cpy._size;
                for (unsigned int i = 0; i < this->_size; i++)
                    array[i] = cpy.array[i];
            }
            return *this;
        };

        T &operator[](unsigned int i) {
            if (i < 0 || i >= this->_size)
                throw std::runtime_error("Index out of bounds !");
            return array[i];
        };

        unsigned int size(void) const { return this->_size; };
        void fill(int number) { for(unsigned int i = 0; i < this->size(); i++) array[i] = number; }

};

#endif
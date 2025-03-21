#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

# define LOG 1

class Serializer {

    private:

    public:
        Serializer(void);
        virtual ~Serializer(void) = 0;
        Serializer(const Serializer &cpy);
        Serializer &operator=(const Serializer &src);

        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};


#endif
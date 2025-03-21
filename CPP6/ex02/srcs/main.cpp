#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate(void)
{
    srand(time(NULL));
    int i = rand() % 3;
    if (i == 0)
        return new A();
    if (i == 1)
        return new B();
    if (i == 2)
        return new C();
    return (NULL);
}

void identify(Base *p)
{
    if (A *a = dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (B *b = dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (C *c = dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try {
        A &a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch(std::exception &e) {}

    try {
        B &b = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        (void)b;
    }
    catch(std::exception &e) {}

    try {
        C &c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        (void)c;
    }
    catch(std::exception &e) {}
}

int main(void)
{
    Base *base_find = generate();

    //TEST void identify(Base *p)
    std::cout << "Result of base.identify(Base *p)" << std::endl;
    identify(base_find);

    //TEST void identify(Base &p)
    std::cout << std::endl << "Result of base.identify(Base &p)" << std::endl;
    Base &base_find_ref = *base_find;
    identify(base_find_ref);
    std::cout << std::endl;
    delete base_find;

    return 0;
}
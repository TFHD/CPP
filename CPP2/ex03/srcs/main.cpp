#include <iostream>
#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {

    Point a(1.0f, 1.0f);
    Point b(5.0f, 1.0f);
    Point c(3.0f, 4.0f);
    Point pt(3.0f, 2.0f);

    Point d(-2.0f, 4.0f);
    Point e(-4.0f, 0.0f);
    Point f(5.0f, -3.0f);
    Point pt1(-1.0f, 2.999f);

    std::cout << "\e[35m[Tirangle Points 1: " << a.getX().toFloat() << " " << a.getY().toFloat() << " ; "
    << b.getX().toFloat() << " " << b.getY().toFloat() << " ; "
    << c.getX().toFloat() << " " << c.getY().toFloat()
    << "]\e[0m" << std::endl;
    if (bsp(a, b, c, pt)) {
        std::cout << "\e[35m[Point1: " << pt.getX().toFloat() << " " << pt.getY().toFloat() << "]\e[0m" << std::endl;
        std::cout << "\e[32mtrue\e[0m" << std::endl;
    }
    else {
        std::cout << "\e[35m[Point1: " << pt.getX().toFloat() << " " << pt.getY().toFloat() << "]\e[0m" << std::endl;
        std::cout << "\e[31mfalse\e[0m" << std::endl;
    }

    std::cout << std::endl << "\e[35m[Tirangle Points 2: " << d.getX().toFloat() << " " << d.getY().toFloat() << " ; "
    << e.getX().toFloat() << " " << e.getY().toFloat() << " ; "
    << f.getX().toFloat() << " " << f.getY().toFloat()
    << "]\e[0m" << std::endl;
    if (bsp(d, e, f, pt1)) {
        std::cout << "\e[35m[Point1: " << pt1.getX().toFloat() << " " << pt1.getY().toFloat() << "]\e[0m" << std::endl;
        std::cout << "\e[32mtrue\e[0m" << std::endl;
    }
    else {
        std::cout << "\e[35m[Point1: " << pt1.getX().toFloat() << " " << pt1.getY().toFloat() << "]\e[0m" << std::endl;
        std::cout << "\e[31mfalse\e[0m" << std::endl;
    }

    return 0;
}
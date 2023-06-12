#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
    Point a;
    Point b(0, 5);
    Point c(5, 0);
    Point test;

    std::cout << "test same as a : " << bsp(a, b, c, test) << std::endl;
    return 0;
}
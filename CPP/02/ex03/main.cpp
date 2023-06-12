#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
    Point a;
    Point b(0, 5);
    Point c(5, 0);
    Point test1;
	Point test2(2, 2);
	Point test3(0, 2);
	Point test4(-1, 5);

	std::cout << "test is on a : " << bsp(a, b, c, test1) << std::endl;
	std::cout << "test is in abc : " << bsp(a, b, c, test2) << std::endl;
	std::cout << "test is on ab : " << bsp(a, b, c, test3) << std::endl;
	std::cout << "test is out of abc : " << bsp(a, b, c, test4) << std::endl;
    return 0;
}
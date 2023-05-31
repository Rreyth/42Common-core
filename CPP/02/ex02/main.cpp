#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c(3.07f);

    std::cout << "increment" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "pre " << ++a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "post " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "decrement" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "pre " << --a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "post " << a-- << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "arithmetic operators" << std::endl;
    std::cout << "b * c = " << b * c << std::endl;
    std::cout << "b + c = " << b + c << std::endl;
    std::cout << "b - c = " << b - c << std::endl;
    std::cout << "b / c = " << b / c << std::endl;
    std::cout << "comparison operators" << std::endl;
    std::cout << "b = " << b << " | c = " << c << std::endl;
    std::cout << "b > c ? " << (b > c) << std::endl;
    std::cout << "b < c ? " << (b < c) << std::endl;
    std::cout << "b >= c ? " << (b >= c) << std::endl;
    std::cout << "b <= c ? " << (b <= c) << std::endl;
    std::cout << "b == c ? " << (b == c) << std::endl;
    std::cout << "c == c ? " << (c == c) << std::endl;
    std::cout << "b != c ? " << (b != c) << std::endl;
    std::cout << "c != c ? " << (c != c) << std::endl;
    std::cout << "max " << Fixed::max( c, b ) << std::endl;
    std::cout << "min " << Fixed::min( c, b ) << std::endl;

    return 0;
}
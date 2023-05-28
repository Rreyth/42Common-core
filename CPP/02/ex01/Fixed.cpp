#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->f_point = 0;
}

Fixed::Fixed(const int point)
{
    std::cout << "Int constructor called" << std::endl;
    this->f_point = (point << this->bits);
}

Fixed::Fixed(const float point)
{
    std::cout << "Float constructor called" << std::endl;
    this->f_point = (int)roundf(point * (1 << this->bits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    float float_nb;
    float_nb = (float)this->f_point / (1 << this->bits);
    return (float_nb);
}

int Fixed::toInt( void ) const
{
    return (this->f_point >> this->bits);
}

Fixed & Fixed::operator = (const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->f_point = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->f_point;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->f_point = raw;
}

std::ostream & operator << (std::ostream &out, const Fixed &a)
{
    out << a.toFloat();
    return out;
}
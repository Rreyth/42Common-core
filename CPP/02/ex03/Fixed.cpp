#include "Fixed.hpp"

Fixed::Fixed()
{
    //std::cout << "Default constructor called" << std::endl;
    this->f_point = 0;
}

Fixed::Fixed(const int point)
{
    //std::cout << "Int constructor called" << std::endl;
    this->f_point = (point << this->bits);
}

Fixed::Fixed(const float point)
{
    //std::cout << "Float constructor called" << std::endl;
    this->f_point = (int)roundf(point * (1 << this->bits));
}

Fixed::Fixed(const Fixed &other)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
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

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->f_point;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->f_point = raw;
}

std::ostream & operator << (std::ostream &out, const Fixed &a)
{
    out << a.toFloat();
    return out;
}

Fixed & Fixed::operator = (const Fixed &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    this->f_point = other.getRawBits();
    return *this;
}

bool Fixed::operator > (const Fixed &other) const
{
    return (f_point > other.f_point);
}

bool Fixed::operator < (const Fixed &other) const
{
    return (f_point < other.f_point);
}

bool Fixed::operator >= (const Fixed &other) const
{
    return (f_point >= other.f_point);
}

bool Fixed::operator <= (const Fixed &other) const
{
    return (f_point <= other.f_point);
}

bool Fixed::operator == (const Fixed &other) const
{
    return (f_point == other.f_point);
}

bool Fixed::operator != (const Fixed &other) const
{
    return (f_point != other.f_point);
}

Fixed Fixed::operator + (const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator - (const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator * (const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator / (const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed & Fixed::operator ++ ()
{
    ++f_point;
    return *this;
}

Fixed Fixed::operator ++ (int)
{
    Fixed tmp = *this;
    ++f_point;
    return tmp;
}

Fixed & Fixed::operator -- ()
{
    --f_point;
    return *this;
}

Fixed Fixed::operator -- (int)
{
    Fixed tmp = *this;
    --f_point;
    return tmp;
}

Fixed & Fixed::min (Fixed &first, Fixed &second)
{
    if (first < second)
        return first;
    return second;
}

const Fixed & Fixed::min (const Fixed &first, const Fixed &second)
{
    if (first < second)
        return first;
    return second;
}

Fixed & Fixed::max (Fixed &first, Fixed &second)
{
    if (first > second)
        return first;
    return second;
}

const Fixed & Fixed::max (const Fixed &first, const Fixed &second)
{
    if (first > second)
        return first;
    return second;
}
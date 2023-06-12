#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(), y()
{
}

Point::Point(const float p1, const float p2) : x(p1), y(p2)
{
}

Point::Point(const Point &other) : x(other.x.toFloat()), y(other.y.toFloat())
{
}

Point::~Point()
{
}

Fixed	Point::getXpos()
{
	return (x);
}

Fixed	Point::getYpos()
{
	return (y);
}

Point & Point::operator = (const Point &other)
{
    (void) other;
    return *this;
}

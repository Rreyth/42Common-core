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

Point & Point::operator = (const Point &other)
{
    (void) other;
    return *this;
}

bool Point::operator == (const Point &other) const
{
    if (x != other.x)
        return (false);
    if (y != other.y)
        return (false);
    return (true);
}

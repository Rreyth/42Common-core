#include "Point.hpp"

Point::Point()
{
    x(0);
    y(0);
}

Point::Point(const float p1, const float p2)
{
    x(p1);
    y(p2);
}

Point::Point(const Point &other)
{
    *this = other;
}

Point::~Point()
{

}

Point & Point::operator = (const Point &other)
{
    x(other.x.toFloat);
    y(other.y.toFloat);
}

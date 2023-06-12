#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point{
    private:
            const Fixed x;
            const Fixed y;
    public:
            Point();
            Point(const float p1, const float p2);
            Point(const Point &other);
            ~Point();
            Point & operator = (const Point &other);
            bool operator == (const Point &other) const;
};


#endif
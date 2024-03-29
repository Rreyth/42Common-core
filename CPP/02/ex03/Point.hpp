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
			Fixed	getXpos();
			Fixed	getYpos();
            Point & operator = (const Point &other);
};


#endif
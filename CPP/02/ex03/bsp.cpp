#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    //false si c'est l'un des point ou si c'est sur l'un des cote du triangle
    //false si c'est a l'ext
    //true si c'est a l'inter
    if (point == a || point == b || point == c)
        return (false);
    return (true);
}
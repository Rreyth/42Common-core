#include "Point.hpp"
#include "Fixed.hpp"

int	det_triangle(Point first, Point second, Point point)
{
	Fixed	fp[2];
	Fixed	sp[2];

	fp[0] = point.getXpos() - first.getXpos();
	fp[1] = point.getYpos() - first.getYpos();
	sp[0] = point.getXpos() - second.getXpos();
	sp[1] = point.getYpos() - second.getYpos();

	Fixed	det((fp[0] * sp[1]) - (fp[1] * sp[0]));
	if (det > 0)
		return (1);
	else if (det < 0)
		return (-1);
	return (0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	int	det_apc = det_triangle(a, c, point);
	int	det_cpb = det_triangle(c, b, point);
	int	det_bpa = det_triangle(b, a, point);

	if (det_apc == det_cpb && det_cpb == det_bpa)
		return (true);
    return (false);
}
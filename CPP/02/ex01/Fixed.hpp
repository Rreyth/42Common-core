#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
    private:
            int f_point;
            static const int bits = 8;
    public:
            Fixed();
            Fixed(const int point);
            Fixed(const float point);
            Fixed(const Fixed &other);
            ~Fixed();
            int getRawBits(void) const;
            void setRawBits(int const raw);
            float toFloat( void ) const;
            int toInt( void ) const;
            Fixed & operator = (const Fixed &other);
};

std::ostream & operator << (std::ostream &out, const Fixed &a);

#endif
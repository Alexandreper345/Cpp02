#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int              _fixedValue;
    static const int _fractional_bits = 8;
public:
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(/* args */);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed();

    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
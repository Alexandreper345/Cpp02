#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int _fixedValue;
    static const int _fractional_bits = 8;
public:
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    Fixed(/* args */);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed();
};

#endif

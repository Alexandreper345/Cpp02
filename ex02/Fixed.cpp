#include <cmath>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedValue = n << _fractional_bits;
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedValue = roundf(n * (1 << _fractional_bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedValue = other._fixedValue;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedValue;
}

void Fixed::setRawBits(int const raw)
{
    _fixedValue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)_fixedValue / (1 << _fractional_bits);
}

int Fixed::toInt(void) const
{
    return _fixedValue >> _fractional_bits;
}

bool Fixed::operator>(const Fixed &other) const
{
    return _fixedValue > other._fixedValue;
}

bool Fixed::operator<(const Fixed &other) const
{
    return _fixedValue < other._fixedValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return _fixedValue >= other._fixedValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return _fixedValue <= other._fixedValue;
}

bool Fixed::operator==(const Fixed &other) const
{
    return _fixedValue == other._fixedValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return _fixedValue != other._fixedValue;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    ++_fixedValue;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++_fixedValue;
    return temp;
}

Fixed& Fixed::operator--()
{
    --_fixedValue;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --_fixedValue;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

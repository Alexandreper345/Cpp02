#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    _fixedValue = other._fixedValue;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _fixedValue = rhs._fixedValue;
    return (*this);
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedValue = value << _fractional_bits;
}

Fixed::Fixed(const float value){
    std::cout << "Float constructor called" << std::endl;
    _fixedValue = roundf(value * (1 << _fractional_bits));
}


Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return  (_fixedValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedValue = raw;
}

float   Fixed::toFloat(void) const {
    return ((float)_fixedValue / (1 << _fractional_bits));
}

int     Fixed::toInt(void) const {
    return (_fixedValue >> _fractional_bits);    
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
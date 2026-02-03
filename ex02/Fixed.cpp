#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
    return _fixedValue;
}

void Fixed::setRawBits(int const raw)
{
    _fixedValue = raw;
}

bool    Fixed::operator>(const Fixed &rhs) const {
    return (this->_fixedValue > rhs._fixedValue);
}

bool Fixed::operator<(const Fixed &rhs) const {
    return this->_fixedValue < rhs._fixedValue;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return this->_fixedValue >= rhs._fixedValue;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return this->_fixedValue <= rhs._fixedValue;
}

bool Fixed::operator==(const Fixed &rhs) const {
    return this->_fixedValue == rhs._fixedValue;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return this->_fixedValue != rhs._fixedValue;
}

Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_fixedValue + rhs._fixedValue);
    return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_fixedValue - rhs._fixedValue);
    return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(
        (this->_fixedValue * rhs._fixedValue) >> _fractional_bits
    );
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(
        (this->_fixedValue << _fractional_bits) / rhs._fixedValue);
    return (result);
}

Fixed &Fixed::operator++(){
    _fixedValue++;
    return *this;
}

Fixed &Fixed::operator++(){
    Fixed temp(*this);
    _fixedValue++;
    return (temp);
}

Fixed &Fixed::operator--(){
    _fixedValue--;
    return *this;
}

Fixed &Fixed::operator--(){
    Fixed temp(*this);
    _fixedValue--;
    return (temp);
}

static Fixed &min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);
}

static const Fixed &min(const Fixed &a, const Fixed &b) {
    return (a < b ? a : b);
}

static Fixed &max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

static const Fixed &max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
}

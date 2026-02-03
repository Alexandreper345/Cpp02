#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedValue = other._fixedValue;
}

Fixed &Fixed::operator=(const Fixed &rhs){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedValue = rhs._fixedValue;
    return (*this);
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return  (_fixedValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedValue = raw;
}
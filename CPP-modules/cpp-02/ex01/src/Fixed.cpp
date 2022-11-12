#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called\n";
    this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &rhs) {
    std::cout << "Copy constructor called\n";
    *this = rhs;
}

Fixed& Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return this->_fixedPointValue;
}

void    Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}
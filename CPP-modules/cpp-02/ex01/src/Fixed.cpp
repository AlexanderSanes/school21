#include "../include/Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
    std::cout << "Default constructor called\n";
    this->_value = 0;
}

Fixed::Fixed(const int n) : _value(n << _bits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _value(std::roundf(n * (1 << _bits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs) {
    std::cout << "Copy constructor called\n";
    *this = rhs;
}

Fixed& Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return this->_value;
}

void    Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float   Fixed::toFloat() const {
    return static_cast<float>(_value) / (1 << _bits);
}

int     Fixed::toInt() const {
    return this->_value >> _bits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
    o << i.toFloat();
    return o;
}
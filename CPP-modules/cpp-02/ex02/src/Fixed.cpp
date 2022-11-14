#include "../include/Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
    // std::cout << "Default constructor called\n";
    this->_value = 0;
}

Fixed::Fixed(const int n) : _value(n << _bits) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _value(std::roundf(n * (1 << _bits))) {
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs) {
    // std::cout << "Copy constructor called\n";
    *this = rhs;
}

Fixed& Fixed::operator=(const Fixed &rhs) {
    // std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const {
    // std::cout << "getRawBits member function called\n";
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

bool    Fixed::operator>(const Fixed &rhs) const {
    return this->getRawBits() > rhs.getRawBits();
}

bool    Fixed::operator<(const Fixed &rhs) const {
    return this->getRawBits() < rhs.getRawBits();
}

bool    Fixed::operator>=(const Fixed &rhs) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool   Fixed::operator<=(const Fixed &rhs) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool  Fixed::operator==(const Fixed &rhs) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool    Fixed::operator!=(const Fixed &rhs) const {
    return this->getRawBits() != rhs.getRawBits();
}

Fixed   Fixed::operator+(const Fixed &rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(const Fixed &rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(const Fixed &rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(const Fixed &rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&   Fixed::operator++() {
    ++this->_value;
    return *this;
}

Fixed   Fixed::operator++(int) {
    Fixed tmp(*this);
    tmp._value = this->_value++;
    return tmp;
}

Fixed& Fixed::operator--() {
    --this->_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    tmp._value = this->_value--;
    return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _value;
    static const int    _bits = 8;

public:
    Fixed();
    Fixed(const Fixed &rhs);
    Fixed(const int n);
    Fixed(const float n);
    Fixed& operator=(const Fixed &rhs);
    ~Fixed();

    int     getRawBits() const;
    void    setRawBits(int const raw);

    float   toFloat() const;
    int     toInt() const;

    bool    operator>(const Fixed &rhs) const ;
    bool    operator<(const Fixed &rhs) const ;
    bool    operator>=(const Fixed &rhs) const ;
    bool    operator<=(const Fixed &rhs) const ;
    bool    operator==(const Fixed &rhs) const ;
    bool    operator!=(const Fixed &rhs) const ;

    Fixed   operator+(const Fixed &rhs) const ;
    Fixed   operator-(const Fixed &rhs) const ;
    Fixed   operator*(const Fixed &rhs) const ;
    Fixed   operator/(const Fixed &rhs) const ;

    Fixed&  operator++(); // prefix
    Fixed   operator++(int); // postfix
    Fixed&  operator--(); // prefix
    Fixed   operator--(int); // postfix

    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
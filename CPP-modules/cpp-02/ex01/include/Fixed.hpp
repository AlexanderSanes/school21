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
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
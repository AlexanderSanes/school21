/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:04:02 by ael-khni          #+#    #+#             */
/*   Updated: 2022/11/18 13:28:34 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <fstream>
#include <limits>

enum e_type
{
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERALS
};

class Converter
{

private:
    char    _c;
    int     _n;
    float   _f;
    double  _d;

    bool    _impossible;

    std::string _str;
    e_type      _type;

public:
    Converter();
    Converter(const Converter& src);
    ~Converter();

    Converter& operator=(const Converter& rhs);

    char    getC() const;
    void    setC(char c);

    int     getI() const;
    void    setI(int n);

    float   getF() const;
    void    setF(float f);

    double  getD() const;
    void    setD(double d);

    void    convert();

    void    setStr(std::string str);
    std::string    getStr() const;

    e_type  getType() const;
    void    setType();

    bool    isChar() const;
    bool    isInt() const;
    bool    isFloat() const;
    bool    isDouble() const;

    bool    isImpossible();

    void    printChar() const ;
    void    printInt() const ;
    void    printFloat() const ;
    void    printDouble() const ;

    bool    isLiterals() const;

    class ConverterException : public std::exception
    {
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Converter& rhs);

#endif
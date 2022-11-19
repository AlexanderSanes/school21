/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:25:44 by ael-khni          #+#    #+#             */
/*   Updated: 2022/11/19 15:28:02 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span& src)
{
    *this = src;
}

Span& Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        this->_n = rhs._n;
        this->_list = rhs._list;
    }
    return *this;
}

Span::~Span(void)
{
}

void Span::addNumber(int n)
{
    if (_list.size() >= _n)
        throw std::out_of_range("Span::addNumber: span is full");
    _list.push_back(n);
}

void Span::fillSpan(std::list<int>::const_iterator itBegin, std::list<int>::const_iterator itEnd)
{
    if (_list.size() >= _n)
        throw std::out_of_range("Span::addNumber: span is full");
    _list.insert(_list.end(), itBegin, itEnd);
}

const std::list< int >* Span::getList(void) const
{
    return &_list;
}

unsigned int    Span::longestSpan(void) const
{
    if (_list.size() < 2)
        throw std::out_of_range("Span::longestSpan: span is empty");
    return (*std::max_element(_list.begin(), _list.end()) - *std::min_element(_list.begin(), _list.end()));
}

unsigned int Span::shortestSpan(void) const
{
    if (_list.size() < 2)
        throw std::out_of_range("Span::shortestSpan: span is empty");
    std::list<int>  sorted_list(_list.begin(), _list.end());
    sorted_list.sort();
    unsigned int  min = Span::longestSpan();
    for (std::list<int>::const_iterator it = sorted_list.begin(); it != sorted_list.end(); ++it)
    {
        std::list<int>::const_iterator tmp_it = it;
        ++tmp_it;
        if (std::abs(*tmp_it - *(it)) <  static_cast<int>(min))
            min = std::abs(*tmp_it - *(it));
    }
    return min;
}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
    for (std::list<int>::const_iterator it = span.getList()->begin(); it != span.getList()->end(); ++it)
        os << *it << " ";
    return os;
}
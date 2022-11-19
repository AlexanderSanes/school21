/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:25:58 by ael-khni          #+#    #+#             */
/*   Updated: 2022/11/19 14:43:36 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <exception>

class Span
{
private:
    std::list<int>  _list;
    unsigned int    _n;

    Span();

public:
    Span(unsigned int);
    Span(const Span&);
    ~Span();

    Span&               operator=(const Span&);
    void                addNumber(int);
    void                fillSpan(std::list<int>::const_iterator, std::list<int>::const_iterator);
    unsigned int        longestSpan() const;
    unsigned int        shortestSpan() const;

    const std::list<int>*   getList() const;
};

std::ostream& operator<<(std::ostream&, const Span&);

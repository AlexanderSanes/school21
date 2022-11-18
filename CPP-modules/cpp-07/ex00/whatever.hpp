/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 03:21:28 by ael-khni          #+#    #+#             */
/*   Updated: 2022/11/18 15:36:34 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T>
void    swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T   min(T& a, T& b)
{
    return (a < b ? a : b);
}

template<typename T>
T   max( T& a, T& b )
{
    return ( a > b ? a : b );
}

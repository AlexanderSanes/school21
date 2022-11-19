/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:53:45 by ael-khni          #+#    #+#             */
/*   Updated: 2022/11/19 14:30:18 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <list>

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
    return std::find(container.begin(), container.end(), value);
}
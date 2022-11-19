/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:53:23 by ael-khni          #+#    #+#             */
/*   Updated: 2022/11/19 14:31:27 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    const int n = 10;
    std::vector<int>        vect;
    std::list<int>          lst;
    std::array<int, 7>      arr = {12, 6, 7, 7, -2, 8, 7};
    for (int i = 0; i < n; i++)
    {
        vect.push_back(i);
        lst.push_back(i);

    }
    std::vector<int>::iterator vect_it = easyfind(vect, 2);
    std::array<int, 7>::iterator arr_it = easyfind(arr, -2);
    std::list<int>::iterator list_it = easyfind(lst, 7);
 
    if (vect_it == vect.end())
        std::cout << "Vect: Not founded\n";
    else
        std::cout << *vect_it << std::endl;

    if (arr_it == arr.end())
        std::cout << "Vect: Not founded\n";
    else
        std::cout << *arr_it << std::endl;
        
    if (list_it == lst.end())
        std::cout << "Vect: Not founded\n";
    else
        std::cout << *list_it << std::endl;

    return EXIT_SUCCESS;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:57:02 by ael-khni          #+#    #+#             */
/*   Updated: 2022/11/18 13:56:38 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int ac, char ** av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert number" << std::endl;
        return 1;
    }

    Converter c;

    try
    {
        c.setStr(av[1]);
        c.convert();

        std::cout << c;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
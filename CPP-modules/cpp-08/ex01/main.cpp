/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:33:10 by ael-khni          #+#    #+#             */
/*   Updated: 2022/11/19 15:28:29 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(-19);
        sp.addNumber(11);

        std::cout << "sp: " << sp << std::endl;

        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    } catch (std::exception& e)
    {
        std::cout << e.what() << std::endl; 
    }
    try
    {
        std::list<int>    l(10000);
        std::srand(time(NULL));
        std::generate(l.begin(), l.end(), std::rand);

        Span span(l.size());
        span.fillSpan(l.begin(), l.end());

        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        
    } catch (std::exception& e)
    {
        std::cout << e.what() << std::endl; 
    }

    return 0;
}
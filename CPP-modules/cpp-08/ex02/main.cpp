/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:21:33 by ael-khni          #+#    #+#             */
/*   Updated: 2022/08/25 14:28:51by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
int main()
{
    std::cout << "MutantStack\n";

    // MutantStack<int> mstack;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    std::cout << std::endl;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);


    std::cout << std::endl;
    std::cout << "list:\n";

   std::list< int > lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;

    lst.pop_back();
    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);

    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();
    ++it;
    --it;
    std::cout << std::endl;

    while (lst_it != lst_ite)
    {
        std::cout << *lst_it << std::endl;
        ++lst_it;
    }
    std::list<int> l(lst);

    {
		std::stack<int> s(mstack);
		MutantStack<int> st = mstack;

        std::cout << "size: " << s.size() << " (" << mstack.size() << ")" << std::endl;
		std::cout << "top: " << s.top() << " (" << mstack.top() << ")" << std::endl;
		std::cout << "size: " << st.size() << " (" << mstack.size() << ")" << std::endl;
		std::cout << "top: " << st.top() << " (" << mstack.top() << ")" << std::endl;
		st.pop();
		std::cout << "size: " << st.size() << " (" << mstack.size() << ")" << std::endl;
		std::cout << "top: " << st.top() << " (" << mstack.top() << ")" << std::endl;
	}
    
    return 0;


}


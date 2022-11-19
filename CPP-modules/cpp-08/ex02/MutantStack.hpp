#pragma once

#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>

template< typename T> 
class MutantStack : public std::stack<T>
{

private:

public:
    MutantStack()
    {
    }

    ~MutantStack()
    {
    }

    MutantStack(const MutantStack& rhs)
    {
        *this = rhs;
    }
    
    MutantStack&    operator=(const MutantStack& rhs)
    {
        std::stack<T>::operator=(rhs);
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator    iterator;

    iterator    begin()
    {
        return this->c.begin();
    }
    iterator    end()
    {
        return this->c.end();
    }
};

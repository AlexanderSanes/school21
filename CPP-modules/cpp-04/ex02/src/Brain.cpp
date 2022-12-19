#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[ Brain ]: " << "Brain created.\n";
}

Brain::~Brain()
{
    std::cout << "[ Brain ]: " << "Brain destroyed.\n";
}

Brain::Brain(const Brain& src)
{
    *this = src;
}

Brain& Brain::operator=(const Brain& src)
{
    std::cout << "[ Brain ]: " << "Brain copy called.\n";
    if ( this != &src ) {
        for ( int i = 0; i < 100; i++ ) {
            this->_ideas[i] = src._ideas[i];
        }
    }
    return *this;
}

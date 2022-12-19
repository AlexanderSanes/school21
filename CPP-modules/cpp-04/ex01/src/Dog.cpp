#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
    std::cout << "[ Dog ]: " << this->_type << " default constructor called\n";
}

Dog::~Dog()
{
    std::cout << "[ Dog ]: " << this->_type << " destructor called\n";
}

void    Dog::makeSound() const
{
    std::cout << "Bark Bark!\n";
}
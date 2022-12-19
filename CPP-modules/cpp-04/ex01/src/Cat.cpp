#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
    std::cout << "[ Cat ]: " << this->_type << " default constructor called\n";
}

Cat::~Cat()
{
    std::cout << "[ Cat ]: " << this->_type << " destructor called\n";
}

void    Cat::makeSound() const
{
    std::cout << "Meow Meow!\n";
}
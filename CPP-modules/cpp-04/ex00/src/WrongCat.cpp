#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
    std::cout << "[ WrongCat ]: " << this->_type << " default constructor called\n";
}

WrongCat::~WrongCat()
{
    std::cout << "[ WrongCat ]: " << this->_type << " destructor called\n";
}

void    WrongCat::makeSound() const
{
    std::cout << "Meow Meow!\n";
}
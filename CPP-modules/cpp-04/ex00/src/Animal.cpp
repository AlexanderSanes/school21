#include "Animal.hpp"

Animal::Animal() : _type("Anime")
{
    std::cout << "[ Animal ]: " << _type << " default constructor called\n";
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "[ Animal ]: " << _type << " init constructor called\n";
}

Animal::~Animal()
{
    std::cout << "[ Animal ]: " << _type << " destructor called\n";
}

Animal::Animal(const Animal& src)
{
    std::cout << "[ Animal ]: " << _type << " copy constructor called\n";
    *this = src;
}

Animal& Animal::operator=(const Animal& rhs)
{
    std::cout  << "[ Animal ]: " << _type << " assignment operator called\n";
    if (this != &rhs) {
        _type = rhs._type;
    }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << _type << " makeSound called\n";
}

std::string    Animal::getType() const
{
    return _type;
}

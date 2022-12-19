#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnime")
{
    std::cout << "[ WrongAnimal ]: " << _type << " default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "[ WrongAnimal ]: " << _type << " init constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[ WrongAnimal ]: " << _type << " destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
    std::cout << "[ WrongAnimal ]: " << _type << " copy constructor called\n";
    *this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    std::cout << "[ WrongAnimal ]: " << _type << " assignment operator called\n";
    if (this != &rhs) {
        _type = rhs._type;
    }
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << _type << " makeSound called\n";
}

std::string    WrongAnimal::getType() const
{
    return _type;
}

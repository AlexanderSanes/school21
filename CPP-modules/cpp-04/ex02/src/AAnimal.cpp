#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnime")
{
    std::cout << "[ AAnimal ]: " << _type << " default constructor called\n";
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "[ AAnimal ]: " << _type << " init constructor called\n";
}

AAnimal::~AAnimal()
{
    std::cout << "[ AAnimal ]: " << _type << " destructor called\n";
}

AAnimal::AAnimal(const AAnimal& src)
{
    std::cout << "[ AAnimal ]: " << _type << " copy constructor called\n";
    *this = src;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
    std::cout  << "[ AAnimal ]: " << _type << " assignment operator called\n";
    if (this != &rhs) {
        _type = rhs._type;
    }
    return *this;
}

void AAnimal::makeSound() const
{
    std::cout << _type << " makeSound called\n";
}

std::string    AAnimal::getType() const
{
    return _type;
}

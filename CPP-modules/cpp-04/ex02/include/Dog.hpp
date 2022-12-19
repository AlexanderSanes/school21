#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
{
private:

public:
    Dog();
    ~Dog();

    void   makeSound() const;
};

#endif
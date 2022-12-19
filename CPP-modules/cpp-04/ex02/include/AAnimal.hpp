#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
    std::string	_type;
    AAnimal();
    AAnimal(std::string type);

public:

    virtual ~AAnimal();

    AAnimal(const AAnimal& src);
    AAnimal& operator=(const AAnimal& rhs);

    virtual void    makeSound() const;
    std::string     getType() const; 
};

#endif
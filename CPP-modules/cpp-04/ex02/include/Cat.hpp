#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
{
private:

public:
    Cat();
    ~Cat();

    void   makeSound() const;
};

#endif
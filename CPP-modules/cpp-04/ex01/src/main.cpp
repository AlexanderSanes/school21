#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

/*
    The order of constructor and destructor:
        1. Base constructor
        2. Derived constructor
        3. Derived destructor
        4.Base destructor
*/

int main( void )
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    const Animal* animals[4] = {
        new Dog(),
        new Dog(),
        new Cat(),
        new Cat()
    };
    
    for ( int i = 0; i < 4; i++ )
        delete animals[i];

    return 0;
}
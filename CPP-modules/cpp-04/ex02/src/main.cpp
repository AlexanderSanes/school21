#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    delete j;
    delete i;

    const AAnimal* AAnimals[4] = {
        new Dog(),
        new Dog(),
        new Cat(),
        new Cat()
    };
    
    for ( int i = 0; i < 4; i++ )
        delete AAnimals[i];

    return 0;
}
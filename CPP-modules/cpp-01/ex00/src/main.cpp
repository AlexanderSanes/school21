
#include "Zombie.hpp"

int main( void )
{
    std::cout << "randomChump():\n";
    randomChump("Chumpi");

    std::string	name;
	name = "Charlie";
    std::cout << "Creating zombie on the stack.\n";
    Zombie z1(name);
	z1.announce();
    
    std::cout << "Creating zombie on the heap.\n";
    name = "Steve";
    Zombie *z2 = newZombie(name);
    z2->announce();
    delete z2;

    return 0;
}
#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name) :
	_name(name)
{
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << " has been destroyed.\n";
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

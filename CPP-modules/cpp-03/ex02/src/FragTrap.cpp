#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_name = "Unnamed";
    _HP = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "[ FragTrap ]: Default constructor is called!\n";
}

FragTrap::~FragTrap()
{
    std::cout << "[ FragTrap ]: Destructor is called!\n";
}

FragTrap::FragTrap(std::string name)
{
	_name = name;
    _HP = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "[ FragTrap ]: Init constructor is called!\nFragTrap " << _name << " is created!\n";
}

void	FragTrap::highFivesGuys()
{
	if (_HP <= 0)
	{
		std::cout << "Its impossible to give five!, FragTrap " << _name << " is dead...\n";
		return ;
	}
	std::cout << "FragTrap " << _name << " high-fived everyone!\n";
}
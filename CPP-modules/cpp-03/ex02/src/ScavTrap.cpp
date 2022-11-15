#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "Unnamed";
    _HP = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "[ ScavTrap ]: Default constructor is called!\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ ScavTrap ]: Destructor is called!\n";
}

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
    _HP = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "[ ScavTrap ]: Init constructor is called!\nScavTrap " << _name << " is created!\n";
}

ScavTrap::ScavTrap(const ScavTrap& rhs)
{
    std::cout << "[ ScavTrap ]: Copy constructor is called\n";
    *this = rhs;
    return;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "[ ScavTrap ]: Copy assignment operator is called\n";
    this->_name = rhs._name;
    this->_HP = rhs._HP;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    return *this;
}

void    ScavTrap::attack(std::string const& target)
{
	if (_HP <= 0)
	{
		std::cout << "Attack unavailable! ScavTrap " << _name << " is dead...\n";
		return;
	}
    if (_energyPoints <= 0)
	{
        std::cout << "ScavTrap " << _name << " is out of energy!/n";
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
    _energyPoints--;;
}

void    ScavTrap::guardGate()
{
	if (_HP <= 0)
		std::cout << "Gate keeper mode is unavailable! ScavTrap " << _name << " is dead...\n";
	else
    	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!\n";
}
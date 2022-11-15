#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed"), _HP(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor is called!\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Init constructor is called!\nClapTrap " << _name << " is created!\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor is called\n";
    return;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
    std::cout << "Copy constructor is called\n";
    *this = rhs;
    return;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Copy assignment operator is called\n";
    this->_name = rhs._name;
    this->_HP = rhs._HP;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    return *this;
}

void    ClapTrap::attack(std::string const& target)
{
    if (_HP <= 0)
	{
		std::cout << "Attack unavailable! ClapTrap " << _name << " is dead...\n";
		return;
	}
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy!\n";
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
    _energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_HP <= amount)
    {
        _HP = 0;
        std::cout << "ClapTrap " << _name << " is dead!\n";
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage!\n";
    _HP -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy!\n";
        return;
    }
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!\n";
    _energyPoints--;
    _HP += amount;
}

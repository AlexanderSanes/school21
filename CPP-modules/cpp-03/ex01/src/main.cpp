#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int main()
{
    ScavTrap ash("Ash");

    ash.guardGate();
    ash.attack("mob1");
    ash.takeDamage(100);
    ash.guardGate();
    ash.attack("mob2");
    ash.beRepaired(100);
    ash.guardGate();
    ash.attack("mob3");

    return 0;
}

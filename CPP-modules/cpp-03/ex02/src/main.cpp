#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

int main()
{
    FragTrap    A("Boob");

    A.highFivesGuys();
    A.attack("bib");
    A.takeDamage(100);
    A.highFivesGuys();
    A.attack("sos");
    A.beRepaired(100);
    A.highFivesGuys();
    A.attack("ok");

    return 0;
}

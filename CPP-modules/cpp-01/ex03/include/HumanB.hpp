#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string _name;
    Weapon*     _weapon;    // pointer can point to NULL (HumanB doesn't have weapon yet)

public:
    HumanB(std::string name);
    ~HumanB();

    void    attack() const;
    void    setWeapon(Weapon& weapon);
};

#endif

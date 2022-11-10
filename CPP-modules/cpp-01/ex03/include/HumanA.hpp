#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon&     _weapon;	// ref allways is pointing on something (HumanA was burn with a weapon))

public:
    HumanA();
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();

    void    attack() const;
};

#endif

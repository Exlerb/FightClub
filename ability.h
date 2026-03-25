#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>

class Ability{
    private:
        std::string name;
        int damage;
    public:
        Ability(std::string name, int damage);
        std::string get_name();

};

#endif // ABILITY_H
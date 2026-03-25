#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "ability.h"

class Character {
    private:
        std::string name;
        int totalFights;
        int deaths;
        int wins;
        int maxHP;
        Ability ability1;
        Ability ability2;
    public:
        Character(std::string name, Ability ability1, Ability ability2);
        std::string get_name();
};

#endif // CHARACTER_H

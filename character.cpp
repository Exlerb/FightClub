#include <iostream>
#include "character.h"

Character::Character(std::string name, Ability ability1, Ability ability2) : name(name), ability1(ability1), ability2(ability2) {}

std::string Character::get_name() {
    std::cout << name << std::endl;
    return name;
}
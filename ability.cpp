#include "ability.h"
#include <iostream>

Ability::Ability(std::string name, int damage) : name(name), damage(damage) {}

std::string Ability::get_name() {
    std::cout << this->name << std::endl;
    return name;
}
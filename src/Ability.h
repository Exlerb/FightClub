#pragma once
#include <string>
#include <vector>

struct Ability {
    std::string name;
    int         damage;
    int         heal;
    std::string description;
};

const std::vector<Ability>& getAbilityPool();

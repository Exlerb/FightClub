#include <iostream>
#include "character.h"
#include "ability.h"

int main() {
    Ability love("love", -7);
    Ability personal_attack("personal attack", 7);
    Ability propose_peace("propose peace", 0);
    Ability prayer("prayer", -2);
    Ability kiss("kiss", -6);
    Ability hit("bottle on head", 9);
    Character Christopher("Christopher", personal_attack, love);
    Character Henry("Henry", kiss, hit);

    prayer.get_name();
    Christopher.get_name();


    return 0;
}
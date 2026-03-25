#include "Ability.h"
vector<Ability>
const std::& getAbilityPool() {
    static const std::vector<Ability> pool = {
        { "Fireball",      40,  0,  "Hurls a ball of fire  — 40 dmg" },
        { "Slash",         25,  0,  "Quick sword strike    — 25 dmg" },
        { "Ice Shard",     30,  0,  "Flings a frozen shard — 30 dmg" },
        { "Thunder",       35,  0,  "Calls down lightning  — 35 dmg" },
        { "Heal",           0, 30,  "Recovers health       — +30 HP"  },
        { "Shield Bash",   20, 10,  "Bash + minor heal     — 20 dmg / +10 HP" },
        { "Poison Strike", 15,  0,  "Toxic slash           — 15 dmg" },
        { "Power Strike",  45,  0,  "Massive blow          — 45 dmg" },
    };
    return pool;
}

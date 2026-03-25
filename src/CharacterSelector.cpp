#include "CharacterSelector.h"
#include "Ability.h"
#include "Utils.h"
#include <iostream>

std::vector<Character> CharacterSelector::presets() const {
    const auto& pool = getAbilityPool();
    return {
        { "Warrior", 120, pool[1], pool[7] }, // Slash        + Power Strike
        { "Mage",     80, pool[0], pool[2] }, // Fireball     + Ice Shard
        { "Paladin", 100, pool[5], pool[4] }, // Shield Bash  + Heal
        { "Rogue",    90, pool[6], pool[3] }, // Poison Strike + Thunder
    };
}

std::unique_ptr<ICharacter> CharacterSelector::pickPreset() {
    auto p = presets();
    std::cout << "\n  Pre-made characters:\n";
    for (int i = 0; i < (int)p.size(); i++) {
        std::cout << "  " << (i + 1) << ". "
                  << p[i].getName()
                  << "  (HP: " << p[i].getMaxHP() << ")"
                  << "  |  " << p[i].getAbility1().name
                  << " / "   << p[i].getAbility2().name << "\n";
    }
    std::cout << "  Pick: ";
    int pick = readInt(1, (int)p.size());
    return std::make_unique<Character>(p[pick - 1]);
}

std::unique_ptr<ICharacter> CharacterSelector::buildCustom() {
    std::string name;
    std::cout << "  Character name: ";
    std::cin >> name;

    const auto& pool = getAbilityPool();
    std::cout << "\n  Available abilities:\n";
    for (int i = 0; i < (int)pool.size(); i++) {
        std::cout << "    " << (i + 1) << ". "
                  << pool[i].name << "  —  " << pool[i].description << "\n";
    }

    std::cout << "  Pick ability 1 (1-" << pool.size() << "): ";
    int a1 = readInt(1, (int)pool.size());
    std::cout << "  Pick ability 2 (1-" << pool.size() << "): ";
    int a2 = readInt(1, (int)pool.size());

    return std::make_unique<Character>(name, 100, pool[a1 - 1], pool[a2 - 1]);
}

std::unique_ptr<ICharacter> CharacterSelector::select(const std::string& label) {
    std::cout << "\n=== " << label << " ===\n";
    std::cout << "1. Choose a pre-made character\n";
    std::cout << "2. Create a custom character\n";
    std::cout << "Choice: ";
    int mode = readInt(1, 2);
    return (mode == 1) ? pickPreset() : buildCustom();
}

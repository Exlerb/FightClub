#include "Character.h"
#include <iostream>
#include <algorithm>

Character::Character(const std::string& name, int hp, Ability a1, Ability a2)
    : name_(name), maxHP_(hp), hp_(hp), ability1_(a1), ability2_(a2) {}

const std::string& Character::getName()     const { return name_;   }
int                Character::getHP()       const { return hp_;     }
int                Character::getMaxHP()    const { return maxHP_;  }
bool               Character::isAlive()     const { return hp_ > 0; }
void               Character::setHP(int hp)       { hp_ = hp;       }
void               Character::resetHP()           { hp_ = maxHP_;   }
const Ability&     Character::getAbility1() const { return ability1_; }
const Ability&     Character::getAbility2() const { return ability2_; }

void Character::useAbility(int choice, ICharacter& target) {
    const Ability& ab = (choice == 1) ? ability1_ : ability2_;
    std::cout << "\n" << name_ << " uses " << ab.name << "!\n";

    if (ab.damage > 0) {
        target.setHP(std::max(0, target.getHP() - ab.damage));
        std::cout << "  " << target.getName() << " takes " << ab.damage
                  << " damage  (" << target.getHP() << "/" << target.getMaxHP() << " HP)\n";
    }
    if (ab.heal > 0) {
        hp_ = std::min(maxHP_, hp_ + ab.heal);
        std::cout << "  " << name_ << " heals " << ab.heal
                  << " HP  (" << hp_ << "/" << maxHP_ << " HP)\n";
    }
}

#pragma once
#include "ICharacter.h"

class Character : public ICharacter {
public:
    Character(const std::string& name, int hp, Ability a1, Ability a2);

    const std::string& getName()     const override;
    int                getHP()       const override;
    int                getMaxHP()    const override;
    bool               isAlive()     const override;
    void               setHP(int hp)       override;
    void               resetHP()           override;
    const Ability&     getAbility1() const override;
    const Ability&     getAbility2() const override;
    void               useAbility(int choice, ICharacter& target) override;

private:
    std::string name_;
    int         maxHP_;
    int         hp_;
    Ability     ability1_;
    Ability     ability2_;
};

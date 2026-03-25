#pragma once
#include <string>
#include "Ability.h"

class ICharacter {
public:
    virtual ~ICharacter() = default;

    virtual const std::string& getName()     const = 0;
    virtual int                getHP()       const = 0;
    virtual int                getMaxHP()    const = 0;
    virtual bool               isAlive()     const = 0;
    virtual void               setHP(int hp)       = 0;
    virtual void               resetHP()           = 0;
    virtual const Ability&     getAbility1() const = 0;
    virtual const Ability&     getAbility2() const = 0;
    virtual void               useAbility(int choice, ICharacter& target) = 0;
};

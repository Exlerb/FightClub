#pragma once
#include "ICharacter.h"
#include "IStats.h"

class IBattle {
public:
    virtual ~IBattle() = default;

    virtual void run(ICharacter& c1, ICharacter& c2, IStats& stats) = 0;
};

#pragma once
#include "IBattle.h"

class Battle : public IBattle {
public:
    void run(ICharacter& c1, ICharacter& c2, IStats& stats) override;
};

#pragma once
#include "IGame.h"
#include "IStats.h"
#include "IBattle.h"
#include "ICharacterSelector.h"
#include <memory>

class Game : public IGame {
public:
    Game();
    void run() override;

private:
    std::unique_ptr<IStats>             stats_;
    std::unique_ptr<IBattle>            battle_;
    std::unique_ptr<ICharacterSelector> selector_;
};

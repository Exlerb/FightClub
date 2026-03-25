#pragma once
#include <memory>
#include <string>
#include "ICharacter.h"

class ICharacterSelector {
public:
    virtual ~ICharacterSelector() = default;

    virtual std::unique_ptr<ICharacter> select(const std::string& label) = 0;
};

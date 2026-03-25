#pragma once
#include "ICharacterSelector.h"
#include "Character.h"
#include <vector>

class CharacterSelector : public ICharacterSelector {
public:
    std::unique_ptr<ICharacter> select(const std::string& label) override;

private:
    std::vector<Character>      presets()     const;
    std::unique_ptr<ICharacter> pickPreset();
    std::unique_ptr<ICharacter> buildCustom();
};

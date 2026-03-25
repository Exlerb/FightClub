#pragma once
#include <string>

class IStats {
public:
    virtual ~IStats() = default;

    virtual void recordResult(const std::string& winner, const std::string& loser) = 0;
    virtual void showStats() const = 0;
};

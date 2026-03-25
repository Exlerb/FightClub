#pragma once
#include "IStats.h"
#include <map>
#include <utility>

class Stats : public IStats {
public:
    void recordResult(const std::string& winner, const std::string& loser) override;
    void showStats() const override;

private:
    std::map<std::string, std::pair<int, int>> records_; // name → {wins, losses}
};

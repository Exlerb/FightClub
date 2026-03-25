#include "Stats.h"
#include <iostream>
#include <cstdio>

void Stats::recordResult(const std::string& winner, const std::string& loser) {
    records_[winner].first++;
    records_[loser].second++;
}

void Stats::showStats() const {
    if (records_.empty()) {
        std::cout << "\nNo battles fought yet.\n";
        return;
    }
    std::cout << "\n=== BATTLE STATISTICS ===\n";
    std::cout << "Name             Wins   Losses\n";
    std::cout << "--------------------------------\n";
    for (const auto& [name, record] : records_) {
        printf("%-16s %-6d %d\n", name.c_str(), record.first, record.second);
    }
}

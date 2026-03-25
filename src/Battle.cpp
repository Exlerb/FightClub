#include "Battle.h"
#include "Utils.h"
#include <iostream>

void Battle::run(ICharacter& c1, ICharacter& c2, IStats& stats) {
    c1.resetHP();
    c2.resetHP();

    std::cout << "\n╔══════════════════════════════╗\n";
    std::cout << "  BATTLE: " << c1.getName() << " vs " << c2.getName() << "\n";
    std::cout << "╚══════════════════════════════╝\n";

    ICharacter* current  = &c1;
    ICharacter* opponent = &c2;
    int round = 1;

    while (c1.isAlive() && c2.isAlive()) {
        std::cout << "\n--- Round " << round++ << " ---\n";
        std::cout << c1.getName() << ": " << c1.getHP() << "/" << c1.getMaxHP() << " HP   |   "
                  << c2.getName() << ": " << c2.getHP() << "/" << c2.getMaxHP() << " HP\n";

        std::cout << "\n" << current->getName() << "'s turn:\n";
        std::cout << "  1. " << current->getAbility1().name
                  << "  (" << current->getAbility1().description << ")\n";
        std::cout << "  2. " << current->getAbility2().name
                  << "  (" << current->getAbility2().description << ")\n";
        std::cout << "  Choice: ";
        int choice = readInt(1, 2);

        current->useAbility(choice, *opponent);
        std::swap(current, opponent);
    }

    ICharacter* winner = c1.isAlive() ? &c1 : &c2;
    ICharacter* loser  = c1.isAlive() ? &c2 : &c1;

    std::cout << "\n★  " << winner->getName() << " wins the battle!  ★\n";
    stats.recordResult(winner->getName(), loser->getName());
}

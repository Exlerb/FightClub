#include "Game.h"
#include "Stats.h"
#include "Battle.h"
#include "CharacterSelector.h"
#include "Utils.h"
#include <iostream>

Game::Game()
    : stats_   (std::make_unique<Stats>()),
      battle_  (std::make_unique<Battle>()),
      selector_(std::make_unique<CharacterSelector>()) {}

void Game::run() {
    std::cout << "╔═══════════════════╗\n";
    std::cout << "║    FIGHT CLUB     ║\n";
    std::cout << "╚═══════════════════╝\n";

    while (true) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Start a battle\n";
        std::cout << "2. View statistics\n";
        std::cout << "3. Quit\n";
        std::cout << "Choice: ";
        int choice = readInt(1, 3);

        if (choice == 1) {
            auto p1 = selector_->select("Player 1");
            auto p2 = selector_->select("Player 2");
            battle_->run(*p1, *p2, *stats_);
        } else if (choice == 2) {
            stats_->showStats();
        } else {
            std::cout << "Goodbye!\n";
            break;
        }
    }
}

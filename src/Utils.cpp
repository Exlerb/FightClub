#include "Utils.h"
#include <iostream>

int readInt(int lo, int hi) {
    int v;
    while (!(std::cin >> v) || v < lo || v > hi) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "  Please enter a number between " << lo << " and " << hi << ": ";
    }
    return v;
}

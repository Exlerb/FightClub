#pragma once

class IGame {
public:
    virtual ~IGame() = default;

    virtual void run() = 0;
};

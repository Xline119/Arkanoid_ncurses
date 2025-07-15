#pragma once
#include "ConsoleViewport.hpp"
#include "GameField.hpp"

class Game {
public:
    Game();
    ~Game() {};
    void run();
private:
    ConsoleViewport viewport_;
    GameField field_;
    bool running_;
};

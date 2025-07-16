#pragma once
#include "ConsoleViewport.hpp"
#include "GameField.hpp"
#include "SidePanel.hpp"

class Game {
public:
    Game();
    ~Game() {};
    void run();
private:
    ConsoleViewport viewport_;
    GameField field_;
    SidePanel panel_;
    bool running_;
};
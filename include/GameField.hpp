#pragma once

#include <vector>
#include <algorithm>
#include <ncurses.h>
#include "../include/ConsoleViewport.hpp"

class GameField {
public:
    GameField(const ConsoleViewport& viewport);
    ~GameField();
    void render();
    // Getters
    int height() const;
    int width() const;
    WINDOW* fieldWin() const; 
private:
    int height_;
    int width_;
    WINDOW* fieldWin_;
    std::vector<std::vector<chtype>> field_;
    void setFieldBorders();
};
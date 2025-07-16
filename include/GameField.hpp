#pragma once
#include <vector>
#include <algorithm>
#include <ncurses.h>
#include "../include/ConsoleViewport.hpp"

class GameField {
public:
    GameField(const ConsoleViewport& viewport, int height = 20, int width = 40);
    ~GameField();
    // Getters
    int height() const;
    int width() const;
    //const chtype* rowData(int y) const;
    void render();
private:
    int height_;
    int width_;
    WINDOW* fieldWin_;
    std::vector<std::vector<chtype>> field_;
    void setFieldBorders();
};
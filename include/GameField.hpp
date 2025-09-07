#pragma once

#include <vector>
#include <ncurses.h>

class ConsoleViewport;

class GameField {
public:
    GameField(const ConsoleViewport& viewport);
    ~GameField();
    void render();
    // Getters
    int height() const;
    int width() const;
    WINDOW* fieldWin() const;
    chtype cell(int y, int x) const;
private:
    int height_;
    int width_;
    WINDOW* fieldWin_;
    std::vector<std::vector<chtype>> field_;
    const std::vector<chtype> clearLine;
    bool hasBorders;
    void setFieldBorders();   
};

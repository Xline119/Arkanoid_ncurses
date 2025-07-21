#pragma once

#include <vector>
#include <ncurses.h>
#include "GameField.hpp"

class Platform {
public:
    Platform(const GameField& field);
    ~Platform() {};
    void render(const GameField& field) const;
private:
    enum direction {STOP, LEFT, RIGHT};
    int width_;
    int posX_;
    std::vector<chtype> platform_;
    direction dir_;
};
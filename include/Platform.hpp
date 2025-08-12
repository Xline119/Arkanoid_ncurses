#pragma once

#include <vector>
#include <ncurses.h>
#include "GameField.hpp"

class Platform {
public:
    Platform(const GameField& field);
    void render(const GameField& field) const;
    void move(const GameField& field, int dir);
    // Getters
    int posX() const;
    int posY() const;
    int width() const;
private:
    enum direction {STOP, LEFT, RIGHT};
    int width_;
    int posY_;
    int posX_;
    std::vector<chtype> platform_;
    direction dir_;
};
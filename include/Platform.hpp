#pragma once

#include <vector>
#include <ncurses.h>

class GameField;

class Platform {
public:
    enum class Direction {stop, left, right};
    Platform(const GameField& field);
    void render(const GameField& field) const;
    void move(const GameField& field, int dir);
    // Getters
    int posX() const;
    int posY() const;
    int width() const;
    Direction movement() const { return movement_; }
private:
    int width_;
    int posY_;
    int posX_;
    std::vector<chtype> platform_;
    Direction movement_;
};

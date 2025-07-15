#pragma once
#include <vector>
#include <algorithm>
#include <ncurses.h>

class GameField {
public:
    GameField(int height = 20, int width = 40);
    ~GameField() {};
    // Getters
    int height() const;
    int width() const;
    const chtype* rowData(int y) const;
private:
    int height_;
    int width_;
    std::vector<std::vector<chtype>> field_;
    void setFieldBorders();
};
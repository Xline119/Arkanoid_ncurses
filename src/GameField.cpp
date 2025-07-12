#include <iostream>
#include <iterator>
#include "../include/GameField.hpp"

using idx = std::size_t;

void GameField::setFieldBorders() {
    // Init sides of field
    static constexpr idx L = 0, T = 0;
    const idx R = width_ - 1;
    const idx B = height_ - 1;

    // Corners
    gameField[T][L] = ACS_ULCORNER;
    gameField[T][R] = ACS_URCORNER;
    gameField[B][L] = ACS_LLCORNER;
    gameField[B][R] = ACS_LRCORNER;

    // Top
    std::fill_n(&gameField[T][1], width_ - 2, ACS_HLINE);
    // Bottom
    std::fill_n(&gameField[B][1], width_ - 2, ACS_HLINE);
    // Walls
    for (idx y = 1; y < B; ++y) {
        gameField[y][L] = ACS_VLINE;
        gameField[y][R] = ACS_VLINE;
    }
}

GameField::GameField(int height, int width) : height_(width / 4), width_(height * 1.5), 
                                              gameField(height_, std::vector<chtype>(width_, ' '))
{
    setFieldBorders();
}

int GameField::height() const { return height_; }
int GameField::width() const { return width_; }

const chtype* GameField::rowData(int y) const {
    return gameField[y].data();
}
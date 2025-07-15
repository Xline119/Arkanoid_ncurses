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
    field_[T][L] = ACS_ULCORNER;
    field_[T][R] = ACS_URCORNER;
    field_[B][L] = ACS_LLCORNER;
    field_[B][R] = ACS_LRCORNER;
    // Top
    std::fill_n(&field_[T][1], width_ - 2, ACS_HLINE);
    // Bottom
    std::fill_n(&field_[B][1], width_ - 2, ACS_HLINE);
    // Walls
    for (idx y = 1; y < B; ++y) {
        field_[y][L] = ACS_VLINE;
        field_[y][R] = ACS_VLINE;
    }
}

GameField::GameField(int height, int width) : height_(width / 4), width_(height * 1.5), 
                                              field_(height_, std::vector<chtype>(width_, ' '))
{
    setFieldBorders();
}

int GameField::height() const { return height_; }
int GameField::width() const { return width_; }

const chtype* GameField::rowData(int y) const {
    return field_[y].data();
}
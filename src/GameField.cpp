#include <stdexcept>
#include <algorithm>
#include "../include/ConsoleViewport.hpp"
#include "../include/GameField.hpp"

GameField::GameField(const ConsoleViewport& viewport) 
    : height_(viewport.height() - 2),
      width_(viewport.width() / 2.2),
      fieldWin_(newwin(height_, width_, 2, viewport.width() / 2)),
      field_(height_, std::vector<chtype>(width_, ' ')),
      clearLine(width_ - 2, ' '),
      hasBorders(false)
{
    noecho();
    cbreak();
    keypad(fieldWin_, true);
    setFieldBorders();
}

GameField::~GameField() {
    delwin(fieldWin_);
}

void GameField::render() {
    if (!hasBorders) {
        for (int y = 0; y < height_; ++y) {
            wmove(fieldWin_, y, 0);
            waddchnstr(fieldWin_, field_[y].data(), width_);
        }
        hasBorders = true;
    } else {
        for (int y = 1; y < height_ - 1; ++y) {
            wmove(fieldWin_, y, 1);
            waddchnstr(fieldWin_, clearLine.data(), width_ - 1);
        }
    }
    wrefresh(fieldWin_);
}

// Getters
int GameField::height() const { return height_; }

int GameField::width() const { return width_; }

WINDOW* GameField::fieldWin() const { return fieldWin_; }

chtype GameField::cell(int y, int x) const {
    if (y < 0 || y >= height_ || x < 0 || x >= width_)
        throw std::out_of_range("Cell coordinates out of bounds");
    else
        return field_[y][x];
}

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
    box(fieldWin_, 0, 0);
}
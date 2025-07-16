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
    box(fieldWin_, 0, 0);
}

GameField::GameField(const ConsoleViewport& viewport, int height, int width) : height_(width / 4), width_(height * 1.5),
    fieldWin_(newwin(height_, width_, 2, viewport.width() / 2)), field_(height_, std::vector<chtype>(width_, ' '))
{
    setFieldBorders();
}

GameField::~GameField() {
    delwin(fieldWin_);
}

void GameField::render() {
    for (int y = 0; y < height_; ++y) {
        wmove(stdscr, 0, 0);
        waddchnstr(stdscr, field_[y].data(), width_);
    }
    wrefresh(fieldWin_);
}

int GameField::height() const { return height_; }
int GameField::width() const { return width_; }

// const chtype* GameField::rowData(int y) const {
//     return field_[y].data();
// }
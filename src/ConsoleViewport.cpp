#include <ncurses.h>
#include <stdexcept>
#include "../include/ConsoleViewport.hpp"


ConsoleViewport::ConsoleViewport(int marginY, int marginX) : rows_(0), cols_(0), marginY_(marginY), marginX_(marginX) {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    detectWindowSize();
}

ConsoleViewport::~ConsoleViewport() {
    endwin();
}

void ConsoleViewport::detectWindowSize() {
    int rawRows, rawCols;
    getmaxyx(stdscr, rawRows, rawCols);
    if (rawRows < 1 || rawCols < 1) {
        throw std::runtime_error("ConsoleViewport: invalid window size");
    }
    rows_ = rawRows - 2 * marginY_;
    cols_ = rawCols - 2 * marginX_;
}

void ConsoleViewport::render(const GameField& field) {
    clear();
    int h = field.height();
    int w = field.width();
    box(stdscr, 0, 0);
    for (int y = 0; y < h; ++y) {
        wmove(stdscr, y + 2, w + 6);
        waddchnstr(stdscr, field.rowData(y), w);
    }
    refresh();
 }

int ConsoleViewport::height() const { return rows_; }
int ConsoleViewport::width() const { return cols_; }
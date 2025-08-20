#include <ncurses.h>
#include <stdexcept>
#include "../include/ConsoleViewport.hpp"

ConsoleViewport::ConsoleViewport(int marginY, int marginX)
     : rows_(0),
       cols_(0),
       marginY_(marginY),
       marginX_(marginX)
{
    initscr();
    //curs_set(0);
    //noecho();
    //cbreak();
    //keypad(stdscr, true);
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

void ConsoleViewport::initialize() const {
    clear();
    box(stdscr, 0, 0);
    refresh();
 }

int ConsoleViewport::height() const { return rows_; }
int ConsoleViewport::width() const { return cols_; }

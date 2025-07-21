#include "../include/Platform.hpp"

Platform::Platform(const GameField& field)
    : width_(field.width() / 4),
      posX_((field.width() / 2) - width_ / 2),
      platform_(width_, ACS_HLINE),
      dir_(STOP)
{}



void Platform::render(const GameField& field) const {
    mvwhline(field.fieldWin(), field.height() - 3, posX_, ACS_HLINE, width_);
}
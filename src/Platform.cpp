#include "../include/Platform.hpp"

Platform::Platform(const GameField& field)
    : width_(field.width() / 4),
      posY_(field.height() - 3),
      posX_((field.width() / 2) - width_ / 2),
      platform_(width_, ACS_HLINE),
      movement_(Direction::stop)
{}

void Platform::move(const GameField& field, int dir) {
    switch (dir) {
        case KEY_LEFT:
            movement_ = Direction::left;
            if (posX_ > 2) posX_-= 2;
            else if (posX_ > 1) posX_ -= 1;
            break;
        case KEY_RIGHT:
            movement_ = Direction::right;
            if (posX_ + width_ < field.width() - 2) posX_ += 2;
            else if (posX_ + width_ < field.width() - 1) posX_ += 1;
            break;
        default:
            movement_ = Direction::stop;
            break;
    }
}

void Platform::render(const GameField& field) const {
    //Rendering platform
    mvwhline(field.fieldWin(), posY_, posX_, ACS_HLINE, width_);

    //Сlearing platform's traces
    if (movement_ == Direction::right)
        mvwhline(field.fieldWin(), posY_, posX_ - 2, ' ', 2);
    else if (movement_ == Direction::left)
        mvwhline(field.fieldWin(), posY_, posX_ + width_, ' ', 2);
}

int Platform::posX() const { return posX_; }
int Platform::posY() const { return posY_; }
int Platform::width() const { return width_; }

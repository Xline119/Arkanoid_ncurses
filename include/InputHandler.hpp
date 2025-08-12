#pragma once

#include <ncurses.h>

class InputHandler {
public:
    explicit InputHandler(WINDOW* window);
    int getInput() const;
    void setNonBlocking(bool enabled);
private:
    WINDOW* window_;
};
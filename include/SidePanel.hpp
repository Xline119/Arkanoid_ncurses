#pragma once

#include <ncurses.h>
#include "../include/ConsoleViewport.hpp"

class SidePanel {
public:
    SidePanel(const ConsoleViewport& viewport);
    ~SidePanel();
    void render();
private:
    int height_;
    int width_;
    WINDOW* sidePanelWin_;
    int score_;
    int level_;
};

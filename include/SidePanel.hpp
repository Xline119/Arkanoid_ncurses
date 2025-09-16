#pragma once

#include <ncurses.h>

class ConsoleViewport;

class SidePanel {
public:
    SidePanel(const ConsoleViewport& viewport);
    ~SidePanel();
    void render();

    // Getters
    int score() const;
    int level() const;
private:
    int height_;
    int width_;
    WINDOW* sidePanelWin_;
    int score_;
    int level_;
};

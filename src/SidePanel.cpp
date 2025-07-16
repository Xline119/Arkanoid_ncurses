
#include "../include/SidePanel.hpp"

SidePanel::SidePanel(const ConsoleViewport& viewport) : height_(viewport.height() / 3), 
                                                        width_(viewport.width() / 3), 
                                                        sidePanelWin_(newwin(height_, width_, viewport.height() / 3, (viewport.width() / 2) / 3)),
                                                        score_(0), level_(0)
{
    box(sidePanelWin_, 0, 0);
}

SidePanel::~SidePanel() {
    delwin(sidePanelWin_);
}

void SidePanel::render() {

    mvwprintw(sidePanelWin_, 1, 1, "Score: %d", score_);
    mvwprintw(sidePanelWin_, 2, 1, "Level: %d", level_);
    wrefresh(sidePanelWin_);
}
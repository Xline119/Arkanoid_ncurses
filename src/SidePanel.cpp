#include "../include/SidePanel.hpp"
#include "../include/ConsoleViewport.hpp"

SidePanel::SidePanel(const ConsoleViewport& viewport) 
    : height_(viewport.height() / 3), 
      width_(viewport.width() / 3),
      sidePanelWin_(newwin(height_, width_, (viewport.height() / 2) - (height_ / 2), (viewport.width() / 2) / 3)),
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

int SidePanel::score() const { return score_;}
int SidePanel::level() const { return level_;}

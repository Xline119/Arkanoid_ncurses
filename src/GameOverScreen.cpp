#include "../include/GameOverScreen.hpp"
#include "../include/ConsoleViewport.hpp"
#include "../include/SidePanel.hpp"

GameOverScreen::GameOverScreen(const ConsoleViewport &viewport, const SidePanel& statistic)
  : height_(viewport.height()),
    width_(viewport.width()),
    gameOverWin_(newwin(height_, width_, 1, 1)),
    statisticWin_(height_, width_, gameOverWin_, statistic),
    menuWin_(height_, width_, gameOverWin_)
{
  box(gameOverWin_, 0, 0);
}

GameOverScreen::~GameOverScreen() {
  delwin(gameOverWin_);
}

void GameOverScreen::render() {
  mvwprintw(gameOverWin_, height_ * 0.2, width_ / 2 - 5, "Game Over");
  wrefresh(gameOverWin_);
  statisticWin_.render();
  menuWin_.render();
}

GameOverScreen::StatisticWindow::StatisticWindow(int height, int width, WINDOW* parent, const SidePanel& statistic)
  : height_(height / 2),
    width_(width / 2 - 2 /* <-- width indent */),
    score_(statistic.score()),
    level_(statistic.level()),
    win_(derwin(parent, height_, width_, height * 0.3, (width / 2) - width_))
{
  box(win_, 0, 0);
}

GameOverScreen::StatisticWindow::~StatisticWindow() {
  delwin(win_);
}

void GameOverScreen::StatisticWindow::render() {
  mvwprintw(win_, 1, width_ / 2 - 5, "Statistic:");
  mvwprintw(win_, 2, 1, "Score: %d", score_);
  mvwprintw(win_, 3, 1, "Level: %d", level_);
  wrefresh(win_);
}

//int GameOverScreen::StatisticWindow::width() const { return width_; }

GameOverScreen::MenuWindow::MenuWindow(int height, int width, WINDOW* parent)
  : height_(height / 2),
    width_(width / 2 - 2 /* <-- width indent */),
    win_(derwin(parent, height_, width_, height * 0.3, width / 2))
{
  box(win_, 0, 0);
}

GameOverScreen::MenuWindow::~MenuWindow() {
  delwin(win_);
}

void GameOverScreen::MenuWindow::render() {
  mvwprintw(win_, 1, width_ / 2 - 5, "Main menu");
  //vwprintw(win_, 2, 1, "Score:");
  // mvwprintw(win_, 3, 1, "Level: %d", level_);
  wrefresh(win_);
}
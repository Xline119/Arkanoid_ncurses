#include "Game.hpp"

Game::Game() 
    : viewport_(),
      panel_(viewport_),
      field_(viewport_),
      platform_(field_),
      running_(true)
{}

void Game::handleInput() {
    int input = wgetch(field_.fieldWin());
    platform_.move(field_, input);
}

void Game::run() {
    viewport_.render();
    nodelay(field_.fieldWin(), TRUE);
    while (running_) {
        panel_.render();
        field_.render();
        handleInput();
        platform_.render(field_);
    }
}
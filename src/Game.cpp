#include "Game.hpp"

Game::Game() 
    : viewport_(),
      panel_(viewport_),
      field_(viewport_),
      platform_(field_),
      running_(true)
{}

void Game::run() {
    viewport_.render();
    while (running_) {
        panel_.render();
        field_.render();
        platform_.render(field_);
    }
}
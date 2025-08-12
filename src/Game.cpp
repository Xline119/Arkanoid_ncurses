#include "Game.hpp"

Game::Game() 
    : viewport_(),
      sidePanel_(viewport_),
      field_(viewport_),
      platform_(field_),
      inputHandler_(field_.fieldWin()),
      running_(true)
{}

void Game::input() {
    lastInput_ = inputHandler_.getInput();
}

void Game::run() {
    viewport_.initialize();
    inputHandler_.setNonBlocking(true);
    while (running_) {
        input();
        update();
        render();
    }
}

void Game::update() {
    platform_.move(field_, lastInput_);
}

void Game::render() {
    sidePanel_.render();
    field_.render();
    platform_.render(field_);
}
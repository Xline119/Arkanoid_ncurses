#include <iostream>
#include "Game.hpp"

Game::Game()
    : viewport_(),
      sidePanel_(viewport_),
      field_(viewport_),
      platform_(field_),
      ball_(platform_),
      inputHandler_(field_.fieldWin()),
      gameOverScreen_(viewport_, sidePanel_),
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
    gameOverScreen_.render();
    std::cin.get();
}

void Game::update() {
    platform_.move(field_, lastInput_);
    ball_.setDirection(field_, platform_);
    ball_.move();
    if (ball_.isBallLost())
        running_ = false;
}

void Game::render() {
    sidePanel_.render();
    field_.render();
    platform_.render(field_);
    ball_.render(field_);
}

#include "Game.hpp"

Game::Game() : viewport_(), field_(viewport_.height(), viewport_.width()), running_(true) {}

void Game::run() {
    while (running_) {
        viewport_.render(field_);
    }
}
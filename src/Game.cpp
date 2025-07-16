#include "Game.hpp"

Game::Game() : viewport_(), field_(viewport_, viewport_.height(), viewport_.width()), panel_(viewport_), running_(true) {}

void Game::run() {
    viewport_.render();
    while (running_) {
        panel_.render();
        field_.render();
    }
}
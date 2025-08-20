#include <iostream>
#include "Game.hpp"

int main() {
    //std::cout << "Arkanoid!" << std::endl;
    try {
        Game game;
        game.run();
        std::cin.get();
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}

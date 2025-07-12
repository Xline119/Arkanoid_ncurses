#include <iostream>
#include "../include/ConsoleViewport.hpp"
#include "../include/GameField.hpp"

int main() {
    //std::cout << "Arkanoid!" << std::endl;
    try {
        ConsoleViewport viewport(1, 1);
        viewport.detectWindowSize();
        GameField field(viewport.height(), viewport.width());
        viewport.render(field);
        std::cin.get();
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
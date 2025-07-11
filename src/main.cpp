#include "../include/GameField.hpp"

int main() {
    std::cout << "Arkanoid!" << std::endl;
    GameField field;
    field.renderField();
    std::cin.get();
    return 0;
}
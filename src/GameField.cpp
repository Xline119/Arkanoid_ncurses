#include "../include/GameField.hpp"

GameField::GameField(int height, int width) : fieldHeight(height), fieldWidth(width), 
                                              gameField(height, std::vector<char>(width, ' '))
{
    setFieldBorders();
}

void GameField::renderField() {
    for (const auto& row : gameField) {
        std::copy(row.begin(), row.end(), std::ostream_iterator<char>(std::cout));
        std::cout << '\n';
    }
}
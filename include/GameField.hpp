#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

class GameField {
public:
    GameField(int height = 20, int width = 40);
    void renderField();
private:
    int fieldHeight;
    int fieldWidth;
    std::vector<std::vector<char>> gameField;
    void setFieldBorders() {
        std::fill(gameField[0].begin(), gameField[0].end(), '#');
        std::fill(gameField[fieldHeight - 1].begin(), gameField[fieldHeight - 1].end(), '#');
        for (int y = 1; y < fieldHeight - 1; ++y) {
            gameField[y][0] = '#';
            gameField[y][fieldWidth - 1] = '#';
        }
    }
};
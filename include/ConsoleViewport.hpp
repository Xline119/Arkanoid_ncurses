#pragma once
#include "GameField.hpp"

class ConsoleViewport {
public:
    ConsoleViewport(int marginY, int marginX);
    ~ConsoleViewport();
    void detectWindowSize();
    void render(const GameField& field);
    // Getters
    int height() const;
    int width() const;
private:
    int rows_, cols_;
    int marginY_, marginX_;
};
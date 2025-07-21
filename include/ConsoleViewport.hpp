#pragma once

class ConsoleViewport {
public:
    ConsoleViewport(int marginY = 1, int marginX = 1);
    ~ConsoleViewport();
    void render() const;
    // Getters
    int height() const;
    int width() const;
private:
    int rows_, cols_;
    int marginY_, marginX_;
    void detectWindowSize();
};
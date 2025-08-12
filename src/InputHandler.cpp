#include "../include/InputHandler.hpp"

InputHandler::InputHandler(WINDOW* window) 
    : window_(window)
{}

int InputHandler::getInput() const {
    return wgetch(window_);
}

void InputHandler::setNonBlocking(bool enabled) {
    nodelay(window_, enabled ? TRUE : FALSE);
}
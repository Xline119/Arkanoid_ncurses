cmake_minimum_required(VERSION 3.10)
project(Arkanoid LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(arkanoid
    src/main.cpp
    src/GameField.cpp
)
cmake_minimum_required(VERSION 4.0)
project(BoopLocal)

set(CMAKE_CXX_STANDARD 20)

add_executable(BoopLocal main.cpp
        Board.cpp
        Board.h
        Player.h
        Piece.h
        Point.h
        PieceView.cpp
        PieceView.h
        DisplayConfig.h
        DisplayConfig.h
        BoardView.cpp
        BoardView.h
        GameController.cpp
        GameController.h
        PlayerView.cpp
        PlayerView.h
        DisplayConfig.cpp)

target_link_libraries(BoopLocal PRIVATE raylib)
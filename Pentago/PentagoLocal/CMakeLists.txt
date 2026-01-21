cmake_minimum_required(VERSION 4.0)
project(PentagoLocal)

set(CMAKE_CXX_STANDARD 20)

add_executable(PentagoLocal main.cpp
        Cell.cpp
        Cell.h
        SubGrid.cpp
        SubGrid.h
        Board.cpp
        Board.h
        GameController.cpp
        GameController.h
        Turn.h
        Turn.cpp
        DisplayConfig.h
        CellView.cpp
        CellView.h
        SubGridView.cpp
        SubGridView.h
        BoardView.cpp
        BoardView.h
        HoverStatus.h
        Point.h
)

target_link_libraries(PentagoLocal PRIVATE raylib)
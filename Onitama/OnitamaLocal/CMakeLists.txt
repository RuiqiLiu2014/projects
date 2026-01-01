cmake_minimum_required(VERSION 4.0)
project(OnitamaLocal)

set(CMAKE_CXX_STANDARD 20)

add_executable(OnitamaLocal main.cpp
        Board.cpp
        Board.h
        Cell.cpp
        Cell.h
        MoveCard.cpp
        MoveCard.h
        GameController.cpp
        GameController.h
        Player.cpp
        Player.h
        Point.h
        BoardView.cpp
        BoardView.h
        CardView.cpp
        CardView.h
        CellView.cpp
        CellView.h
        DisplayConfig.h
        GameView.cpp
        GameView.h
        PlayerView.cpp
        PlayerView.h
        MiddleCardView.cpp
        MiddleCardView.h
        MiddleCard.cpp
        MiddleCard.h
        ScoreView.cpp
        ScoreView.h
        TurnIndicatorView.cpp
        TurnIndicatorView.h
)

target_link_libraries(OnitamaLocal PRIVATE raylib)
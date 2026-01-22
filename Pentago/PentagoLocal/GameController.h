//
// Created by whale on 1/15/26.
//

#ifndef PENTAGOLOCAL_GAMECONTROLLER_H
#define PENTAGOLOCAL_GAMECONTROLLER_H
#include <memory>

#include "Board.h"
#include "BoardView.h"

enum class AppState {
    CHOOSE_PLAYERS,
    PLAYING,
    GAME_OVER
};

class GameController {
    std::unique_ptr<Board> board;
    std::unique_ptr<Turn> turn;
    AppState state;
    std::unique_ptr<BoardView> boardView;

    void drawPlayerSelect();
    static void drawWinScreen(CellStatus winner);
    void drawMouse() const;
    void createGame(int players);
    void reset() const;

public:
    GameController();
    void update();
    void display();
    void handleClick() const;
};


#endif //PENTAGOLOCAL_GAMECONTROLLER_H